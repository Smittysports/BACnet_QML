import QtQuick
import QtQuick.Controls

Column {
    anchors.margins: 4
    spacing: 3

    Rectangle {
        id: topLine
        border.width: 2
        width: parent.width
        height: 1
    }

    Rectangle {
        width: parent.width
        height: 20
        Text{
            id: testme
            anchors.margins: 4
            text: "    Log:"
        }
    }

    Rectangle {
        width: parent.width
        height: 200

        TextArea{
            id: textAreaId
            anchors.fill: parent
            anchors.margins: 4
            color: "black"
            placeholderText: "Text goes in here ...."
        }
    }

    Connections {
        target: myLearningInterface

        function onClearLogSignal() {
            textAreaId.text = ""
        }

        function onLogUpdatedSignal(message) {
            textAreaId.text += message;
        }
    }

}

