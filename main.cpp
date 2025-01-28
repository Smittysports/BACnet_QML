#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "BACnetObjectTypes.h"
#include "BACnetInterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // This registers the BACnetObjectTypes class for instantiation in QML
    qmlRegisterType<BACnet::BACnetObjectTypes>("com.BACnet.models", 1, 0, "BACnetObjectTypes");

    QQmlApplicationEngine engine;

    // This instantiates the BACnetInterface class and allows many QML files to use it directly
    BACnet::BACnetInterface bacnetInterface{};
    engine.rootContext()->setContextProperty("myBACnetInterface", &bacnetInterface);

    const QUrl url(u"qrc:/BACnetModule/Main.qml"_qs);
    engine.load(url);
    
    return app.exec();
}
