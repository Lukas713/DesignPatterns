#ifndef DESIGNPATTERNS_COMMAND_H
#define DESIGNPATTERNS_COMMAND_H

#endif //DESIGNPATTERNS_COMMAND_H

/**
 * Reciever
 * Reciever Knows how to perform action that will carry out the request
 */
class Light {
public:
    void on(){ //possible request
        std::cout << "Lights are turned on!\n"; //response to request
    }
    void off(){ //possible request
        std::cout << "Lights are turned off!\n";    //response to request
    }
};

class Doors {
public:
    void open(){    //possible request
        std::cout << "Doors are opened!\n"; //response to request
    }
    void close(){ //possible request
        std::cout << "Doors are closed!\n"; //response to request
    }
};



/**
 * all command objects implements same interface that describes how to perform action
 */
class Command {
public:
    virtual void execute() = 0;
};

/**
 * Concrete Commands
 * client creates concrete command and settings its receiver
 */
class LightOnCommand : public Command {
    Light* light;

public:
    LightOnCommand(Light* light);
    void execute() override;
};

class LightOffCommand : public Command {
    Light* light;

public:
    LightOffCommand(Light* light);
    void execute() override;    //performs action
};

class DoorsOpenCommand : public Command {
    Doors* doors;
public:
    DoorsOpenCommand(Doors* doors);
    void execute() override;
};

class DoorsCloseCommand : public Command {
    Doors* doors;
public:
    DoorsCloseCommand(Doors* doors);
    void execute() override;
};

/**
 * Invoker
 * class that serves as remote with different requests.
 *
 */
class SimpleRemoteControl {
    Command* slot;

public:
    SimpleRemoteControl(){}
    void setCommand(Command* command);  //concrete command as parameter
    void pressButton(); //perform execute() within concrete command
};


/**
 * METHOD DEFINITIONS
 */
LightOnCommand::LightOnCommand(Light* light){    //specific light is passes that this command will control
    this->light = light;
}

void LightOnCommand::execute() {
    this->light->on();
}

LightOffCommand::LightOffCommand(Light* light){
    this->light = light;
}

void LightOffCommand::execute(){
    this->light->off();
}

DoorsOpenCommand::DoorsOpenCommand(Doors* doors){
    this->doors = doors;
}

void DoorsOpenCommand::execute(){
    this->doors->open();
}

DoorsCloseCommand::DoorsCloseCommand(Doors* doors){
    this->doors = doors;
}

void DoorsCloseCommand::execute(){
    this->doors->close();
}

void SimpleRemoteControl::setCommand(Command* command){
    this->slot = command;
}
void SimpleRemoteControl::pressButton(){
    slot->execute();
}




/**
 * TEST CODE
 *
 *
 *
   Command* openDoors = new DoorsOpenCommand(new Doors());
   SimpleRemoteControl* remoter = new SimpleRemoteControl();
   remoter->setCommand(openDoors);
   remoter->pressButton();

   std::cout << "\n-------------------------------------------------------------------------------------\n";

    Command* lightsOn = new LightOnCommand(new Light());
   remoter->setCommand(lightsOn);
   remoter->pressButton();
    Command* lightsOff = new LightOffCommand(new Light());
   remoter->setCommand(lightsOff);
   remoter->pressButton();
  */
