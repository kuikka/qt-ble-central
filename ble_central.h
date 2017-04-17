#include <QtCore>
#include "objectmanager_adaptor.ii"

class ObjectManagerAdaptor;
class BleService;
class BleCharacteristic;
class BleDescriptor;
class BleCentral;



class BleCentral : public QObject
{
	Q_OBJECT

public:
	BleCentral( QObject *parent );
	void add( BleService *service );

public Q_SLOTS:
	ManagedObjectList GetManagedObjects();

private:
	ObjectManagerAdaptor	*m_manager = nullptr;

};
