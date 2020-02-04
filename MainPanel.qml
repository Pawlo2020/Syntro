import QtQuick 2.12
import QtQuick.Controls 2.12
import carmonitor 1.0
import "Pages"

Item {

    id: element

    Image {
        id: background
        x: 0
        y: 0
        width: 640
        height: 480
        fillMode: Image.PreserveAspectFit
        source: "Assets/midPanel.png"

        Text {

            objectName: "date"
            id: dateLbl
            x: 97
            y: 78
            width: 111
            height: 29
            color: "#ffffff"
            text: "monit.getTime() no scam"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }

        Text {
            objectName: "time"
            id: timeLbl
            x: 429
            y: 78
            width: 111
            height: 29
            color: "#ffffff"
            text: qsTr("12:00")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
        }

//        Page {
//            id: hostPage
//            x: 168
//            y: 135
//            width: 303
//            height: 258
//            antialiasing: true

//            contentItem: MainPage{

//            }

//            background: Rectangle{
//                color: "#00ffffff"
//            }
//        }

        Loader{
            id:hostLoader
            x: 168
            y: 135
            width: 303
            height: 258
            source:"Pages/MainPage.qml"
//            onLoaded: {
//            monit.getTime()
//            }
        }

        Connections {
            target: hostLoader.item
            onGo: hostLoader.setSource(msg)
        }

    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
