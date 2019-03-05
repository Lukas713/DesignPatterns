//
// Created by lukas on 05.03.19..
//

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

class TV {
public:
    void on(){
        std::cout << "TV is turned on!\n";
    }
    void off(){
        std::cout << "TV is turned off!\n";
    }
};

class Stereo {
public:
    void on(){
        std::cout << "Stereo is turned on!\n";
    }
    void off(){
        std::cout << "Stereo is turned off!\n";
    }
};



/**
 * all command objects implements same interface that describes how to perform action
 */
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string getClassName() = 0;
};

/**
 * Concrete Commands
 * client creates concrete command and settings its receiver
 */
 class NoCommand : public Command {
 public:
     void execute() override {}
     void undo() override {}
     std::string getClassName() override{
         return "NoCommand";
     }
 };

class LightOnCommand : public Command {
    Light* light;

public:
    LightOnCommand(Light* light);
    void execute() override;
    void undo() override {
        this->light->off();
    }
    std::string getClassName() override{
        return "LightOnCommand";
    }
};

class LightOffCommand : public Command {
    Light* light;

public:
    LightOffCommand(Light* light);
    void execute() override;    //performs action
    void undo() override {
        this->light->on();
    }
    std::string getClassName() override{
        return "LightOffCommand";
    }
};

class DoorsOpenCommand : public Command {
    Doors* doors;
public:
    DoorsOpenCommand(Doors* doors);
    void execute() override;
    void undo() override {
        this->doors->close();
    }
    std::string getClassName() override{
        return "DoorsOpenCommand";
    }
};

class DoorsCloseCommand : public Command {
    Doors* doors;
public:
    DoorsCloseCommand(Doors* doors);
    void execute() override;
    void undo() override {
        this->doors->open();
    }
    std::string getClassName() override{
        return "DoorsCloseCommand";
    }
};

class StereoOnCommand : public Command {
    Stereo* stereo;
public:
    StereoOnCommand(Stereo* stereo){
        this->stereo = stereo;
    }
    void execute() override {
        this->stereo->on();
    }
    void undo() override {
        this->stereo->off();
    }
    std::string getClassName() override{
        return "StereoOnCommand";
    }
};

class StereoOffCommand : public Command {
    Stereo* stereo;
public:
    StereoOffCommand(Stereo* stereo){
        this->stereo = stereo;
    }
    void execute() override {
        this->stereo->off();
    }
    void undo() override {
        this->stereo->on();
    }
    std::string getClassName() override{
        return "StereoOffCommand";
    }
};

class TVOnCommand : public Command {
    TV* tv;
public:
    TVOnCommand(TV* tv){
        this->tv = tv;
    }
    void execute() override {
        this->tv->on();
    }
    void undo() override {
        this->tv->off();
    }
    std::string getClassName() override{
        return "TVOnCommand";
    }
};

class TVOffCommand : public Command {
    TV* tv;
public:
    TVOffCommand(TV* tv){
        this->tv = tv;
    }
    void execute() override {
        this->tv->on();
    }
    void undo() override {
        this->tv->on();
    }
    std::string getClassName() override{
        return "TVOffCommand";
    }
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


class Invoker {
    int slots;
    std::vector<Command*> onButtons;
    std::vector<Command*> offButtons;
    Command* undoButton;

public:
    Invoker(int slots){
        this->slots = slots;
        this->onButtons = std::vector<Command*>(slots);
        this->offButtons = std::vector<Command*>(slots);

        for(int i=0; i<slots; ++i){
            onButtons[i] = new NoCommand();
            offButtons[i] = new NoCommand();
        }
        std::cout << "Buttons constructed!\n";
    }
    void setCommand(int slot, Command* onButton, Command* offButton){
        this->onButtons[slot] = onButton;
        this->offButtons[slot] = offButton;
    }
    void pressOnButton(int slot){
        this->onButtons[slot]->execute();
        this->undoButton = this->onButtons[slot];
    }
    void pressOffButton(int slot){
        this->offButtons[slot]->execute();
        this->undoButton = this->offButtons[slot];
    }
    void pressUndoButton() {
        this->undoButton->undo();
    }
    void displayRemoter(){
        for(int i=0; i<this->slots; ++i){
            std::cout << i << ": " << this->onButtons[i]->getClassName() << " - " << this->offButtons[i]->getClassName() << "\n";
        }
    }
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
    Command* lightOff = new LightOffCommand(new Light());
    Command* lightOn = new LightOnCommand(new Light());

    Command* musicOn = new StereoOnCommand(new Stereo());
    Command* musicOff = new StereoOffCommand(new Stereo());

    Command* tvOn = new TVOnCommand(new TV());
    Command* tvOff = new TVOffCommand(new TV());

    Command* doorsOpen = new DoorsOpenCommand(new Doors());
    Command* doorsClose = new DoorsCloseCommand(new Doors());

    Invoker* remote = new Invoker(4);

    remote->setCommand(0, lightOn, lightOff);
    remote->setCommand(1, musicOn, musicOff);
    remote->setCommand(2, tvOn, tvOff);
    remote->setCommand(3, doorsOpen, doorsClose);

    remote->displayRemoter();

    remote->pressOnButton(1);
    remote->pressOffButton(1);
  */
