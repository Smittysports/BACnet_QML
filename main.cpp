#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "BACnetObjectTypes.h"
#include "NetworkSettings.h"
#include "BACnetInterface.h"
#include "LearningInterface.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // This registers the BACnetObjectTypes class for instantiation in QML
    qmlRegisterType<BACnet::BACnetObjectTypes>("com.BACnet.models", 1, 0, "BACnetObjectTypes");
    qmlRegisterType<BACnet::NetworkSettings>("com.BACnet.models", 1, 0, "NetworkSettings");

    QQmlApplicationEngine engine;

    // This instantiates the BACnetInterface class and allows many QML files to use it directly
    BACnet::BACnetInterface bacnetInterface{};
    engine.rootContext()->setContextProperty("myBACnetInterface", &bacnetInterface);
    Learning::LearningInterface learningInterface{};
    engine.rootContext()->setContextProperty("myLearningInterface", &learningInterface);

    const QUrl url(u"qrc:/BACnetModule/Main.qml"_qs);
    engine.load(url);
    
    return app.exec();
}
