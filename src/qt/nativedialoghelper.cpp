#include "nativedialoghelper.h"

#include <QMessageBox>

NativeDialogHelper::NativeDialogHelper(QObject *parent)
    : QObject(parent)
{
}

void NativeDialogHelper::information(const QString &title, const QString &text)
{
    QMessageBox::information(nullptr, title, text);
}

void NativeDialogHelper::warning(const QString &title, const QString &text)
{
    QMessageBox::warning(nullptr, title, text);
}

bool NativeDialogHelper::question(const QString &title, const QString &text)
{
    return QMessageBox::question(nullptr, title, text,
                                 QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok;
}
