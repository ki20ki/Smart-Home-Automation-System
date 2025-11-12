#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "SmartDevice.hpp"
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    vector<shared_ptr<Observer>> observers;
public:
    void attach(shared_ptr<Observer> observer);
    void detach(shared_ptr<Observer> observer);
    void notify(const string& message);
};

class MotionSensorWithObserver : public MotionSensor, public Subject {
public:
    void turnOn() override;
    void turnOff() override;
    void detectMotion() override;
    string getStatus() const override;
    string getType() const override;
};

class LightObserver : public Observer {
private:
    shared_ptr<Light> light;
public:
    LightObserver(shared_ptr<Light> l);
    void update(const string& message) override;
};

#endif 