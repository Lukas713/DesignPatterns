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
#include "Test.h"



int main() {

    IFlower* rose = new Rose();
    IFlower* redRose = new Red(rose);
    IFlower* redRedRose = new Red(redRose);
    IFlower* blueRedRedRose = new Blue(redRedRose);

    blueRedRedRose->str();


    return 0;
}