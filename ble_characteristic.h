#pragma once 
#include <QBluetoothUuid>
#include "dbus_object.h"
#include "ble_service.h"

class BleService;
class BleDescriptor;
class GattCharacteristic1Adaptor;

class BleCharacteristic : public DbusObject
{
    Q_OBJECT;

public:
    BleCharacteristic( const QBluetoothUuid &uuid );
    void add( BleDescriptor *descriptor );
    void registerCharacteristic();
    void setService( BleService *s );
    void setValue( const QByteArray& value );

public: // PROPERTIES
    Q_PROPERTY(QStringList Flags READ flags)
    QStringList flags() const { return m_flags; }

    Q_PROPERTY(bool Notifying READ notifying)
    bool notifying() const { return m_notifying; }

    Q_PROPERTY(QDBusObjectPath Service READ service)
    QDBusObjectPath service() const { return QDBusObjectPath(m_service->path()); }

    Q_PROPERTY(QString UUID READ uUID)
    QString uUID() const { return QUuidToString( m_uuid ); }

    Q_PROPERTY(QByteArray Value READ value)
    QByteArray value() const { return m_value; }

    QVector<BleDescriptor*>& descriptors() { return m_descriptors; }

public Q_SLOTS: // METHODS
    QByteArray ReadValue(const QVariantMap &options);
    void StartNotify();
    void StopNotify();
    void WriteValue(const QByteArray &value, const QVariantMap &options);

private:
    BleService *m_service = nullptr;
    QBluetoothUuid m_uuid;
    QVector<BleDescriptor*> m_descriptors;

    QStringList m_flags;
    bool m_notifying = false;
    QByteArray m_value;
};

// vim: set shiftwidth=4 expandtab cinoptions=t0,g0,j1,ws,(s,W1:
