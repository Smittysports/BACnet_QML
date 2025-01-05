import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.BACnet.models 1.0

Rectangle {
    id: rightBar
    visible: true
    width: 80
    height: parent.height

    BACnetInterface {
        id: bacnetInterface
    }

    ColumnLayout{
        id: columnLayout
        spacing: 10
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        property int buttonWidth: 60

        Rectangle {
            id: spacer
        }

        Button {
            text: "Send"
            onClicked: {
                bacnetInterface.send()
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

        Button {
            text: "It"
            onClicked: console.log("It")

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
