#include <QtCore>
#include <QtCore/QMetaObject>
#include <QtDBus/QtDBus>

#include "ble_peripheral.h"
#include "ble_service.h"
#include "ble_characteristic.h"

int main(int argc, char *argv[])
{
	// TODO: find a better place
	qDBusRegisterMetaType<InterfaceList>();
	qDBusRegisterMetaType<ManagedObjectList>();

	QCoreApplication a(argc, argv);

  qDebug() << "baseService = " << QDBusConnection::systemBus().baseService();
  QDBusConnection::systemBus().registerService( "com.juha" );

  QBluetoothUuid uu( (quint16) 0xFFFF);
  QString ss = uu.toString();
  printf("UUID: %s\n", ss.toLatin1().constData());
  printf("UUID: %s\n", QUuidToString( uu ).toLatin1().constData());

	BlePeripheral peripheral(&a, "/my/dbus/path");
  BleService *s = new BleService( QBluetoothUuid( (quint16) 0x100 ) );
  BleCharacteristic *c = new BleCharacteristic( QBluetoothUuid( (quint16) 0x200 ) );

  s->add( c );
  peripheral.add( s );
  peripheral.registerPeripheral();
  c->setValue( QByteArray().append('f') );

	return a.exec();
}
