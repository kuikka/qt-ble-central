CONFIG += debug
CONFIG += c++11

QT = core dbus

SOURCES += \
	ble_central.cpp \
	ble_service.cpp \
	ble_characteristic.cpp \
	ble_descriptor.cpp \
	objectmanager_adaptor.cpp \


HEADERS += \
	ble_central.h \
	ble_service.h \
	ble_characteristic.h \
	ble_descriptor.h \
	objectmanager_adaptor.h \


DBUS_INTERFACES += org.bluez.GattManager1.xml

# Build by hand because of typedefs
# DBUS_ADAPTORS += org.freedesktop.DBus.ObjectManager.xml
DBUS_ADAPTORS += org.bluez.GattService1.xml
DBUS_ADAPTORS += org.bluez.GattCharacteristic1.xml


