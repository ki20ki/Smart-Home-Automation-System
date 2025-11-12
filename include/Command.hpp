#ifndef COMMAND_HPP
#define COMMAND_HPP

using namespace std;

#include "DeviceGroup.hpp"
#include <queue>
#include <vector>
#include <memory>

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class TurnOnCommand : public Command {
private:
    shared_ptr<DeviceComponent> device;
public:
    TurnOnCommand(shared_ptr<DeviceComponent> d);
    void execute() override;
    void undo() override;
};

class TurnOffCommand : public Command {
private:
    shared_ptr<DeviceComponent> device;
public:
    TurnOffCommand(shared_ptr<DeviceComponent> d);
    void execute() override;
    void undo() override;
};

class CommandQueue {
private:
    queue<shared_ptr<Command>> commands;
    vector<shared_ptr<Command>> history;
public:
    void addCommand(shared_ptr<Command> cmd);
    void executeNext();
    void undoLast();
};

#endif 