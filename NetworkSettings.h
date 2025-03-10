#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QAbstractListModel>
#include <QObject>
#include <QNetworkInterface>

namespace BACnet {
class NetworkSettings : public QAbstractListModel
{
    Q_OBJECT

    /** Enables QML to directly access and bind properties in the C++ model.
     *
     * items: The name of the property accessible from QML
     * itemsChanged: The signal emitted when the property changes */
    Q_PROPERTY(QStringList items READ items NOTIFY itemsChanged)

    /** Enables QML to directly access and bind to the number of m_items.
     *
     * count: The number of m_items, accessible from QML
     * rowCount (READ): The C++ method to read the number of m_items
     * countChanged: The signal emitted when the property changes */
    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)

    /** Enables QML to directly access and bind to the m_currentIndex of this class.
     *
     * currentIndex: The alias, of m_currentIndex, that is accessible from QML
     * currentIndex (READ): The C++ method to read the current index
     * setCurrentIndex (WRITE): The C++ method to modify the current index
     * currentIndexChanged: The signal emitted when the property changes */
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)

public:
    NetworkSettings(QObject *parent = nullptr);

    /** Roles are used to access the desired data in a list. If the list is very simple, there may not be a need
     * to add new roles.
     */
    enum Roles {
        NameRole = Qt::UserRole + 1,
        IDRole,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int currentIndex() const;

    void setCurrentIndex(const int newIndex);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::UserRole) const override;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole) const override;

    /** returns the available role names used by BACnetObjectTypes */
    virtual QHash<int, QByteArray> roleNames() const override;

    QStringList items() const;

private:
    QList<QString> m_items;
    int m_currentIndex = 0;

signals:
    void itemsChanged();

    void countChanged();

    void currentIndexChanged();
};
} // namespace
#endif // NETWORKSETTINGS_H
