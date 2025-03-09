/** BackButton.qml
  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {

    background: Rectangle {
        implicitWidth: 40
        implicitHeight: 40
        border.color: "black"
        border.width: 2
        radius: 4
        color: parent.down ? "lightgray" :
                (parent.hovered ? "green" : "gray")
        Image {
            width: parent.width * 0.9
            height: parent.height * 0.9
            source: "img/back-arrow-black.png"
            fillMode: Image.Stretch
            opacity: 0.5
        }
    }

    onClicked: {
        mainContentLoader.source = "MainScreenChooser.qml"
    }
}
