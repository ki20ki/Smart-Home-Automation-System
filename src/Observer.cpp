#include "../include/Observer.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void Subject::attach(shared_ptr<Observer> observer) { 
    observers.push_back(observer); 
}

void Subject::detach(shared_ptr<Observer> observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const string& message) {
    for (auto& obs : observers) obs->update(message);
}

void MotionSensorWithObserver::turnOn() { 
    cout << "Motion Sensor ON\n"; 
}

void MotionSensorWithObserver::turnOff() { 
    cout << "Motion Sensor OFF\n"; 
}

void MotionSensorWithObserver::detectMotion() {
    cout << "Motion detected!\n";
    notify("MotionDetected");
}

string MotionSensorWithObserver::getStatus() const { 
    return "Active"; 
}

string MotionSensorWithObserver::getType() const { 
    return "MotionSensorWithObserver"; 
}

LightObserver::LightObserver(shared_ptr<Light> l) : light(l) {}

void LightObserver::update(const string& message) {
    if (message == "MotionDetected") {
        light->turnOn();
    }
}