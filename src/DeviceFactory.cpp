#include "../include/DeviceFactory.hpp"
#include <iostream>

using namespace std;

class LEDLight : public Light {
private:
    int brightness = 0;
public:
    void turnOn() override { brightness = 100; cout << "BrandA LED Light ON\n"; }
    void turnOff() override { brightness = 0; cout << "BrandA LED Light OFF\n"; }
    void dim(int level) override { brightness = level; cout << "BrandA LED Light dimmed to " << level << "\n"; }
    string getStatus() const override { return "Brightness: " + to_string(brightness); }
    string getType() const override { return "BrandA LEDLight"; }
};

class SmartThermostatA : public Thermostat {
private:
    int targetTemp = 72;
    string mode = "off";
public:
    void turnOn() override { mode = "heating"; cout << "BrandA Thermostat ON\n"; }
    void turnOff() override { mode = "off"; cout << "BrandA Thermostat OFF\n"; }
    void setTemperature(int temp) override { targetTemp = temp; cout << "Set temp to " << temp << "\n"; }
    void setMode(const string& m) override { mode = m; cout << "Mode set to " << m << "\n"; }
    string getStatus() const override { return "Temp: " + to_string(targetTemp) + ", Mode: " + mode; }
    string getType() const override { return "BrandA SmartThermostatA"; }
};

class WiredCamera : public SecurityCamera {
public:
    void turnOn() override { cout << "BrandA Wired Camera ON\n"; }
    void turnOff() override { cout << "BrandA Wired Camera OFF\n"; }
    void startRecording() override { cout << "Recording started\n"; }
    void stopRecording() override { cout << "Recording stopped\n"; }
    void enableNightVision() override { cout << "Night vision enabled\n"; }
    string getStatus() const override { return "Active"; }
    string getType() const override { return "BrandA WiredCamera"; }
};

class SmartDoorLock : public DoorLock {
private:
    bool locked = false;
public:
    void turnOn() override { lock(); }
    void turnOff() override { unlock(); }
    void lock() override { locked = true; cout << "Door locked\n"; }
    void unlock() override { locked = false; cout << "Door unlocked\n"; }
    string getStatus() const override { return locked ? "Locked" : "Unlocked"; }
    string getType() const override { return "BrandA SmartDoorLock"; }
};

class SmartMotionSensor : public MotionSensor {
public:
    void turnOn() override { cout << "Motion Sensor ON\n"; }
    void turnOff() override { cout << "Motion Sensor OFF\n"; }
    void detectMotion() override { cout << "Motion detected!\n"; }
    string getStatus() const override { return "Active"; }
    string getType() const override { return "BrandA SmartMotionSensor"; }
};

class HalogenLight : public Light {
private:
    int brightness = 0;
public:
    void turnOn() override { brightness = 100; cout << "BrandB Halogen Light ON\n"; }
    void turnOff() override { brightness = 0; cout << "BrandB Halogen Light OFF\n"; }
    void dim(int level) override { brightness = level; cout << "BrandB Halogen Light dimmed to " << level << "\n"; }
    string getStatus() const override { return "Brightness: " + to_string(brightness); }
    string getType() const override { return "BrandB HalogenLight"; }
};

class SmartThermostatB : public Thermostat {
private:
    int targetTemp = 72;
    string mode = "off";
public:
    void turnOn() override { mode = "cooling"; cout << "BrandB Thermostat ON\n"; }
    void turnOff() override { mode = "off"; cout << "BrandB Thermostat OFF\n"; }
    void setTemperature(int temp) override { targetTemp = temp; cout << "Set temp to " << temp << "\n"; }
    void setMode(const string& m) override { mode = m; cout << "Mode set to " << m << "\n"; }
    string getStatus() const override { return "Temp: " + to_string(targetTemp) + ", Mode: " + mode; }
    string getType() const override { return "BrandB SmartThermostatB"; }
};

class WirelessCamera : public SecurityCamera {
public:
    void turnOn() override { cout << "BrandB Wireless Camera ON\n"; }
    void turnOff() override { cout << "BrandB Wireless Camera OFF\n"; }
    void startRecording() override { cout << "Recording started\n"; }
    void stopRecording() override { cout << "Recording stopped\n"; }
    void enableNightVision() override { cout << "Night vision enabled\n"; }
    string getStatus() const override { return "Active"; }
    string getType() const override { return "BrandB WirelessCamera"; }
};

class BasicDoorLock : public DoorLock {
private:
    bool locked = false;
public:
    void turnOn() override { lock(); }
    void turnOff() override { unlock(); }
    void lock() override { locked = true; cout << "Door locked\n"; }
    void unlock() override { locked = false; cout << "Door unlocked\n"; }
    string getStatus() const override { return locked ? "Locked" : "Unlocked"; }
    string getType() const override { return "BrandB BasicDoorLock"; }
};

class BasicMotionSensor : public MotionSensor {
public:
    void turnOn() override { cout << "Motion Sensor ON\n"; }
    void turnOff() override { cout << "Motion Sensor OFF\n"; }
    void detectMotion() override { cout << "Motion detected!\n"; }
    string getStatus() const override { return "Active"; }
    string getType() const override { return "BrandB BasicMotionSensor"; }
};

unique_ptr<Light> BrandAFactory::createLight() { return make_unique<LEDLight>(); }
unique_ptr<Thermostat> BrandAFactory::createThermostat() { return make_unique<SmartThermostatA>(); }
unique_ptr<SecurityCamera> BrandAFactory::createSecurityCamera() { return make_unique<WiredCamera>(); }
unique_ptr<DoorLock> BrandAFactory::createDoorLock() { return make_unique<SmartDoorLock>(); }
unique_ptr<MotionSensor> BrandAFactory::createMotionSensor() { return make_unique<SmartMotionSensor>(); }

unique_ptr<Light> BrandBFactory::createLight() { return make_unique<HalogenLight>(); }
unique_ptr<Thermostat> BrandBFactory::createThermostat() { return make_unique<SmartThermostatB>(); }
unique_ptr<SecurityCamera> BrandBFactory::createSecurityCamera() { return make_unique<WirelessCamera>(); }
unique_ptr<DoorLock> BrandBFactory::createDoorLock() { return make_unique<BasicDoorLock>(); }
unique_ptr<MotionSensor> BrandBFactory::createMotionSensor() { return make_unique<BasicMotionSensor>(); }