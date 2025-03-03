import QtQuick
import QtQuick.Controls

Window {
    id: root
    visible: true
    width: 1000
    height: 800

    BACnetObjectTypes {
        id: objectTypes
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: log.top
    }

    CommandResponse {
        id: commandResponse
        anchors.top: parent.top
        anchors.left: objectTypes.right
        anchors.right: rightBar.left
        anchors.bottom: log.top
    }

    RightBar {
        id: rightBar
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: log.top
        visible: true
    }

    Log {
        id: log

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    onClosing: {
        myBACnetInterface.shutdown()
    }
}
