/** RightBar.qml
  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: rightBar
    visible: true
    width: 80
    height: parent.height

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
            text: "Send"
            onClicked: {
                myBACnetInterface.send()
            }
            background: Rectangle {
                implicitWidth: columnLayout.buttonWidth
                border.width: 2
                border.color: "black"
                radius: 4
                color: parent.down ? "lightgray" :
                        (parent.hovered ? "green" : "gray")
            }
        }
    }
}
