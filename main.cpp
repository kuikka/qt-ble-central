#include <QtCore>
#include <QtCore/QMetaObject>
#include <QtDBus/QtDBus>

#include "ble_central.h"
#include "ble_service.h"
#include "ble_characteristic.h"

int main(int argc, char *argv[])
{
	// TODO: find a better place
	qDBusRegisterMetaType<InterfaceList>();
	qDBusRegisterMetaType<ManagedObjectList>();

	QCoreApplication a(argc, argv);

	BleCentral central(&a, "/my/dbus/path");
	central.add( new BleService( QUuid( "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx" ) ) );;

	return a.exec();
}
