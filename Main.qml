import QtQuick
import QtQuick.Controls

Window {
    id: root
    visible: true
    width: 1000
    height: 800

    /*
    Text {
        text: "BACnet"
        anchors.centerIn: parent
        color: "white"
        z: 2
    }
    */
    //FramedBACnetImage { id: framedBACnetImage; anchors.top: parent.top; }
    //BACnetObjectTypes { anchors.top: framedBACnetImage.bottom; anchors.bottom: parent.bottom }

    BACnetObjectTypes {
        id: objectTypes
        anchors.top: parent.top
        anchors.left: parent.left
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

}
