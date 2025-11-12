#include "../include/DeviceGroup.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

IndividualDevice::IndividualDevice(shared_ptr<SmartDevice> d) : device(d) {}

void IndividualDevice::turnOn() { 
    device->turnOn(); 
}

void IndividualDevice::turnOff() { 
    device->turnOff(); 
}

string IndividualDevice::getStatus() const { 
    return device->getStatus(); 
}

string IndividualDevice::getType() const { 
    return device->getType(); 
}

void IndividualDevice::add(shared_ptr<DeviceComponent>) {}

void IndividualDevice::remove(shared_ptr<DeviceComponent>) {}

DeviceGroup::DeviceGroup(const string& n) : name(n) {}

void DeviceGroup::turnOn() {
    cout << "Turning ON group: " << name << "\n";
    for (auto& child : children) child->turnOn();
}

void DeviceGroup::turnOff() {
    cout << "Turning OFF group: " << name << "\n";
    for (auto& child : children) child->turnOff();
}

string DeviceGroup::getStatus() const {
    return "Group " + name + " status";
}

string DeviceGroup::getType() const { 
    return "Group"; 
}

void DeviceGroup::add(shared_ptr<DeviceComponent> component) {
    children.push_back(component);
}

void DeviceGroup::remove(shared_ptr<DeviceComponent> component) {
    children.erase(std::remove(children.begin(), children.end(), component), children.end());
}
