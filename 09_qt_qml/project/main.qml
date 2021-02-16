import QtQuick.Window 2.2
import QtQuick 2.9

import QtQuick.Controls 2.2

import pl.podstawski 1.0


Window {
    width: 856
    height: 588
    visible: true
    title: qsTr("SPEED & ACCELERATION")

    Speed {
        id: speed
        onChanged: console.log("speed value changed");
        value: speed.get();
    }

    Acceleration {
        id: acceleration
        onChanged: console.log("acceleration value changed");
        value: acceleration.get();

    }

    Displacement {
        id: displacement
    }

    Dial {
        id: speedDial
        x: 150
        y: 202
        width: 263
        height: 251
        value: speed.value / 100

    }

    Dial {
        id: accelerationDial
        x: 445
        y: 202
        width: 263
        height: 251
        value: acceleration.value / 100

    }



    Text {
        id: speedIndicator
        x: 271
        y: 320
        width: 22
        height: 18
        color: "#ba0606"
        text: parseInt(speedDial.value * 100)
        font.pixelSize: 26
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"



    }

    Text {
        id: acceleraionIndicator
        x: 566
        y: 317
        width: 12
        height: 21
        color: "#0716d6"
        text: parseInt(accelerationDial.value * 100)
        font.pixelSize: 26
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
    }

    TextField {
        id: displacementText
        x: 328
        y: 116
        validator: IntValidator {bottom: 1; top: 100}
    }

    Button {
        id: button
        x: 552
        y: 116
        text: qsTr("Set displacement")
        font.capitalization: Font.AllUppercase
        font.weight: Font.Medium
        font.family: "Arial"
        onClicked: function() {
            var value = parseFloat(displacementText.text);
            displacement.set(value);
            displacementText.clear();
            speedAnimation.running = true;
            accelerationAnimation.running = true;
        }
            NumberAnimation {
            id: speedAnimation
            target: speedDial
            property: "value"
            duration: 500
            from: 0
            to: speed.value / 100
        }

            NumberAnimation {
            id: accelerationAnimation
            target: accelerationDial
            property: "value"
            duration: 500
            from: 0
            to: acceleration.value / 100
        }


    }

}


