#include "../include/SmartHomeHub.hpp"
#include <iostream>

using namespace std;

SmartHomeHub* SmartHomeHub::instance = nullptr;

SmartHomeHub* SmartHomeHub::getInstance() {
    if (!instance) instance = new SmartHomeHub();
    return instance;
}

void SmartHomeHub::setFactory(unique_ptr<DeviceFactory> f) {
    factory = move(f);
}

void SmartHomeHub::addDevice(const string& id, shared_ptr<SmartDevice> device) {
    devices[id] = device;
}

shared_ptr<SmartDevice> SmartHomeHub::getDevice(const string& id) {
    auto it = devices.find(id);
    if (it != devices.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

shared_ptr<Light> SmartHomeHub::createLight(const string& id) {
    auto device = shared_ptr<Light>(factory->createLight());
    addDevice(id, device);
    return device;
}

shared_ptr<Thermostat> SmartHomeHub::createThermostat(const string& id) {
    auto device = shared_ptr<Thermostat>(factory->createThermostat());
    addDevice(id, device);
    return device;
}

shared_ptr<SecurityCamera> SmartHomeHub::createSecurityCamera(const string& id) {
    auto device = shared_ptr<SecurityCamera>(factory->createSecurityCamera());
    addDevice(id, device);
    return device;
}

shared_ptr<DoorLock> SmartHomeHub::createDoorLock(const string& id) {
    auto device = shared_ptr<DoorLock>(factory->createDoorLock());
    addDevice(id, device);
    return device;
}

shared_ptr<MotionSensor> SmartHomeHub::createMotionSensor(const string& id) {
    auto device = shared_ptr<MotionSensor>(factory->createMotionSensor());
    addDevice(id, device);
    return device;
}