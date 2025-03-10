#include "BACnetInterface.h"
#include <QDebug>
#include <QGuiApplication>

namespace BACnet {

BACnetInterface::BACnetInterface(QObject *parent)
    : QObject{parent}
{
    connect(&m_networking, SIGNAL(bytesReceivedSignal(int)), this, SLOT(handleBytesReceived(int)));
}

void BACnetInterface::shutdown()
{
    m_networking.shutdown();
}

void BACnetInterface::send()
{
    m_networking.send();
}

void BACnetInterface::setIPAddress(const QString& address)
{
    m_networking.setIPAddress(address);
}

void BACnetInterface::setPort(const int port)
{
    m_networking.setPort(port);
}

void BACnetInterface::setDeviceIPAddress(const QString& address)
{
    m_networking.setDeviceIPAddress(address);
}

void BACnetInterface::setDevicePort(const int port)
{
    m_networking.setDevicePort(port);
}

void BACnetInterface::createUDPSocket()
{
    m_networking.createUDPSocket();
}

void BACnetInterface::whoIs()
{
    m_networking.whoIs();
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
