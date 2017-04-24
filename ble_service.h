#pragma once 
#include <QtCore>
#include <QBluetoothUuid>
#include "dbus_object.h"

class BleCharacteristic;
class GattService1Adaptor;
class BlePeripheral;

class BleService : public DbusObject
{
    Q_OBJECT;

public:
    BleService( const QUuid &uuid );
    void add( BleCharacteristic *service );
    void setPeripheral( BlePeripheral *peripheral );
    QVector<BleCharacteristic*>& characteristics();
    bool registerService();

public: // PROPERTIES
    Q_PROPERTY(bool Primary READ primary)
    bool primary() const { return true; }

    Q_PROPERTY(QString UUID READ Uuid)
    QString Uuid() const { qDebug() << QUuidToString(m_uuid); return QUuidToString(m_uuid); }

private:
    BlePeripheral		*m_peripheral = nullptr;
    QBluetoothUuid m_uuid;
    QVector<BleCharacteristic*> m_characteristics;
};

// vim: set shiftwidth=4 expandtab cinoptions=t0,g0,j1,ws,(s,W1:
