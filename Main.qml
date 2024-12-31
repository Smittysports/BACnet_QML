import QtQuick

Window {
    id: root
    visible: true
    Text {
        text: "BACnet"
        anchors.centerIn: parent
        color: "white"
        z: 2
    }
    FramedBACnetImage { anchors.fill: parent }
}
