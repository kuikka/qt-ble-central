#include <QtCore>
#include "dbus_object.h"

class BleCharacteristic;
class GattService1Adaptor;
class BleCentral;

class BleService : public DbusObject
{
	Q_OBJECT

public:
	BleService( const QUuid &uuid );
	void add( BleCharacteristic *service );
	void setCentral( BleCentral *central );

private:
	GattService1Adaptor	*m_adaptor = nullptr;
	BleCentral		*m_central = nullptr;
	QVector<BleCharacteristic*> m_characteristics;
	
};

