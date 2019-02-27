import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4

ApplicationWindow {
    id: window
    visible: true
    width: 500
    height: 500
    title: qsTr("TableView")
    TableView {
        width: parent.width
        height: parent.height
        TableViewColumn {
            role: "user_id"
            title: "Id"
            width: window.width * 1/5 - 2
        }
        TableViewColumn {
            role: "user_name"
            title: "Name"
            width: window.width * 2/5
        }
        TableViewColumn {
            role: "phone_number"
            title: "Phone number"
            width: window.width * 2/5
        }
        model: listModel
    }
}
