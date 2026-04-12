#ifndef GRIDCOIN_QT_NATIVEDIALOGHELPER_H
#define GRIDCOIN_QT_NATIVEDIALOGHELPER_H

#include <QObject>

//! A lightweight QML-callable helper that shows native QMessageBox dialogs.
//! This exists because the QML native dialogs don't seem to work well at time and are either deprecated/not supported by 6.2
class NativeDialogHelper : public QObject
{
    Q_OBJECT

public:
    explicit NativeDialogHelper(QObject *parent = nullptr);

    //! Show a native information dialog with an OK button.
    Q_INVOKABLE void information(const QString &title, const QString &text);

    //! Show a native warning dialog with an OK button.
    Q_INVOKABLE void warning(const QString &title, const QString &text);

    //! Show a native question dialog with OK and Cancel buttons.
    //! Returns true if the user clicked OK.
    Q_INVOKABLE bool question(const QString &title, const QString &text);
};

#endif // GRIDCOIN_QT_NATIVEDIALOGHELPER_H
