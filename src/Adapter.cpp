#include "../include/Adapter.hpp"
#include <iostream>

using namespace std;

void LegacyLight::activate() { 
    cout << "Legacy Light activated\n"; 
}

void LegacyLight::deactivate() { 
    cout << "Legacy Light deactivated\n"; 
}

string LegacyLight::status() { 
    return "Legacy Light status"; 
}

LegacyAdapter::LegacyAdapter(shared_ptr<LegacyDevice> legacy) : legacyDevice(legacy) {}

void LegacyAdapter::turnOn() { 
    legacyDevice->activate(); 
}

void LegacyAdapter::turnOff() { 
    legacyDevice->deactivate(); 
}

string LegacyAdapter::getStatus() const { 
    return legacyDevice->status(); 
}

string LegacyAdapter::getType() const { 
    return "Legacy Adapted"; 
}

void LegacyAdapter::add(shared_ptr<DeviceComponent>) {}

void LegacyAdapter::remove(shared_ptr<DeviceComponent>) {}