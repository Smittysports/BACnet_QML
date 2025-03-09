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
        }
    }



}
