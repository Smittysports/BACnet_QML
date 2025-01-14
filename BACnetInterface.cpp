#include "BACnetInterface.h"
#include <QDebug>

namespace BACnet {

BACnetInterface::BACnetInterface(QObject *parent)
    : QObject{parent}
{

}

void BACnetInterface::send()
{
    qDebug() << "Send\n";
    m_networking.send();
}

} // namespace BACnet
