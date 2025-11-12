#ifndef ADAPTER_HPP
#define ADAPTER_HPP

using namespace std;

#include "DeviceGroup.hpp"

class LegacyDevice {
public:
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual string status() = 0;
    virtual ~LegacyDevice() = default;
};

class LegacyLight : public LegacyDevice {
public:
    void activate() override;
    void deactivate() override;
    string status() override;
};

class LegacyAdapter : public DeviceComponent {
private:
    shared_ptr<LegacyDevice> legacyDevice;
public:
    LegacyAdapter(shared_ptr<LegacyDevice> legacy);
    void turnOn() override;
    void turnOff() override;
    string getStatus() const override;
    string getType() const override;
    void add(shared_ptr<DeviceComponent>) override;
    void remove(shared_ptr<DeviceComponent>) override;
};

#endif 