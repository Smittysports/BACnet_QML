/** NetworkConfiguration.qml
  */
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: networkConfigurationRectangle
    anchors.fill: parent
    property alias ipAddressField: ipAddressTextField

    NetworkList {
        id: networkList
        anchors.top: parent.top
        anchors.left: parent.left
    }

    Rectangle {
        id: networkConfigurationDataId
        anchors.margins: 4
        anchors.left: parent.left
        anchors.top: networkList.bottom
        anchors.bottom: parent.bottom
        width: 200
        border.color: "black"
        border.width: 2

        ColumnLayout{
            id: networkConfigurationDataColumnLayout
            spacing: 10
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 5
            anchors.leftMargin: 10
            property int textFieldWidths: 100

            Rectangle {
                id: networkConfigurationDataColumnSpacer
            }

            TextField {
                id: ipAddressTextField
                text: "10.17.21.127"
                width: networkConfigurationDataColumnLayout.textFieldWidths
            }

            TextField {
                id: portTextField
                text: "47808"
                width: networkConfigurationDataColumnLayout.textFieldWidths
            }
        }
    }

    Rectangle {
        id: networkConfigurationRightBarRectangle
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
                text: "Set"
                onClicked: {
                    console.log(ipAddressTextField.text + ":" + portTextField.text)
                    myBACnetInterface.setIPAddress(ipAddressTextField.text)
                    myBACnetInterface.setPort(parseInt(portTextField.text, 10))
                    myBACnetInterface.createUDPSocket()
                }

                background: Rectangle {
                    implicitWidth: 40
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
