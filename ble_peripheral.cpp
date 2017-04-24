#include <QtCore>
#include <QtCore/QMetaObject>
#include <QtDBus/QtDBus>

#include "ble_peripheral.h"
#include "ble_service.h"
#include "ble_characteristic.h"
#include "ble_descriptor.h"
#include "objectmanager_adaptor.ii"
#include "objectmanager_adaptor.h"
#include "gattmanager1_interface.h"

BlePeripheral::BlePeripheral( QObject *parent, const QString &dbusPath )
    : DbusObject( parent )
{
    m_manager = new ObjectManagerAdaptor( this );
    setAdaptor( m_manager );
    setPath( dbusPath );

    qDebug() << "path " << path();
    qDebug() << "interface " << interface();
}

void BlePeripheral::add( BleService *service )
{
    service->setParent( this );
    service->setPeripheral( this );
    m_services.append( service );
}

bool BlePeripheral::registerPeripheral()
{
    for (int i = 0; i < m_services.size(); i++)
    {
        QString objectPath = QString( "%1/service%2" ).arg( path() ).arg( i );
        m_services[i]->setPath( objectPath );
        m_services[i]->registerService();
    }

    bool success = QDBusConnection::systemBus().registerObject( path(), this );
    qDebug() << "registerObject() success=" << success;

    OrgBluezGattManager1Interface *gattMgr = new OrgBluezGattManager1Interface( "org.bluez", "/org/bluez/hci0", QDBusConnection::systemBus(), this );
    gattMgr->RegisterApplication( QDBusObjectPath( path() ), QVariantMap() );

    return true;
}

ManagedObjectList BlePeripheral::GetManagedObjects()
{
    qDebug() << "BlePeripheral::GetManagedObjects()";
#if 0
    ManagedObjectList list;

    QVariantMap prop_value;
    prop_value[ "Uuid" ] = QString( "bbbbbbbb-bbbb-bbbb-bbbb-bbbbbbbbbbbb" );

    InterfaceList intfs;
    intfs[ "org.bluez.GattService1" ] = prop_value;

    list[ QDBusObjectPath( path() ) ] = intfs;
#endif

    ManagedObjectList list;
    for(BleService *s : m_services)
    {
        addObject(list, s);
        for(BleCharacteristic *c : s->characteristics())
        {
            addObject(list, c);
            for (BleDescriptor *d : c->descriptors())
            {
                addObject(list, d);
            }
        }
    }
    qDebug() << list;
    return list;
}

#if 1
QDebug &operator<<(QDebug &d, const QDBusObjectPath &p)
{
    d << p.path();
    d << "xxx";
    return d;
}
#endif

void BlePeripheral::addObject( ManagedObjectList &list, DbusObject *o )
{
    QVariantMap prop_value;

    for (int i = 0;
        i < o->adaptor()->metaObject()->propertyCount();
        i++)
    {
        const char *name = o->adaptor()->metaObject()->property(i).name();
        qDebug() << "Reading property: " << name;
        prop_value[ name ] = o->property( name );
    }

    InterfaceList intfs;
    intfs[ o->interface() ] = prop_value;

    list[ QDBusObjectPath(o->path()) ] = intfs;
}

// vim: set shiftwidth=4 expandtab cinoptions=t0,g0,j1,ws,(s,W1:
