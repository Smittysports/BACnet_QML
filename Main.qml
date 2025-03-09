import QtQuick
import QtQuick.Controls

Window {
    id: root
    visible: true
    width: 1000
    height: 800

    Loader {
        id: mainContentLoader
        width: parent.width
        height: parent.height * 0.75
        anchors.top: parent.top
        anchors.left: parent.left
    }
    /*
    Rectangle {
        id: mainScreenId
        anchors.fill: parent
        anchors.margins: 0.25 * parent.height
    }
    */
    Log {
        id: log
        anchors.top: mainContentLoader.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    Component.onCompleted: {
        mainContentLoader.source = "MainScreenChooser.qml"
    }

    onClosing: {
        myBACnetInterface.shutdown()
    }
}
