// Copyright (c) 2014-2023 The Gridcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or https://opensource.org/licenses/mit-license.php.

#include <qt/sidestaketablemodel.h>
#include <qt/optionsmodel.h>
#include <node/ui_interface.h>

#include <QList>
#include <QTimer>
#include <QDebug>

namespace {

static void RwSettingsUpdated(SideStakeTableModel* sidestake_model)
{
    qDebug() << QString("%1").arg(__func__);
    QMetaObject::invokeMethod(sidestake_model, "updateSideStakeTableModel", Qt::QueuedConnection);
}

} // anonymous namespace

SideStakeLessThan::SideStakeLessThan(int column, Qt::SortOrder order)
    : m_column(column)
      , m_order(order)
{}

bool SideStakeLessThan::operator()(const GRC::SideStake& left, const GRC::SideStake& right) const
{
    const GRC::SideStake* pLeft = &left;
    const GRC::SideStake* pRight = &right;

    if (m_order == Qt::DescendingOrder) {
        std::swap(pLeft, pRight);
    }

    switch (static_cast<SideStakeTableModel::ColumnIndex>(m_column)) {
    case SideStakeTableModel::Address:
        return pLeft->m_key < pRight->m_key;
    case SideStakeTableModel::Allocation:
        return pLeft->m_allocation < pRight->m_allocation;
    case SideStakeTableModel::Description:
        return pLeft->m_description.compare(pRight->m_description) < 0;
    case SideStakeTableModel::Status:
        return pLeft->m_status < pRight->m_status;
    } // no default case, so the compiler can warn about missing cases
    assert(false);
}

class SideStakeTablePriv
{
public:
    QList<GRC::SideStake> m_cached_sidestakes;
    int m_sort_column{-1};
    Qt::SortOrder m_sort_order;

    void refreshSideStakes()
    {
        m_cached_sidestakes.clear();

        std::vector<GRC::SideStake_ptr> core_sidestakes = GRC::GetSideStakeRegistry().ActiveSideStakeEntries(false, true);

        m_cached_sidestakes.reserve(core_sidestakes.size());

        for (const auto& entry : core_sidestakes) {
            m_cached_sidestakes.append(*entry);
        }

        if (m_sort_column >= 0) {
            std::stable_sort(m_cached_sidestakes.begin(), m_cached_sidestakes.end(), SideStakeLessThan(m_sort_column, m_sort_order));
        }
    }

    int size()
    {
        return m_cached_sidestakes.size();
    }

    GRC::SideStake* index(int idx)
    {
        if (idx >= 0 && idx < m_cached_sidestakes.size()) {
            return &m_cached_sidestakes[idx];
        }

        return nullptr;
    }

};

SideStakeTableModel::SideStakeTableModel(OptionsModel* parent)
    : QAbstractTableModel(parent)
{
    m_columns << tr("Address") << tr("Allocation") << tr("Description") << tr("Status");
    m_priv.reset(new SideStakeTablePriv());

    subscribeToCoreSignals();

    // load initial data
    refresh();
}

SideStakeTableModel::~SideStakeTableModel()
{
  // Intentionally left empty
}

int SideStakeTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_priv->size();
}

int SideStakeTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_columns.length();
}

QVariant SideStakeTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    GRC::SideStake* rec = static_cast<GRC::SideStake*>(index.internalPointer());

    const auto column = static_cast<ColumnIndex>(index.column());
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (column) {
        case Address:
            return QString::fromStdString(rec->m_key.ToString());
        case Allocation:
            return rec->m_allocation * 100.0;
        case Description:
            return QString::fromStdString(rec->m_description);
        case Status:
            return QString::fromStdString(rec->StatusToString());
        } // no default case, so the compiler can warn about missing cases
        assert(false);
    } else if (role == Qt::TextAlignmentRole) {
        switch (column) {
        case Address:
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        case Allocation:
            return QVariant(Qt::AlignRight | Qt::AlignVCenter);
        case Description:
            return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
        case Status:
            return QVariant(Qt::AlignCenter | Qt::AlignVCenter);
        default:
            return QVariant();
        }
    }

    return QVariant();
}

bool SideStakeTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) {
        return false;
    }

    GRC::SideStakeRegistry& registry = GRC::GetSideStakeRegistry();

    GRC::SideStake* rec = static_cast<GRC::SideStake*>(index.internalPointer());

    if (role != Qt::EditRole) {
        return false;
    }

    m_edit_status = OK;

    switch (index.column())
    {
    case Address:
    {
        CBitcoinAddress address;
        address.SetString(value.toString().toStdString());


        if (rec->m_key == address) {
            m_edit_status = NO_CHANGES;
            return false;
        } else if (!address.IsValid()) {
            m_edit_status = INVALID_ADDRESS;
            return false;
        }

        std::vector<GRC::SideStake_ptr> sidestakes = registry.Try(address, true);

        if (!sidestakes.empty()) {
            m_edit_status = DUPLICATE_ADDRESS;
            return false;
        }

        // There is no valid state change left for address. If you are editing the item, the address field is
        // not editable, so will be NO_CHANGES. For a non-matching address, it will be covered by the dialog
        // in New mode.
        break;
    }
    case Allocation:
    {
        double prior_total_allocation = 0.0;

        // Save the original local sidestake (also in the core).
        GRC::SideStake orig_sidestake = *rec;

        for (const auto& entry : registry.ActiveSideStakeEntries(false, true)) {
            if (entry->m_key == orig_sidestake.m_key) {
                continue;
            }

            prior_total_allocation += entry->m_allocation * 100.0;
        }

        if (rec->m_allocation * 100.0 == value.toDouble()) {
            m_edit_status = NO_CHANGES;
            return false;
        }

        if (value.toDouble() < 0.0 || prior_total_allocation + value.toDouble() > 100.0) {
            m_edit_status = INVALID_ALLOCATION;

            LogPrint(BCLog::LogFlags::VERBOSE, "INFO: %s: m_edit_status = %i",
                     __func__,
                     (int) m_edit_status);

            return false;
        }

        // Delete the original sidestake
        registry.NonContractDelete(orig_sidestake.m_key, false);

        // Add back the sidestake with the modified allocation
        registry.NonContractAdd(GRC::SideStake(orig_sidestake.m_key,
                                               value.toDouble() / 100.0,
                                               orig_sidestake.m_description,
                                               int64_t {0},
                                               uint256 {},
                                               orig_sidestake.m_status.Value()), true);

        break;
    }
    case Description:
    {
        std::string orig_value = value.toString().toStdString();
        std::string san_value = SanitizeString(orig_value, SAFE_CHARS_CSV);

        if (rec->m_description == orig_value) {
            m_edit_status = NO_CHANGES;
            return false;
        }

        if (san_value != orig_value) {
            m_edit_status = INVALID_DESCRIPTION;
            return false;
        }

        // Save the original local sidestake (also in the core).
        GRC::SideStake orig_sidestake = *rec;

        // Delete the original sidestake
        registry.NonContractDelete(orig_sidestake.m_key, false);

        // Add back the sidestake with the modified allocation
        registry.NonContractAdd(GRC::SideStake(orig_sidestake.m_key,
                                               orig_sidestake.m_allocation,
                                               san_value,
                                               int64_t {0},
                                               uint256 {},
                                               orig_sidestake.m_status.Value()), true);

        break;
    }
    case Status:
        // Status is not editable
        return false;
    }

    updateSideStakeTableModel();

    return true;
}

QVariant SideStakeTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal)
    {
        if(role == Qt::DisplayRole && section < m_columns.size())
        {
            return m_columns[section];
        }
    }
    return QVariant();
}

Qt::ItemFlags SideStakeTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }

    GRC::SideStake* rec = static_cast<GRC::SideStake*>(index.internalPointer());

    Qt::ItemFlags retval = Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    if (rec->m_status == GRC::SideStakeStatus::ACTIVE
        && (index.column() == Allocation || index.column() == Description)) {
        retval |= Qt::ItemIsEditable;
    }

    return retval;
}

QModelIndex SideStakeTableModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    GRC::SideStake* data = m_priv->index(row);

    if (data)
        return createIndex(row, column, data);
    return QModelIndex();
}

QString SideStakeTableModel::addRow(const QString &address, const QString &allocation, const QString description)
{
    GRC::SideStakeRegistry& registry = GRC::GetSideStakeRegistry();

    CBitcoinAddress sidestake_address;
    sidestake_address.SetString(address.toStdString());

    double sidestake_allocation = 0.0;

    m_edit_status = OK;

    if (!sidestake_address.IsValid()) {
        m_edit_status = INVALID_ADDRESS;
        return QString();
    }

    // Check for duplicate local sidestakes. Here we use the actual core sidestake registry rather than the
    // UI model.
    std::vector<GRC::SideStake_ptr> core_local_sidestake = registry.Try(sidestake_address, true);

    double prior_total_allocation = 0.0;

    // Get total allocation of all active/mandatory sidestake entries
    for (const auto& entry : registry.ActiveSideStakeEntries(false, true)) {
        prior_total_allocation += entry->m_allocation * 100.0;
    }

    if (!core_local_sidestake.empty()) {
        m_edit_status = DUPLICATE_ADDRESS;
        return QString();
    }

    // The new allocation must be parseable as a double, must be greater than or equal to 0, and
    // must result in a total allocation of less than 100.
    if (!ParseDouble(allocation.toStdString(), &sidestake_allocation)
        || sidestake_allocation < 0.0 || prior_total_allocation + sidestake_allocation > 100.0) {
        m_edit_status = INVALID_ALLOCATION;
        return QString();
    }

    sidestake_allocation /= 100.0;

    std::string sidestake_description = description.toStdString();
    std::string sanitized_description = SanitizeString(sidestake_description, SAFE_CHARS_CSV);

    if (sanitized_description != sidestake_description) {
        m_edit_status = INVALID_DESCRIPTION;
        return QString();
    }

    registry.NonContractAdd(GRC::SideStake(sidestake_address,
                                           sidestake_allocation,
                                           sanitized_description,
                                           int64_t {0},
                                           uint256 {},
                                           GRC::SideStakeStatus::ACTIVE));

    updateSideStakeTableModel();

    return QString::fromStdString(sidestake_address.ToString());
}

bool SideStakeTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    GRC::SideStake* rec = m_priv->index(row);

    if(count != 1 || !rec || rec->m_status == GRC::SideStakeStatus::MANDATORY)
    {
        // Can only remove one row at a time, and cannot remove rows not in model.
        // Also refuse to remove mandatory sidestakes.
        return false;
    }

    GRC::GetSideStakeRegistry().NonContractDelete(rec->m_key);

    updateSideStakeTableModel();

    return true;
}

SideStakeTableModel::EditStatus SideStakeTableModel::getEditStatus() const
{
    return m_edit_status;
}

void SideStakeTableModel::refresh()
{
    Q_EMIT layoutAboutToBeChanged();
    m_priv->refreshSideStakes();

    m_edit_status = OK;

    Q_EMIT layoutChanged();
}

void SideStakeTableModel::sort(int column, Qt::SortOrder order)
{
    m_priv->m_sort_column = column;
    m_priv->m_sort_order = order;
    refresh();
}

void SideStakeTableModel::updateSideStakeTableModel()
{
    refresh();

    emit updateSideStakeTableModelSig();
}

void SideStakeTableModel::subscribeToCoreSignals()
{
    // Connect signals to client
    uiInterface.RwSettingsUpdated_connect(boost::bind(RwSettingsUpdated, this));
}

void SideStakeTableModel::unsubscribeFromCoreSignals()
{
    // Disconnect signals from client (currently no-op).
}
