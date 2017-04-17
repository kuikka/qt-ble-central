#include <QtCore>
#include <QtCore/QMetaObject>
#include <QtDBus/QtDBus>

#include "ble_central.h"
#include "objectmanager_adaptor.ii"
#include "objectmanager_adaptor.h"
#include "gattmanager1_interface.h"

BleCentral::BleCentral( QObject *parent )
	: QObject( parent )
{
	m_manager = new ObjectManagerAdaptor( this );
	QString m_path( "/juha" );

	bool success = QDBusConnection::systemBus().registerObject( m_path, this );
	qDebug() << "registerObject() success=" << success;

	OrgBluezGattManager1Interface *gattMgr = new OrgBluezGattManager1Interface( "org.bluez", "/org/bluez/hci0", QDBusConnection::systemBus(), this );
	gattMgr->RegisterApplication( QDBusObjectPath( m_path ), QVariantMap() );
}

ManagedObjectList BleCentral::GetManagedObjects()
{
	qDebug() << "BleCentral::GetManagedObjects()";
	ManagedObjectList list;

	return list;
}

int main(int argc, char *argv[])
{
	// TODO: find a better place
	qDBusRegisterMetaType<InterfaceList>();
	qDBusRegisterMetaType<ManagedObjectList>();

	QCoreApplication a(argc, argv);

	BleCentral central(&a);

	return a.exec();
}

