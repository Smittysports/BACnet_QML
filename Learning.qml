/** Learning.qml
  */
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: learningRectangle
    anchors.fill: parent

    property var cpp11StringList: ["lambdas", "auto", "decltype", "uniform initialization syntax", "delete & default",
        "nullptr", "move semantics", "threading library", "smart pointers"]

    property var cpp14StringList: ["auto function return", "variable templates", "binary literals", "generic lambdas",
        "lambda capture expressions", "The [[deprecated]] attribute"]

    property var cpp17StringList: ["Optional value", "constexpr lambdas", "inline variables", "nested namespaces", "variant",
        "any", "Fold exressions"]

    property var cpp20StringList: ["Range-based for loop", "Attributes", "Constinit", "Lambda capture of parameter pack",
        "Lambda improvements", "Constexpr improvements", "Coroutines", "Modules", "Concept",
        "String literalts as template params", "Constant expressions", "Designated initializers", "Template syntax for lambdas"]

    property var cpp23StringList: ["Concept enhancements", "Module enhancements", "Coroutine enhancements", "Ranges enhancements",
        "Explicit object parameters", "if consteval", "Multidimensional subscruipt operator", "Enhanced lambda expressions",
        "size_t literal suffix", "..."]

    property int listChoice: 0
    property string listText: ""
    property var selectedItem: null

    Rectangle {
        id: learningBlackBorderId
        anchors.margins: 4
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 800
        height: 400
        border.color: "black"
        border.width: 2
        property int stringListHeights: 250
        property int stringItemHeights: 20

        RowLayout{
            id: learningRowLayout

            Rectangle {
                id: learningRowLayoutSpacer
                width: 10
            }

            ColumnLayout{
                id: learningColumnLayout
                spacing: 10
                property int textFieldWidths: 200

                Rectangle {
                    id: learningColumnSpacer
                }

                Text {
                    id: cpp11Field
                    text: "C++ 11"
                    color: "Green"
                    font.underline: true
                    width: learningColumnLayout.textFieldWidths
                }

                ScrollView {
                    Layout.fillWidth: true
                    Layout.minimumHeight: learningBlackBorderId.stringListHeights

                    Column {
                        width: parent.width
                        Repeater {
                            model: cpp11StringList

                            // TODO: This Rectangle is a candidate for re-factoring since it is common in 5 locations
                            Rectangle
                            {
                                width: learningColumnLayout.textFieldWidths
                                height: learningBlackBorderId.stringItemHeights

                                Text {
                                    id: cpp11ItemText
                                    text: modelData
                                    color: "Blue"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        if (learningRectangle.selectedItem != null)
                                            learningRectangle.selectedItem.color = "Blue"
                                        learningRectangle.selectedItem = cpp11ItemText
                                        learningRectangle.selectedItem.color = "Green"
                                        learningRectangle.listChoice = 1
                                        learningRectangle.listText = cpp11ItemText.text
                                    }
                                }
                            }
                        }
                    }
                }
                Rectangle {
                    id: learningColumnSpacer2
                }

                Text {
                    id: cpp14Field
                    text: "C++ 14"
                    color: "Green"
                    font.underline: true
                    width: learningColumnLayout.textFieldWidths
                }

                ScrollView {
                    Layout.fillWidth: true
                    Layout.minimumHeight: learningBlackBorderId.stringListHeights

                    Column {
                        width: parent.width

                        Repeater {
                            model: cpp14StringList

                            Rectangle
                            {
                                id: cpp14Rectangle
                                width: learningColumnLayout.textFieldWidths
                                height: learningBlackBorderId.stringItemHeights

                                Text {
                                    id: cpp14ItemText
                                    text: modelData
                                    color: "Blue"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        if (learningRectangle.selectedItem != null)
                                            learningRectangle.selectedItem.color = "Blue"
                                        learningRectangle.selectedItem = cpp14ItemText
                                        learningRectangle.selectedItem.color = "Green"
                                        learningRectangle.listChoice = 2
                                        learningRectangle.listText = cpp14ItemText.text
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Rectangle {
                id: learningRowLayoutSpacer2
                width: 10
            }

            ColumnLayout{
                id: learningColumnLayout2
                spacing: 10
                property int textFieldWidths: 100

                Rectangle {
                    id: learningColumnSpacer3
                }

                Text {
                    id: cpp17Field
                    text: "C++ 17"
                    color: "Green"
                    font.underline: true
                    width: learningColumnLayout.textFieldWidths
                }

                ScrollView {
                    Layout.fillWidth: true
                    Layout.minimumHeight: learningBlackBorderId.stringListHeights

                    Column {
                        width: parent.width

                        Repeater {
                            model: cpp17StringList

                            Rectangle
                            {
                                id: cpp17Rectangle
                                width: learningColumnLayout.textFieldWidths
                                height: learningBlackBorderId.stringItemHeights

                                Text {
                                    id: cpp17ItemText
                                    text: modelData
                                    color: "Blue"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        if (learningRectangle.selectedItem != null)
                                            learningRectangle.selectedItem.color = "Blue"
                                        learningRectangle.selectedItem = cpp17ItemText
                                        learningRectangle.selectedItem.color = "Green"
                                        learningRectangle.listChoice = 3
                                        learningRectangle.listText = cpp17ItemText.text
                                    }
                                }
                            }
                        }
                    }
                }

                Rectangle {
                    id: learningColumnSpacer4
                }

                Text {
                    id: cpp20Field
                    text: "C++ 20"
                    color: "Green"
                    font.underline: true
                    width: learningColumnLayout.textFieldWidths
                }

                ScrollView {
                    Layout.fillWidth: true
                    Layout.minimumHeight: learningBlackBorderId.stringListHeights

                    Column {
                        width: parent.width
                        Repeater {
                            model: cpp20StringList

                            Rectangle
                            {
                                id: cpp20Rectangle
                                width: learningColumnLayout.textFieldWidths
                                height: learningBlackBorderId.stringItemHeights

                                Text {
                                    id: cpp20ItemText
                                    text: modelData
                                    color: "Blue"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        if (learningRectangle.selectedItem != null)
                                            learningRectangle.selectedItem.color = "Blue"
                                        learningRectangle.selectedItem = cpp20ItemText
                                        learningRectangle.selectedItem.color = "Green"
                                        learningRectangle.listChoice = 4
                                        learningRectangle.listText = cpp20ItemText.text
                                    }
                                }
                            }
                        }
                    }
                }
            }

            ColumnLayout{
                id: learningColumnLayout3
                spacing: 10
                property int textFieldWidths: 100
                Layout.alignment: Qt.AlignTop

                Rectangle {
                    id: learningColumnSpacer5
                }

                Text {
                    id: cpp23Field
                    text: "C++ 23"
                    color: "Green"
                    font.underline: true
                    width: learningColumnLayout.textFieldWidths
                }

                ScrollView {
                    Layout.fillWidth: true
                    Layout.minimumHeight: learningBlackBorderId.stringListHeights

                    Column {
                        width: parent.width
                        Repeater {
                            model: cpp23StringList

                            Rectangle
                            {
                                id: cpp23Rectangle
                                width: learningColumnLayout.textFieldWidths
                                height: learningBlackBorderId.stringItemHeights

                                Text {
                                    id: cpp23ItemText
                                    text: modelData
                                    color: "Blue"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        if (learningRectangle.selectedItem != null)
                                            learningRectangle.selectedItem.color = "Blue"
                                        learningRectangle.selectedItem = cpp23ItemText
                                        learningRectangle.selectedItem.color = "Green"
                                        learningRectangle.listChoice = 5
                                        learningRectangle.listText = cpp23ItemText.text
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle {
        id: learningRightBarRectangle
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
                text: "Optional"
                onClicked: {
                    // TODO: Create a map to run the desired myLearningInterface method based on the name of the selected value
                    if (learningRectangle.listChoice == 1)
                        console.log("C++ 11")
                    else if (learningRectangle.listChoice == 2)
                        console.log("C++ 14")
                    else if (learningRectangle.listChoice == 3)
                    {
                        console.log("C++ 17")
                        if(learningRectangle.listText == "Optional value")
                            myLearningInterface.testOptional()
                    }
                    else if (learningRectangle.listChoice == 4)
                        console.log("C++ 20")
                    else if (learningRectangle.listChoice == 5)
                        console.log("C++ 23")

                    console.log(learningRectangle.listText)
                    // TODO: Get results to show up in the Log
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
