#include "ble_characteristic.h"
#include "ble_service.h"
#include "ble_descriptor.h"

BleCharacteristic::BleCharacteristic( BleService *parent )
	: QObject( parent )
{
}

void BleCharacteristic::add( BleDescriptor *descriptor )
{
}
