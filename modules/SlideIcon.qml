import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    id: item_root
    property double slide_icon_height: 180
    property double slide_icon_width: 40
    property string background_color: "#e0f0e9"

    width: slide_icon_width
    height: slide_icon_height

    signal button_home_clicked
    signal button_book_clicked
    signal button_todo_clicked
    signal button_note_clicked
    signal button_menu_clicked

    Rectangle {
        id: rectangle_root
        width: slide_icon_width
        height: slide_icon_height - menu_button.height
        anchors.fill: parent

        color: background_color

        ListView {
            id: icon_list
            width: slide_icon_width
            height: parent.height
            anchors.fill: parent
            anchors.top: parent.top
            anchors.topMargin: indent_button.width / 2
            model: iconModel
            delegate: iconComponent
        }

        ListModel {
            id: iconModel
            ListElement {
                imgSource: "qrc:/img/home.svg"
                elementName: "home"
            }
            ListElement {
                imgSource: "qrc:/img/carry out.svg"
                elementName: "todo"
            }
            ListElement {
                imgSource: "qrc:/img/edit-square.svg"
                elementName: "note"
            }
            ListElement {
                imgSource: "qrc:/img/book.svg"
                elementName: "book"
            }
        }

        Component {
            id: iconComponent
            Rectangle {
                width: parent.width
                height: parent.width
                color: background_color
                MenuButton {
                    id: menu_button
                    widgetWidth: parent.width
                    iconWidth: parent.width * 0.65
                    backgroundColor: background_color
                    imgPath: imgSource
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sendElementSignal(elementName)
                    }
                }
            }
        }
    }
    Rectangle {
        id: indent_button
        width: parent.width
        height: parent.width
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        MenuButton {
            id: menu_button
            widgetWidth: parent.width
            iconWidth: parent.width * 0.65
            backgroundColor: background_color
            imgPath: "qrc:/img/indent.svg"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                item_root.button_menu_clicked()
                console.log("indent clicked")
            }
        }
    }

    function sendElementSignal(elementName) {
        switch (elementName) {
        case "home":
            item_root.button_home_clicked()
            console.log("home clicked")
            break
        case "todo":
            item_root.button_todo_clicked()
            console.log("todo clicked")
            break
        case "note":
            item_root.button_note_clicked()
            console.log("note clicked")
            break
        case "book":
            item_root.button_book_clicked()
            console.log("book clicked")
            break
        }
    }
}
