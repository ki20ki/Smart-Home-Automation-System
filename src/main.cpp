#include "../include/SmartHomeHub.hpp"
#include "../include/DeviceFactory.hpp"
#include "../include/DeviceGroup.hpp"
#include "../include/Adapter.hpp"
#include "../include/Observer.hpp"
#include "../include/Command.hpp"
#include <iostream>

using namespace std;

int main() {
    // initialize hub with BrandA factory
    auto hub = SmartHomeHub::getInstance();
    hub->setFactory(make_unique<BrandAFactory>());

    // create devices
    auto light1 = hub->createLight("LivingRoomLight1");
    auto thermo1 = hub->createThermostat("LivingRoomThermostat");
    auto motion1 = hub->createMotionSensor("LivingRoomMotion");
    auto camera1 = hub->createSecurityCamera("LivingRoomCamera");
    auto doorLock1 = hub->createDoorLock("LivingRoomDoorLock");

    // create composite groups
    auto livingRoom = make_shared<DeviceGroup>("LivingRoom");
    livingRoom->add(make_shared<IndividualDevice>(light1));
    livingRoom->add(make_shared<IndividualDevice>(thermo1));
    livingRoom->add(make_shared<IndividualDevice>(motion1));
    livingRoom->add(make_shared<IndividualDevice>(camera1));
    livingRoom->add(make_shared<IndividualDevice>(doorLock1));

    auto firstFloor = make_shared<DeviceGroup>("FirstFloor");
    firstFloor->add(livingRoom);

    // adapter example: integrate legacy light
    auto legacyLight = make_shared<LegacyLight>();
    auto adaptedLight = make_shared<LegacyAdapter>(legacyLight);
    livingRoom->add(adaptedLight);

    // observer example: motion sensor triggers light
    auto motionWithObs = make_shared<MotionSensorWithObserver>();
    auto lightObs = make_shared<LightObserver>(light1);
    motionWithObs->attach(lightObs);
    motionWithObs->detectMotion(); // should turn on light1

    // command example: queue and execute commands
    CommandQueue queue;
    queue.addCommand(make_shared<TurnOnCommand>(livingRoom));
    queue.addCommand(make_shared<TurnOffCommand>(firstFloor));
    queue.executeNext(); // turn on LivingRoom group
    queue.executeNext(); // turn off FirstFloor group
    queue.undoLast();    // undo FirstFloor turn off

    // automation example: simple mode switching
    string mode = "EnergySaving";
    if (mode == "EnergySaving") {
        livingRoom->turnOff(); // simulate energy saving
    } else if (mode == "Comfort") {
        light1->dim(80); // simulate comfort mode
        thermo1->setTemperature(75);
    }

    // test door lock status
    cout << "Door lock status: " << doorLock1->getStatus() << "\n";
    doorLock1->lock();
    cout << "Door lock status after locking: " << doorLock1->getStatus() << "\n";

    return 0;
}