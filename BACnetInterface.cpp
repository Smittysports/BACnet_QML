#include "BACnetInterface.h"
#include <QDebug>

namespace BACnet {

BACnetInterface::BACnetInterface(QObject *parent)
    : QObject{parent}
{
    connect(&m_networking, SIGNAL(bytesReceivedSignal(int)), this, SLOT(handleBytesReceived(int)));
}

void BACnetInterface::send()
{
    qDebug() << "Send\n";
    m_networking.send();
}

QString BACnetInterface::getCommand()
{
    return m_networking.getCommands().toHex();
}

QString BACnetInterface::getResponse()
{
    return m_networking.getResponse().toHex();
}

int BACnetInterface::bytesReceived() const
{
    return m_bytesReceived;
}

void BACnetInterface::setBytesReceived(const int bytes)
{
    if (m_bytesReceived != bytes)
    {
        m_bytesReceived = bytes;
        emit bytesReceivedChanged(bytes);
    }
}

void BACnetInterface::handleBytesReceived(const int received)
{
    setBytesReceived(received);
}

} // namespace BACnet
