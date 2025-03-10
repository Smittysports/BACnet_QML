#include "NetworkSettings.h"

namespace BACnet {
NetworkSettings::NetworkSettings(QObject *parent) :
    QAbstractListModel(parent)
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for (const QNetworkInterface &interface : interfaces) {
        qDebug()  << "Interface: " << interface.humanReadableName().toStdString();

        QList<QNetworkAddressEntry> entries = interface.addressEntries();
        for (const QNetworkAddressEntry &entry : entries) {
            QHostAddress ip = entry.ip();
            if (ip.protocol() == QAbstractSocket::IPv4Protocol) {

                m_items.append(ip.toString());

                qDebug()  << "  IP Address: " << ip.toString().toStdString();
                qDebug()  << "  Subnet Mask: " << entry.netmask().toString().toStdString();
                qDebug()  << "  Default Gateway: " << entry.broadcast().toString().toStdString();
            }
        }
    }
}

int NetworkSettings::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.size();
}

int NetworkSettings::currentIndex() const
{
    return m_currentIndex;
}

void NetworkSettings::setCurrentIndex(const int newIndex)
{
    qDebug() << "currentIndex = " << newIndex << "\n";
    if (m_currentIndex != newIndex)
    {
        m_currentIndex = newIndex;
        emit currentIndexChanged();
    }
}

QVariant NetworkSettings::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QString("nameRole");
}

QVariant NetworkSettings::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() && (role != NameRole) && (role != IDRole))
        return QVariant();

    if (role == NameRole)
    {
        return m_items.at(index.row());
    }
    return QVariant();
}

QHash<int, QByteArray> NetworkSettings::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "nameRole";
    roles[IDRole] = "idRole";
    return roles;
}

QStringList NetworkSettings::items() const
{
    return QStringList{};
}
} // namespace
