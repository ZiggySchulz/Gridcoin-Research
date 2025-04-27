import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("MyApp - QML Shell")

    // placeholder 
    Rectangle { 
        anchors.fill: parent
        color: "lightgray" 
    }

}