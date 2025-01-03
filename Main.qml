import QtQuick

Window {
    id: root
    visible: true
    width: 1000
    height: 600
    Text {
        text: "BACnet"
        anchors.centerIn: parent
        color: "white"
        z: 2
    }
    //FramedBACnetImage { id: framedBACnetImage; anchors.top: parent.top; }
    //BACnetObjectTypes { anchors.top: framedBACnetImage.bottom; anchors.bottom: parent.bottom }
    BACnetObjectTypes { anchors.fill: parent }
}
