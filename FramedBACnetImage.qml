import QtQuick

Rectangle {
    border.width: 0
    width: 100
    height: 100
    anchors.leftMargin: 100
    anchors.rightMargin: 100

    Image {
        source: Qt.resolvedUrl("img/BACnet.jpg")
        anchors.centerIn: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        sourceSize.width: parent.width - anchors.leftMargin * 2
        sourceSize.height: parent.height

    }
}

