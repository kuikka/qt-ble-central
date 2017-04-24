#include "ble_peripheral.h"
#include "ble_service.h"
#include "ble_characteristic.h"
#include "gattservice1_adaptor.h"

BleService::BleService( const QUuid &uuid )
    : m_uuid( uuid )
{
    setAdaptor( new GattService1Adaptor( this ) );
}

void BleService::add( BleCharacteristic *c )
{
    c->setParent( this );
    c->setService( this );
    m_characteristics.append( c );
}

void BleService::setPeripheral( BlePeripheral *peripheral )
{
    m_peripheral = peripheral;
}

QVector<BleCharacteristic*>& BleService::characteristics()
{
    return m_characteristics;
}

bool BleService::registerService()
{
    bool success = QDBusConnection::systemBus().registerObject( path(), this );
    qDebug() << "registerObject() success=" << success;

    for (int i = 0; i < m_characteristics.size(); i++)
    {
        QString objectPath = QString( "%1/characteristic%2" ).arg( path() ).arg( i );
        m_characteristics[i]->setPath( objectPath );
        m_characteristics[i]->registerCharacteristic();
    }

    return true;
}


// vim: set shiftwidth=4 expandtab cinoptions=t0,g0,j1,ws,(s,W1:
