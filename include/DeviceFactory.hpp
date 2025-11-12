#ifndef DEVICE_FACTORY_HPP
#define DEVICE_FACTORY_HPP

#include "SmartDevice.hpp"
#include <memory>

using namespace std;

class DeviceFactory {
public:
    virtual unique_ptr<Light> createLight() = 0;
    virtual unique_ptr<Thermostat> createThermostat() = 0;
    virtual unique_ptr<SecurityCamera> createSecurityCamera() = 0;
    virtual unique_ptr<DoorLock> createDoorLock() = 0;
    virtual unique_ptr<MotionSensor> createMotionSensor() = 0;
    virtual ~DeviceFactory() = default;
};

class BrandAFactory : public DeviceFactory {
public:
    unique_ptr<Light> createLight() override;
    unique_ptr<Thermostat> createThermostat() override;
    unique_ptr<SecurityCamera> createSecurityCamera() override;
    unique_ptr<DoorLock> createDoorLock() override;
    unique_ptr<MotionSensor> createMotionSensor() override;
};

class BrandBFactory : public DeviceFactory {
public:
    unique_ptr<Light> createLight() override;
    unique_ptr<Thermostat> createThermostat() override;
    unique_ptr<SecurityCamera> createSecurityCamera() override;
    unique_ptr<DoorLock> createDoorLock() override;
    unique_ptr<MotionSensor> createMotionSensor() override;
};

#endif 