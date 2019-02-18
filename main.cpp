#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Introduction.h"
#include "Builder.h"


int main() {

    Duck* a = new BigDuck();
    Duck* b = new SmallDuck();
    Duck* c = new MediumDuck();

    a->action();
    std::cout << '\n';
    b->action();
    std::cout << '\n';
    c->action();
    return 0;
}