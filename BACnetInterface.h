#ifndef BACNETINTERFACE_H
#define BACNETINTERFACE_H

#include <QObject>
#include "Networking.h"

namespace BACnet {

/** This class is used to expose methods to QML.
 *  The BACnetInterface class is exposed to QML in main.cpp with qmlRegisterType.
 *
 * @extends QObject in order to utilize singals, slots, Q_OBJECT, Q_INVOKABLE, etc... */
class BACnetInterface : public QObject
{
    Q_OBJECT
public:
    explicit BACnetInterface(QObject *parent = nullptr);

    /** The send method will attempt to send the BACnet message that was constructed to the desired BACnet device.
     *
     * The Q_INVOKABLE macro is used to flag to Qt that the send method can be called from QML. The BACnetInterface must
     * also be exposed to QML, which is done in main.cpp with qmlRegisterType. */
    Q_INVOKABLE void send();

    Q_INVOKABLE QByteArray getResponse();
private:
    Networking m_networking;
};

} // namespace BACnet

#endif // BACNETINTERFACE_H
