#include "ble_characteristic.h"
#include "ble_service.h"
#include "ble_descriptor.h"
#include "gattcharacteristic1_adaptor.h"

BleCharacteristic::BleCharacteristic( const QBluetoothUuid &uuid )
    : m_uuid( uuid )
{
    setAdaptor( new GattCharacteristic1Adaptor( this ) );
    m_flags << "read";
    m_flags << "write";
}

void BleCharacteristic::add( BleDescriptor *descriptor )
{
    descriptor->setParent( this );
    descriptor->setCharacteristic( this );
    m_descriptors.append( descriptor );
}

void BleCharacteristic::registerCharacteristic()
{
    bool success = QDBusConnection::systemBus().registerObject( path(), this );
    qDebug() << "registerObject() success=" << success;

    for (int i = 0; i < m_descriptors.size(); i++)
    {
        QString objectPath = QString( "%1/descriptor%2" ).arg( path() ).arg( i );
        m_descriptors[i]->setPath( objectPath );
        m_descriptors[i]->registerDescriptor();
    }
}

void BleCharacteristic::setService( BleService *s )
{
    m_service = s;
}

void BleCharacteristic::setValue( const QByteArray& value )
{
    m_value = value;
    notifyPropertyChanged( "Value" );
}

// method dos the gatt characteristic adaptor

QByteArray BleCharacteristic::ReadValue(const QVariantMap &options)
{
    qDebug() << "ReadValue()" << options;

    return m_value;
}

void BleCharacteristic::StartNotify()
{
    qDebug() << "StartNotify()";
}

void BleCharacteristic::StopNotify()
{
    qDebug() << "StopNotify()";
}

void BleCharacteristic::WriteValue(const QByteArray &value, const QVariantMap &options)
{
    qDebug() << "WriteValue " << value << options;
}


// vim: set shiftwidth=4 expandtab cinoptions=t0,g0,j1,ws,(s,W1:
