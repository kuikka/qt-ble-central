#include <QtCore>
#include "dbus_object.h"
#include "objectmanager_adaptor.ii"

class ObjectManagerAdaptor;
class BleService;
class BleCharacteristic;
class BleDescriptor;

class BlePeripheral : public DbusObject
{
	Q_OBJECT

public:
	BlePeripheral( QObject *parent, const QString &path );

	void add( BleService *service );
	bool registerPeripheral();

public Q_SLOTS:
	ManagedObjectList GetManagedObjects();

private:
  void addObject( ManagedObjectList &list, DbusObject *o );
private:
	ObjectManagerAdaptor	*m_manager = nullptr;
	QVector<BleService*>	m_services;
  QVector<DbusObject*>  m_objects;

};
