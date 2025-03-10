/** Manual.qml
  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: manualRectangle
    anchors.fill: parent

    BACnetObjectTypes {
        id: objectTypes
        anchors.top: parent.top
        anchors.left: parent.left
    }

    ColumnLayout{
        id: manualDataColumnLayout
        spacing: 10
        anchors.top: objectTypes.bottom
        anchors.left: parent.left
        anchors.topMargin: 5
        anchors.leftMargin: 10
        property int textFieldWidths: 100

        Rectangle {
            id: manualDataColumnSpacer
        }

        TextField {
            id: ipAddressTextField
            text: "0.0.0.0"
            width: manualDataColumnLayout.textFieldWidths
        }

        TextField {
            id: portTextField
            text: "47808"
            width: manualDataColumnLayout.textFieldWidths
        }
    }

    CommandResponse {
        id: commandResponse
        anchors.top: parent.top
        anchors.left: objectTypes.right
        anchors.right: manualRightBarRectangle.left
    }

    Rectangle {
        id: manualRightBarRectangle
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
            property int buttonWidth: 60

            Rectangle {
                id: spacer
            }

            BackButton {}

            Button {
                text: "Send"
                onClicked: {
                    myBACnetInterface.setDeviceIPAddress(ipAddressTextField.text)
                    myBACnetInterface.setDevicePort(parseInt(portTextField.text, 10))
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



}
