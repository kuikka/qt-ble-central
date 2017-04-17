#include "ble_characteristic.h"
#include "ble_service.h"

BleService::BleService( QObject *parent )
: QObject( parent )
{
	m_adaptor = new GattService1Adaptor( this );
}


void BleService::add( BleCharacteristic *service )
{
}

void BleService::registerObject( const QString &path )
{
	bool success = QDBusConnection::systemBus().registerObject( path, this );
	qDebug() << "BleService::registerObject(" << path << ") success=" << success;
}
