import QtQuick 2.12

Item {
    id: tachometer
    width: 350
    height: 350

    signal pointerhange(string value)

    Image {
        id: tachometerSpace
        x: 0
        y: 0
        width: 350
        height: 350
        antialiasing: true
        scale: 1
        sourceSize.width: 0
        source: "Assets/test1butshadower.png"
        fillMode: Image.PreserveAspectFit

        Image {
            id: middle
            x: 125
            y: 125
            width: 100
            height: 100
            source: "Assets/PointerMid.png"
            fillMode: Image.PreserveAspectFit

            Image {
                objectName: "pointer"
                id: pointer
                x: -113
                y: 41
                width: 164
                height: 20
                z: -1
                rotation: -30
                transformOrigin: Item.Right
                source: "Assets/pointerItself.png"
                fillMode: Image.PreserveAspectFit

                property var targetRot: -30.0;


//                RotationAnimator {
//                    objectName: "tek";
//                       id: tek;
//                       target: pointer;
//                       from: pointer.rotation;
//                       to: targetRot;
//                       duration: 2000
//                       running: true

//                   }
            }

            Text {
                objectName: "gearLbl"
                id: gearLbl
                x: 10
                y: 10
                width: 80
                height: 80
                color: "#e1d1d1"
                text: "N"
                font.family: "Orbitron"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 52
            }
        }
    }

    Image {
        id: tachometerShield
        x: 0
        y: 0
        width: 350
        height: 350
        source: "Assets/glasscut.png"
        fillMode: Image.PreserveAspectFit
    }
}

/*##^##
Designer {
    D{i:0;height:350;width:350}
}
##^##*/
