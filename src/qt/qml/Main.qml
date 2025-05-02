import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import MMPTheme 1.0

ApplicationWindow {
    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("MyApp - QML Shell")

    Connections {
        target: _messageBrige
        function onNewInitMessage(message) {
             console.log("QML received message:", message)
             abc.text = message
        }
    }

    // placeholder 
    Rectangle { 
        anchors.fill: parent
        color: "lightgray" 
    }

    Text {
        id: abc
        text: MMPTheme.isLightTheme
    }

    Button {
        text: "green"
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
