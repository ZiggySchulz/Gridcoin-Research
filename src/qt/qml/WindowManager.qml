// The root of the qml application. Manages showing what would be root level windows
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQml 2.15
import Qt.labs.platform 1.1 //Available in Qt 5/6
Item {
    //Acts as the parent item for windows. This is to prevent unwanted garbage collection
    id: root
    Component.onCompleted: showOnboardingWindow()
    SystemTrayIcon {
        visible: true
        icon.source: "qrc:/res/icons/logos/ic_logo_app_gradient_white.svg"
        menu: Menu {
            MenuItem {
                text: qsTr("Quit")
                onTriggered: Qt.quit()
            }
        }
    }
    MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem { text: qsTr("Backup Wallet/Config")}
            MenuItem {
                text: qsTr("Export")
                enabled: false
            }
            MenuItem { text: qsTr("Snapshot Download")}
            MenuItem {text: qsTr("Export")}
            MenuItem {
                id: aboutMenuItem
                role: MenuItem.AboutRole
                text: qsTr("About")
                enabled: true
                onTriggered: showAboutWindow()
            }
        }
        Menu {
            id: editMenu
            title: qsTr("&Edit")
        }
        Menu {
            id: viewMenu
            title: qsTr("&View")
        }
        Menu {
            id: helpMenu
            title: qsTr("&Help")
        }

    }

    function showSplashScreen() {
        var component = Qt.createComponent("SplashScreen.qml")
        var windowObj = component.createObject(root)
        windowObj.loaded.connect(showMainWindow)
        windowObj.show()
    }

   function showMainWindow() {
       var component = Qt.createComponent("MainWindow.qml")
       var windowObj = component.createObject(root, {opacity: 0})
       windowObj.show()
       windowObj.opacity = 1
   }

   function showOnboardingWindow() {
       var component = Qt.createComponent("OnboardingWindow.qml")
       var windowObj = component.createObject(root)
       windowObj.onboardingFinished.connect(showMainWindow)
       windowObj.show()
   }

   function showAboutWindow() {
       aboutMenuItem.enabled = false
       var component = Qt.createComponent("AboutWindow.qml")
       var windowObj = component.createObject(root)
       windowObj.onClosing.connect(function(){aboutMenuItem.enabled=true})
       windowObj.show()
   }
}
