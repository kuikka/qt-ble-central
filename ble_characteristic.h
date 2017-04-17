#include <QtCore/QObject>

class BleService;
class BleDescriptor;

class BleCharacteristic : public QObject
{
	Q_OBJECT
public:
	BleCharacteristic( BleService *parent );
	void add( BleDescriptor *descriptor );
};
