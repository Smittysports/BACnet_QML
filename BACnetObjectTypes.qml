import QtQuick
import QtQuick.Controls
import com.BACnet.models 1.0
import Qt.labs.qmlmodels

Rectangle {
    width: 500
    height: 500
    visible: true

    /** The BACnetObjectTypes is a class declared in C++. It is exposed to QML in main.cpp via qmlRegisterType.
    * The qmlRegisterType exposed the type using the com.BACnet.models module.
    */
    BACnetObjectTypes {
        id: objectTypesModel
    }

    /** The delegate describes how each item in the list is rendered in QML
     *
     * The delegate is accessed via its id. The ListView declares that the objectTypesModel is the
     * model it should utilize.
     *
     * The MouseArea is used to capture mouse clicks. When an item in the BACnetObjectTypes list is selected,
     * the index is updated in C++ as well as in the ListView.
     *
     * Component: A Component is not automatically displayed, unlike a Rectangle. A Component encapsulates the
     * QML types within and is not loaded until requested. Since it is not derived from Item, you cannot anchor anything
     * to it.
     */
    Component {
        id: listDelegate
        Rectangle {
            id: mainRoleContainer
            height: 20
            width: 220
            property var view: ListView.view
            property int itemIndex: index
            color: ListView.isCurrentItem ? "lightGreen" : "white"

            Rectangle {
                id: nameRoleRectangle
                height: 20
                width: 170
                anchors.left: parent.left
                color: "Transparent"

                Text {
                    id: nameRoleText
                    text: model.nameRole
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            view.currentIndex = itemIndex
                            objectTypesModel.currentIndex = itemIndex
                        }
                    }
                }
            }

            Rectangle {
                id: idRoleRectangle
                height: 20
                width: 20
                anchors.left: nameRoleRectangle.right
                color: "Transparent"

                Text {
                    id: idRoleText
                    text: model.idRole
                }
            }

        }
    }

    Rectangle{
        id: listViewRectangle
        height: 400
        width: 220
        border.width: 2

        Rectangle {
            id: headerItem
            width: parent.width
            height:30
            anchors.margins: 10
            anchors.left: parent.left
            anchors.top: parent.top
            z: 2

            color: "Transparent"

            Text {
                text: "Object Name                       ID"
                color: "Green"
                font.underline: true
                font.bold: true
            }
        }

        ScrollView {
            id: objectTypesScrollView
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: headerItem.bottom
            anchors.bottom: parent.bottom

            ListView {
                id: objectTypesListView
                anchors.fill: parent
                anchors.margins: 10
                keyNavigationWraps: true
                focus: true
                clip: true
                snapMode: ListView.SnapToItem

                // The model is the QAbstractListModel class, defined in C++, that we will bind the QML ListView to
                model: objectTypesModel

                delegate: listDelegate

                Component.onCompleted: {
                    // I needed to add this in order to get the keyboard to be captured
                    objectTypesListView.forceActiveFocus()
                }
            }
        }
    }

    Text {
        anchors.top: listViewRectangle.bottom
        text: "Count = " + objectTypesModel.count
    }
}
