import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    id: item_root
    property double slideIconHeight: 180
    property double slideIconWidth: 40
    property double iconWidth: slideIconWidth * 0.9
    property string backgroundColor: "#e0f0e9"

    width: slideIconWidth
    height: slideIconHeight

    signal button_home_clicked
    signal button_list_clicked
    signal button_todo_clicked
    signal button_note_clicked
    signal button_menu_clicked

    Rectangle {
        id: rectangle_root
        width: slideIconWidth
        height: slideIconHeight - menu_button.height
        anchors.fill: parent

        color: backgroundColor

        ListView {
            id: icon_list
            width: slideIconWidth
            height: parent.height
            anchors.fill: parent
        }
    }
    Rectangle {
        id: menu_button
        width: parent.width
        height: parent.width
        color: backgroundColor
        anchors.left: parent.left
        anchors.bottom: parent.bottom

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
            Image {
                id: img_menu
                source: "qrc:/img/file.svg"
                width: iconWidth
                height: iconWidth
                anchors.centerIn: parent
            }
        }
    }
}
