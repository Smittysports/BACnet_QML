#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "BACnetObjectTypes.h"
#include "BACnetInterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<BACnet::BACnetObjectTypes>("com.BACnet.models", 1, 0, "BACnetObjectTypes");
    qmlRegisterType<BACnet::BACnetInterface>("com.BACnet.models", 1, 0, "BACnetInterface");


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/BACnetModule/Main.qml"_qs);
    engine.load(url);
    
    return app.exec();
}
