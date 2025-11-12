#include "../include/Command.hpp"

using namespace std;

TurnOnCommand::TurnOnCommand(shared_ptr<DeviceComponent> d) : device(d) {}

void TurnOnCommand::execute() { 
    device->turnOn(); 
}

void TurnOnCommand::undo() { 
    device->turnOff(); 
}

TurnOffCommand::TurnOffCommand(shared_ptr<DeviceComponent> d) : device(d) {}

void TurnOffCommand::execute() { 
    device->turnOff(); 
}

void TurnOffCommand::undo() { 
    device->turnOn(); 
}

void CommandQueue::addCommand(shared_ptr<Command> cmd) { 
    commands.push(cmd); 
}

void CommandQueue::executeNext() {
    if (!commands.empty()) {
        auto cmd = commands.front();
        commands.pop();
        cmd->execute();
        history.push_back(cmd);
    }
}

void CommandQueue::undoLast() {
    if (!history.empty()) {
        history.back()->undo();
        history.pop_back();
    }
}