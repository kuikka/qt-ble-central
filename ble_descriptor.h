#include <QtCore/QObject>

class BleCharacteristic;

class BleDescriptor : public QObject
{
	Q_OBJECT
public:
	BleDescriptor( BleCharacteristic *parent );
	virtual ~BleDescriptor();
};
