import QtQuick 2.12

Item {
    id: tachometer
    width: 350
    height: 350

    Image {
        id: tachometerSpace
        x: 0
        y: 0
        width: 350
        height: 350
        antialiasing: true
        scale: 1
        sourceSize.width: 0
        source: "Assets/speedometer shield SHADOWER.png"
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
                objectName: "speedometer"
                id: pointer
                x: -113
                y: 41
                width: 164
                height: 20
                rotation: -30
                z: -1
                transformOrigin: Item.Right
                source: "Assets/pointerItself.png"
                fillMode: Image.PreserveAspectFit
            }
        }
    }

    Image {
        id: tachometerShield
        x: 0
        y: 0
        width: 350
        height: 350
        rotation: -197.609
        source: "Assets/glasscut.png"
        fillMode: Image.PreserveAspectFit
    }
}

/*##^##
Designer {
    D{i:0;height:350;width:350}
}
##^##*/
