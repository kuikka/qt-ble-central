#!/bin/bash

qdbusxml2cpp -a objectmanager_adaptor.h: -i objectmanager_adaptor.ii org.freedesktop.DBus.ObjectManager.xml
qdbusxml2cpp -i objectmanager_adaptor.h -a :objectmanager_adaptor.cpp org.freedesktop.DBus.ObjectManager.xml

