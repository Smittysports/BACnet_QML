/** Discovery.qml
  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: discoveryRectangle
    anchors.fill: parent

    Rectangle {
        id: discoveryRightBarRectangle
        anchors.margins: 4
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 100
        border.color: "black"
        border.width: 4

        ColumnLayout{
            id: columnLayout
            spacing: 10
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: spacer
            }

            BackButton {}

            Button {
                id: discoverButton
                 anchors.margins: 2

                background: Rectangle {
                    implicitWidth: 40
                    implicitHeight: 40
                    border.color: "black"
                    border.width: 1
                    radius: 4
                    color: parent.down ? "lightgray" :
                            (parent.hovered ? "green" : "gray")

                    Image {
                        width: parent.width * 0.8
                        height: parent.height * 0.8
                        source: "img/discover.png"
                        fillMode: Image.Stretch
                        opacity: 0.5
                        anchors.centerIn: parent
                    }
                }

                onClicked: {
                    myBACnetInterface.whoIs()
                }
            }
        }
    }



}
