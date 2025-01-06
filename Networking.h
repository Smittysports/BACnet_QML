#ifndef NETWORKING_H
#define NETWORKING_H

#include <QUdpSocket>
#include <QObject>

namespace BACnet {

/**
 * @brief The Networking class
 */
class Networking : QObject
{
    Q_OBJECT

public:
    explicit Networking(QObject *parent = nullptr);

    void send();

    /** sendWriteAnalogValue
     *
     *  AnalogValue:
     * writeProperty example
     * 81 0a 00 18 01 04 02 05 e8 0f 0c 00 80 00 01 19 55 3e 44 3f 80 00 00 3f
     *
     * BVLC
     * 81 0a 00 18
     * - 0x81       = Type: BACnet/IP
     * - 0x0a       = Function: Original-Unicast-NPDU
     * - 0x00 0x18  = BVLC-Length: 24 byte BACnet packet length
     *
     * NPDU
     * - 0x01       = Version: ASHRAE 135-1995
     * - 0x04       = Control: Bit 3 is for 'Expecting Reply'
     *
     * APDU
     * - 0x02       = APDU Type: Confirmed-REQ (4 LSB)
     *                PDU Flags: 0x2 is for 'Segmented Response Accepted'
     * - 0x05       = Max Response Segments Accepted: Unspecificed
     *                Size of Maximum APDU accepted: (4 MSB = 0101) Up to 1476 octets
     * - 0xe8       = Invoke ID: 232
     * - 0x0f       = Service Choice: writeProperty
     * - 0x0c 0x00 0x80 0x00 0x01 = Object Identifier
     *       - 0x0c     = Context Tag: (MSB = 0)
     *                    Tag class: bit 4 = 1 'Context specific tag'
     *                    Length: bit 1 - 3 (4 bytes)
     *       - 0x00 0x80 0x00 0x01
     *                  = Object Type: Bits 23 - 32 = 0000 0000 10 'analog-value (2)'
     *                    Instance Number: Bits 1 - 22 = 1
     * - 0x19 0x55  = Property Identifier
     *      - 0x19      = Context Tag: Bit 4 = 1 'Context specific tag'
     *                    Context tag number: (MSB = 0001 = 1)
     *                    Length: bit 1 - 3 (1 byte)
     *      - 0x55      = Property Identifier: present-value (85)
     * - 0x3e       = Tag class: bit 4 = 1 'Context specific tag'
     *                Context Tag: (MSB = 3)
     *                Named tag: bit 1 - 3 'Opening Tag' (6)
     * - 0x44 0x3f 0x80 0x00 0x00    = Present value
     *      - 0x44      = Application Tag
     *                    Tag class: Bit 4 = 0 'Application tag'
     *                    Application tag number: (MSB = 0100) = 'Real' (4)
     *                    Length: bit 1 - 3 (4 bytes)
     *      - 0x3f 0x80 0x00 0x00: real value of 1
     * - 0x3f       = Tag class: bit 4 = 1 'Context specific tag'
     *                Context Tag: (MSB = 3)
     *                Named tag: bit 1 - 3 'Closing Tag' (7)
     */
    void sendWriteAnalogValue();

    /** sendReadAnalogValue
     *
     *  81 0a 00 11 01 04 02 05 3d 0c 0c 00 80 00 01 19 55
     */
    void sendReadAnalogValue();

private:
    QHostAddress m_hostAddress;
    int m_port;
    QUdpSocket* m_clientSocket;

public slots:
    void readyRead();
};

} // namespace BACnet

#endif // NETWORKING_H
