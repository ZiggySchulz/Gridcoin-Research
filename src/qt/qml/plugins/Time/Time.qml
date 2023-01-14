pragma Singleton

import QtQuick 2.15
import QtQml 2.15

QtObject {
    property date currentTime: new Date()
    property Timer timer: Timer {
        interval: 60 * 1000
        repeat: true
        running: true
        onTriggered: currentTime = new Date()
    }
}
