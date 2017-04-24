#include "ble_descriptor.h"
#include "ble_characteristic.h"

BleDescriptor::BleDescriptor( BleCharacteristic *parent )
: DbusObject( parent )
{
}

BleDescriptor::~BleDescriptor()
{
}

void BleDescriptor::registerDescriptor()
{
    bool success = QDBusConnection::systemBus().registerObject( path(), this );
    qDebug() << "registerObject() success=" << success;
}

QByteArray BleDescriptor::ReadValue(const QVariantMap &flags)
{
}

void BleDescriptor::WriteValue(const QByteArray &value, const QVariantMap &flags)
{
}
