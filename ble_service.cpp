#include "ble_central.h"
#include "ble_service.h"
#include "ble_characteristic.h"
#include "gattservice1_adaptor.h"

BleService::BleService( QObject *parent )
: DbusObject( parent )
{
	m_adaptor = new GattService1Adaptor( this );
}


void BleService::add( BleCharacteristic *service )
{
}

void BleService::setCentral( BleCentral *central )
{
	m_central = central;
}
