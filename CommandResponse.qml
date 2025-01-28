import QtQuick
import QtQuick.Controls

Rectangle {
    id: commandResponse

    Column {
        anchors.margins: 4
        spacing: 3

        Text {
            id: messageSentText
            text: "Sent:"
        }

        Text {
            id: bytesReceivedText
            text: "Bytes received: " + myBACnetInterface.bytesReceived
            onTextChanged:
            {
                messageSentText.text = "Sent: " + myBACnetInterface.getCommand()
                messageReceivedText.text = "Received: " + myBACnetInterface.getResponse()
            }
        }

        Text {
            id: messageReceivedText
            text: "Received:"
        }
    }
}

