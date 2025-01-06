#include "Networking.h"
#include <QByteArray>
#include <QDebug>

namespace BACnet {

Networking::Networking(QObject *parent) :
    QObject{parent},
    m_hostAddress("10.0.0.179"),
    m_port(47808)
{
    m_clientSocket = new QUdpSocket(this);
    m_clientSocket->bind(m_hostAddress, m_port);
    m_clientSocket->flush();
    connect(m_clientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Networking::send()
{
    sendWriteAnalogValue();
    sendReadAnalogValue();
}

void Networking::sendWriteAnalogValue()
{
    // Write 1.0 to the PresentValu of an AnalogValue object
    unsigned char dat[]={0x81, 0x0a, 0x00, 0x18, 0x01, 0x04, 0x02, 0x05, 0xe8, 0x0f, 0x0c,
                           0x00, 0x80, 0x00, 0x01, 0x19, 0x55, 0x3e, 0x44, 0x3f, 0x80, 0x00,
                           0x00, 0x3f};
    QByteArray datagram=QByteArray::fromRawData((char*)dat,24);
    qDebug() << "sendWriteAnalogValue: " << datagram << "\n";
    QHostAddress device {"10.0.0.77"};
    int devicePort {47809};
    qint64 bytesSent = m_clientSocket->writeDatagram(datagram, device, devicePort);
    qDebug() << "Sent " << bytesSent << " bytes\n";
}

void Networking::sendReadAnalogValue()
{
    unsigned char dat[]={0x81, 0x0a, 0x00, 0x11, 0x01, 0x04, 0x02, 0x05, 0x3d, 0x0c, 0x0c, 0x00, 0x80, 0x00, 0x01, 0x19, 0x55};

    QByteArray datagram=QByteArray::fromRawData((char*)dat,17);
    qDebug() << "sendReadAnalogValue: " << datagram << "\n";
    QHostAddress device {"10.0.0.77"};
    int devicePort {47809};
    qint64 bytesSent = m_clientSocket->writeDatagram(datagram, device, devicePort);
    qDebug() << "Sent " << bytesSent << " bytes\n";
}

void Networking::readyRead()
{
    QByteArray Buffer;
    Buffer.resize(m_clientSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    qint64 bytesReceived = m_clientSocket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);
    qDebug() << "Received " << bytesReceived << " bytes\n";
}

} // namespace BACnet
