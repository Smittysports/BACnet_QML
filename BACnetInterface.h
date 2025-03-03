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
    /** bytesReceived:               The name of the property
     *  READ bytesReceived:          The getter function that reads the property value
     *  WRITE setBytesReceived:      The setter function that modifies the properties value
     *  NOTIFY bytesReceivedChanged: The signal that is emitted when the property value changes
     */
    Q_PROPERTY(int bytesReceived READ bytesReceived WRITE setBytesReceived NOTIFY bytesReceivedChanged)

public:
    explicit BACnetInterface(QObject *parent = nullptr);

    Q_INVOKABLE void shutdown();

    /** The send method will attempt to send the BACnet message that was constructed to the desired BACnet device.
     *
     * The Q_INVOKABLE macro is used to flag to Qt that the send method can be called from QML. The BACnetInterface must
     * also be exposed to QML, which is done in main.cpp with qmlRegisterType. */
    Q_INVOKABLE void send();

    Q_INVOKABLE QString getCommand();

    Q_INVOKABLE QString getResponse();

    int bytesReceived() const;

    void setBytesReceived(const int bytes);

public slots:
    void handleBytesReceived(const int received);

private:
    Networking m_networking;
    int m_bytesReceived = 0;

signals:
    void bytesReceivedChanged(int bytes);
};

} // namespace BACnet

#endif // BACNETINTERFACE_H
