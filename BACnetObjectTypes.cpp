#include "BACnetObjectTypes.h"

namespace BACnet {

#include "BACnetObjectTypes.h"

BACnetObjectTypes::BACnetObjectTypes(QObject *parent) :
    QAbstractListModel(parent),
    m_items{ {"Access Credential", 32}, {"Access Door", 30}, {"Access Point", 33}, {"Access User", 35}, {"Access Zone", 36},
        {"Accumulator", 23}, {"Alert Enrollment", 52} , {"Analog Input", 0}, {"Analog Output", 1} , {"Analog Value", 2},
        {"Audit Log", 61}, {"Audit Reporter", 62}, {"Averaging", 18}, {"Binary Input", 3}, {"Binary Lighting Output", 55},
        {"Binary Output", 4}, {"Binary Value", 5}, {"Calendar", 6}, {"Channel", 53}, {"Character String Value", 40},
        {"Command", 7}, {"Credential Data Input", 37}, {"Date Pattern Value", 41}, {"Date Value", 42}, {"DateTime Pattern Value", 43},
        {"DateTime Value", 44}, {"Device", 8}, {"Elevator Group", 57}, {"Escalator", 58}, {"Event Enrollment", 9},
        {"Event Log", 25}, {"File", 10}, {"Global Group", 26}, {"Group", 11}, {"Integer Value", 45},
        {"Large Analog Value", 46}, {"Life Safety Point", 21}, {"Life Safety Zone", 22}, {"Lift", 59}, {"Lighting Output", 54},
        {"Load Control", 28}, {"Loop", 12}, {"Multi-state Input", 13}, {"Multi-state Output", 14}, {"Multi-state Value", 19},
        {"Network Port", 56}, {"Notification Class", 15}, {"Notification Forwarder", 51}, {"OctetString Value", 47},
        {"Positive Integer Value", 48}, {"Program", 16}, {"Pulse Converter", 24}, {"Schedule", 17}, {"Staging", 60},
        {"Structured View", 29}, {"Time Pattern Value", 49}, {"Time Value",50}, {"Timer", 31}, {"Trend Log", 20}, {"Trend Log Multiple", 27}
        }
{

}

int BACnetObjectTypes::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.size();
}

int BACnetObjectTypes::currentIndex() const
{
    return m_currentIndex;
}

void BACnetObjectTypes::setCurrentIndex(const int newIndex)
{
    qDebug() << "currentIndex = " << newIndex << "\n";
    if (m_currentIndex != newIndex)
    {
        m_currentIndex = newIndex;
        emit currentIndexChanged();
    }
}

QVariant BACnetObjectTypes::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QString("nameRole");
}

QVariant BACnetObjectTypes::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() && (role != NameRole) && (role != IDRole))
        return QVariant();

    if (role == NameRole)
    {
        auto pairVal = m_items.at(index.row());
        return pairVal.first;
    }
    else
    {
        auto pairVal = m_items.at(index.row());
        return pairVal.second;
    }
}

QHash<int, QByteArray> BACnetObjectTypes::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "nameRole";
    roles[IDRole] = "idRole";
    return roles;
}

QStringList BACnetObjectTypes::items() const
{
    return QStringList{};
}

} // namespace BACnet
