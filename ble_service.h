#include <QtCore/QObject>

class BleCharacteristic;

class BleService : public QObject
{
	Q_OBJECT

public:
	BleService( QObject *parent );
	void add( BleCharacteristic *service );

private:
	GattService1Adaptor	*m_adaptor;
	
};

