import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
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
            text: "Discover"
            onClicked: {
                mainContentLoader.source = "Discovery.qml"
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
            text: "Manual"
            onClicked: {
                mainContentLoader.source = "Manual.qml"
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
