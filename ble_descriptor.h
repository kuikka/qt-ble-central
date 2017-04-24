#include <QtCore/QObject>
#include "dbus_object.h"
#include "ble_characteristic.h"


class BleDescriptor : public DbusObject
{
	Q_OBJECT
public:
	BleDescriptor( BleCharacteristic *parent );
	virtual ~BleDescriptor();
  void registerDescriptor();
  void setCharacteristic(BleCharacteristic *c) { m_characteristic = c; }

public: // PROPERTIES
    Q_PROPERTY(QDBusObjectPath Characteristic READ characteristic)
    QDBusObjectPath characteristic() const { return QDBusObjectPath(m_characteristic->path()); }

    Q_PROPERTY(QStringList Flags READ flags)
    QStringList flags() const { return QStringList(); }

    Q_PROPERTY(QString UUID READ uUID)
    QString uUID() const { return m_uuid.toString(); }

    Q_PROPERTY(QByteArray Value READ value)
    QByteArray value() const { return m_value; }

public Q_SLOTS: // METHODS
    QByteArray ReadValue(const QVariantMap &flags);
    void WriteValue(const QByteArray &value, const QVariantMap &flags);

private:

    BleCharacteristic   *m_characteristic;
    QBluetoothUuid m_uuid;
    QByteArray m_value;
};
