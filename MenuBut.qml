import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
    id: menuBut
    width: 305
    height: 32
    text: "Test"

    state: enabled ? "" : "disabled"

    states: [
        State {
            name: "disabled"

            PropertyChanges {
                target: rect
                color: "#b3b7b7b7"
            }
        }
    ]
    opacity: 1
    antialiasing: true

    property var textSize: 10

    contentItem: Text {
        property bool wasClicked: true
        id: name
        text: wasClicked ? parent.text : "test"
        antialiasing: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "#ffffff"
        font.pixelSize: textSize
    }

    background: Rectangle{
        id:rect
        property bool isClicked: true
        color: isClicked ? "#b3606060" : border.color
        radius: 0
        border.width: 0
        border.color: "#99191919"

        MouseArea{

            anchors.fill: parent

            onPressed: {
                rect.isClicked = !rect.isClicked
            }

            onReleased:{
                rect.isClicked = !rect.isClicked
            }

            onClicked: {
                buttonClick();
            }
        }
    }

    property var buttonClick: (function() {
        //Implement yourself
    }
    )
}

/*##^##
Designer {
    D{i:0;height:32;width:305}
}
##^##*/
