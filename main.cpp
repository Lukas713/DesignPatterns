#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <math.h>
#include <algorithm>

#include "Introduction.h"
#include "Builder.h"
#include "Strategy.h"
#include "Observer.h"
#include "Decorator.h"
#include "Command.h"
#include "Test.h"

int main() {

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

    remote->pressOnButton(0);
    remote->pressOffButton(0);
    remote->pressUndoButton(); 

    return 0;
}
