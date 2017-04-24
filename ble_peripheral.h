#include <QtCore>
#include "dbus_object.h"
#include "objectmanager_adaptor.ii"

class ObjectManagerAdaptor;
class BleService;
class BleCharacteristic;
class BleDescriptor;
class BleCentral;

class BleCentral : public DbusObject
{
	Q_OBJECT

public:
	BleCentral( QObject *parent, const QString &path );

	void add( BleService *service );
	bool registerCentral();

public Q_SLOTS:
	ManagedObjectList GetManagedObjects();

private:
	ObjectManagerAdaptor	*m_manager = nullptr;
	QVector<BleService*>	m_services;

};
