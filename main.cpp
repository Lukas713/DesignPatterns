#include <iostream>
#include <string>

#include "EncapsulateWhatVaries.h"

int main() {

    Mallard* one = new Mallard();
    one->performFly();

    std::cout << '\n';

    CantFlyDuck* two = new CantFlyDuck();
    two->performFly();
    return 0;
}