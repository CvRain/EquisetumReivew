import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    property double iconWidth: 64
    property double widgetWidth: 64
    property color backgroundColor: "#e0f0e9"
    property string imgPath: ""

    id: item_root
    width: widgetWidth
    height: widgetWidth

    Rectangle {
        id: menu_button
        width: parent.width
        height: parent.height
        color: backgroundColor
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        MouseArea {
            id: menu_button_mouse
            anchors.fill: parent
            onEntered: {
                menu_button.color = Qt.lighter(parent.color, 1.01)
            }
            onExited: {
                menu_button.color = Qt.darker(parent.color, 1.01)
            }
        }

        Shape {
            anchors.fill: parent
            ShapePath {
                strokeWidth: 4
                strokeColor: Qt.lighter(backgroundColor, 1.1)
                strokeStyle: ShapePath.SolidLine
                startX: 0
                startY: 0
                PathLine {
                    x: menu_button.width
                    y: 0
                }
            }
        }
        Image {
            id: img_menu
            source: imgPath
            width: iconWidth
            height: iconWidth
            anchors.centerIn: parent
        }
    }
}
