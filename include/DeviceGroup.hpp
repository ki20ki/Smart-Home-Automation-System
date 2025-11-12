#ifndef DEVICE_GROUP_HPP
#define DEVICE_GROUP_HPP

using namespace std;

#include "SmartDevice.hpp"
#include <vector>
#include <string>
#include <memory>

class DeviceComponent : public SmartDevice {
public:
    virtual void add(shared_ptr<DeviceComponent> component) = 0;
    virtual void remove(shared_ptr<DeviceComponent> component) = 0;
    virtual ~DeviceComponent() = default;
};

class IndividualDevice : public DeviceComponent {
private:
    shared_ptr<SmartDevice> device;
public:
    IndividualDevice(shared_ptr<SmartDevice> d);
    void turnOn() override;
    void turnOff() override;
    string getStatus() const override;
    string getType() const override;
    void add(shared_ptr<DeviceComponent>) override;
    void remove(shared_ptr<DeviceComponent>) override;
};

class DeviceGroup : public DeviceComponent {
private:
    vector<shared_ptr<DeviceComponent>> children;
    string name;
public:
    DeviceGroup(const string& n);
    void turnOn() override;
    void turnOff() override;
    string getStatus() const override;
    string getType() const override;
    void add(shared_ptr<DeviceComponent> component) override;
    void remove(shared_ptr<DeviceComponent> component) override;
};

#endif 