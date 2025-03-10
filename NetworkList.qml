/** NetworkList.qml
  */
import QtQuick
import QtQuick.Controls
import com.BACnet.models 1.0
import Qt.labs.qmlmodels

Rectangle {
    width: 200
    height: 200
    anchors.margins: 4
    border.color: "black"
    border.width: 2
    visible: true

    /** The NetworkSettings is a class declared in C++. It is exposed to QML in main.cpp via qmlRegisterType.
    * The qmlRegisterType exposed the type using the com.BACnet.models module.
    */
    NetworkSettings {
        id: networkSettingsModel
    }

    /** The delegate describes how each item in the list is rendered in QML
     */
    Component {
        id: listDelegate
        Rectangle {
            id: mainRoleContainer
            height: 20
            width: 180
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
                            networkSettingsModel.currentIndex = itemIndex
                            networkConfigurationRectangle.ipAddressField.text = nameRoleText.text
                        }
                    }
                }
            }
        }
    }

    Rectangle{
        id: listViewRectangle
        height: 200
        width: 200
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
                text: "Network"
                color: "Green"
                font.underline: true
                font.bold: true
            }
        }

        ScrollView {
            id: networksTypesScrollView
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: headerItem.bottom
            anchors.bottom: parent.bottom

            ListView {
                id: networksListView
                anchors.fill: parent
                anchors.margins: 10
                keyNavigationWraps: true
                focus: true
                clip: true
                snapMode: ListView.SnapToItem

                // The model is the QAbstractListModel class, defined in C++, that we will bind the QML ListView to
                model: networkSettingsModel

                delegate: listDelegate
            }
        }
    }
}
