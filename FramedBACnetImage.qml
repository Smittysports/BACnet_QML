import QtQuick

Rectangle {
    border.width: 2
    border.color: "black"
    Image {
        source: Qt.resolvedUrl("img/BACnet.jpg")
        anchors.centerIn: parent
        sourceSize.width: parent.width
        sourceSize.height: parent.height
    }
}

