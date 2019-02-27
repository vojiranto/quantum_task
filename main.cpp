#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QVariant>
#include <QQmlContext>
#include <QFile>
#include <QTextStream>
#include "dataobject.h"

void readDataFile(QString a_fileName, QList<QObject*> *a_list)
{
    QFile l_file(a_fileName);
    if(!l_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&l_file);
    while (!in.atEnd()) {
        QString l_line = in.readLine();
        QStringList l_list = l_line.split(';');
        if (l_list.size() != 3) {
            break;
        }
        a_list->append(new DataObject(l_list[0], l_list[1], l_list[2]));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QList<QObject*> listModel;
    readDataFile(":/file.txt", &listModel);

    engine.rootContext()->setContextProperty(QStringLiteral("listModel"), QVariant::fromValue(listModel));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

