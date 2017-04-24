CONFIG += debug
CONFIG += c++11

QT = core dbus bluetooth

SOURCES += \
	main.cpp \
	ble_peripheral.cpp \
	ble_service.cpp \
	ble_characteristic.cpp \
	ble_descriptor.cpp \
	objectmanager_adaptor.cpp \
	gattmanager1_interface.cpp \
	gattservice1_adaptor.cpp \
	gattcharacteristic1_adaptor.cpp \


HEADERS += \
	ble_peripheral.h \
	ble_service.h \
	ble_characteristic.h \
	ble_descriptor.h \
	objectmanager_adaptor.h \
	gattmanager1_interface.h \
	gattservice1_adaptor.h \
	gattcharacteristic1_adaptor.h \
	dbus_object.h \

