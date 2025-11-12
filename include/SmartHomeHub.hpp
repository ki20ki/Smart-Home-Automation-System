#ifndef SMART_HOME_HUB_HPP
#define SMART_HOME_HUB_HPP

#include "SmartDevice.hpp"
#include "DeviceFactory.hpp"
#include <map>
#include <memory>

using namespace std;

class SmartHomeHub {
private:
    static SmartHomeHub* instance;
    map<string, shared_ptr<SmartDevice>> devices;
    unique_ptr<DeviceFactory> factory;
    SmartHomeHub() = default;

public:
    static SmartHomeHub* getInstance();
    void setFactory(unique_ptr<DeviceFactory> f);
    void addDevice(const string& id, shared_ptr<SmartDevice> device);
    shared_ptr<SmartDevice> getDevice(const string& id);
    shared_ptr<Light> createLight(const string& id);
    shared_ptr<Thermostat> createThermostat(const string& id);
    shared_ptr<SecurityCamera> createSecurityCamera(const string& id);
    shared_ptr<DoorLock> createDoorLock(const string& id);
    shared_ptr<MotionSensor> createMotionSensor(const string& id);
};

#endif 