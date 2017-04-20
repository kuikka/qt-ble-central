#include <QtCore>
#include <QtCore/QMetaObject>
#include <QtDBus/QtDBus>

#include "ble_central.h"
#include "ble_service.h"
#include "objectmanager_adaptor.ii"
#include "objectmanager_adaptor.h"
#include "gattmanager1_interface.h"

BleCentral::BleCentral( QObject *parent, const QString &dbusPath )
	: DbusObject( parent )
{
	m_manager = new ObjectManagerAdaptor( this );
	setInterface( m_manager->metaObject()->classInfo(0).value() );
	setPath( dbusPath );
	
	qDebug() << "path " << path();
	qDebug() << "interface " << interface();

	bool success = QDBusConnection::systemBus().registerObject( path(), this );
	qDebug() << "registerObject() success=" << success;

	OrgBluezGattManager1Interface *gattMgr = new OrgBluezGattManager1Interface( "org.bluez", "/org/bluez/hci0", QDBusConnection::systemBus(), this );
	gattMgr->RegisterApplication( QDBusObjectPath( path() ), QVariantMap() );
}

void BleCentral::add( BleService *service )
{
	service->setParent( this );
	service->setCentral( this );
	m_services.add( service );
}

ManagedObjectList BleCentral::GetManagedObjects()
{
	qDebug() << "BleCentral::GetManagedObjects()";
	ManagedObjectList list;

	return list;
}


