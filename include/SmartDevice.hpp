#ifndef SMART_DEVICE_HPP
#define SMART_DEVICE_HPP

#include <string>
#include <memory>

using namespace std;

class SmartDevice {
public:
    virtual ~SmartDevice() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() const = 0;
    virtual string getType() const = 0;
};

class Light : public SmartDevice {
private:
    int brightness = 0;
public:
    virtual void dim(int level) = 0;
};

class Thermostat : public SmartDevice {
private:
    int targetTemp = 72;
    string mode = "off";
public:
    virtual void setTemperature(int temp) = 0;
    virtual void setMode(const string& m) = 0;
};

class SecurityCamera : public SmartDevice {
public:
    virtual void startRecording() = 0;
    virtual void stopRecording() = 0;
    virtual void enableNightVision() = 0;
};

class DoorLock : public SmartDevice {
private:
    bool locked = false;
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class MotionSensor : public SmartDevice {
public:
    virtual void detectMotion() = 0;
};

#endif 