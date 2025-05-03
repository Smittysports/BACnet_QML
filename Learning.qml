/** Learning.qml
  */
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: learningRectangle
    anchors.fill: parent


    property var functionMapCpp11: ({
        "lambdas": myLearningInterface.notImplemented,
        "auto": myLearningInterface.notImplemented,
        "decltype": myLearningInterface.notImplemented,
        "uniform initialization syntax": myLearningInterface.notImplemented,
        "delete & default": myLearningInterface.notImplemented,
        "nullptr": myLearningInterface.notImplemented,
        "move semantics": myLearningInterface.notImplemented,
        "threading library": myLearningInterface.notImplemented,
        "smart pointers": myLearningInterface.notImplemented
    })

    property var functionMapCpp14: ({
        "auto function return": myLearningInterface.notImplemented,
        "variable templates": myLearningInterface.notImplemented,
        "binary literals": myLearningInterface.notImplemented,
        "generic lambdas": myLearningInterface.notImplemented,
        "lambda capture expressions": myLearningInterface.notImplemented,
        "The [[deprecated]] attribute": myLearningInterface.notImplemented
    })

    property var functionMapCpp17: ({
        "Optional value": myLearningInterface.testOptional,
        "constexpr lambdas": myLearningInterface.notImplemented,
        "inline variables": myLearningInterface.notImplemented,
        "nested namespaces": myLearningInterface.notImplemented,
        "variant": myLearningInterface.notImplemented,
        "any": myLearningInterface.notImplemented,
        "Fold exressions": myLearningInterface.notImplemented
    })

    property var functionMapCpp20: ({
        "Range-based for loop": myLearningInterface.notImplemented,
        "Attributes": myLearningInterface.notImplemented,
        "Constinit": myLearningInterface.notImplemented,
        "Lambda capture of parameter pack": myLearningInterface.notImplemented,
        "Lambda improvements": myLearningInterface.notImplemented,
        "Constexpr improvements": myLearningInterface.notImplemented,
        "Coroutines": myLearningInterface.notImplemented,
        "Modules": myLearningInterface.notImplemented,
        "Concept": myLearningInterface.notImplemented,
        "String literalts as template params": myLearningInterface.notImplemented,
        "Constant expressions": myLearningInterface.notImplemented,
        "Designated initializers": myLearningInterface.notImplemented,
        "Template syntax for lambdas": myLearningInterface.notImplemented
    })

    property var functionMapCpp23: ({
        "Concept enhancements": myLearningInterface.notImplemented,
        "Module enhancements": myLearningInterface.notImplemented,
        "Coroutine enhancements": myLearningInterface.notImplemented,
        "Ranges enhancements": myLearningInterface.notImplemented,
        "Explicit object parameters": myLearningInterface.notImplemented,
        "if consteval": myLearningInterface.notImplemented,
        "Multidimensional subscruipt operator": myLearningInterface.notImplemented,
        "Enhanced lambda expressions": myLearningInterface.notImplemented,
        "size_t literal suffix": myLearningInterface.notImplemented
    })

    property var currentMap: functionMapCpp17
    property string chosenFunctionKey: ""
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
                            model: Object.keys(functionMapCpp11)

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
                                        learningRectangle.currentMap = functionMapCpp11
                                        learningRectangle.chosenFunctionKey = cpp11ItemText.text
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
                            model: Object.keys(functionMapCpp11)

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
                                        learningRectangle.currentMap = functionMapCpp14
                                        learningRectangle.chosenFunctionKey = cpp14ItemText.text
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
                            model: Object.keys(functionMapCpp17)

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
                                        learningRectangle.currentMap = functionMapCpp17
                                        learningRectangle.chosenFunctionKey = cpp17ItemText.text
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
                            model: Object.keys(functionMapCpp20)

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
                                        learningRectangle.currentMap = functionMapCpp20
                                        learningRectangle.chosenFunctionKey = cpp20ItemText.text
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
                            model: Object.keys(functionMapCpp23)

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
                                        learningRectangle.currentMap = functionMapCpp23
                                        learningRectangle.chosenFunctionKey = cpp23ItemText.text
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
                text: "Run"
                property string functionKey: learningRectangle.chosenFunctionKey

                onClicked: {
                    if (currentMap.hasOwnProperty(learningRectangle.chosenFunctionKey))
                    {
                        currentMap[learningRectangle.chosenFunctionKey]()
                    }
                    else
                    {
                        myLearningInterface.clearLog()
                        myLearningInterface.logText(learningRectangle.chosenFunctionKey + ": Not implemented")
                    }
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
