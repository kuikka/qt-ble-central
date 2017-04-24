#!/bin/bash

qdbusxml2cpp -a objectmanager_adaptor.h: -i objectmanager_adaptor.ii org.freedesktop.DBus.ObjectManager.xml
qdbusxml2cpp -i objectmanager_adaptor.h -a :objectmanager_adaptor.cpp org.freedesktop.DBus.ObjectManager.xml

qdbusxml2cpp -p gattmanager1_interface.h: org.bluez.GattManager1.xml
qdbusxml2cpp -i gattmanager1_interface.h -p :gattmanager1_interface.cpp org.bluez.GattManager1.xml

qdbusxml2cpp -a gattservice1_adaptor.h: org.bluez.GattService1.xml
qdbusxml2cpp -i gattservice1_adaptor.h -a :gattservice1_adaptor.cpp org.bluez.GattService1.xml

qdbusxml2cpp -a gattcharacteristic1_adaptor.h: org.bluez.GattCharacteristic1.xml
qdbusxml2cpp -i gattcharacteristic1_adaptor.h -a :gattcharacteristic1_adaptor.cpp org.bluez.GattCharacteristic1.xml

qdbusxml2cpp -a gattdescriptor1_adaptor.h: org.bluez.GattDescriptor1.xml
qdbusxml2cpp -i gattdescriptor1_adaptor.h -a :gattdescriptor1_adaptor.cpp org.bluez.GattDescriptor1.xml

