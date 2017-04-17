#include "ble_descriptor.h"
#include "ble_characteristic.h"

BleDescriptor::BleDescriptor( BleCharacteristic *parent )
: QObject( parent )
{
}

BleDescriptor::~BleDescriptor()
{
}
