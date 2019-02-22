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

    Coffe* coffee = new Coffe();
    Cream* creamOne = new Cream(coffee);
    Cream* creamTwo = new Cream(creamOne);
    Chocolate* chocolate = new Chocolate(creamTwo);
    std::cout << "Price of coffee with double cream = " << chocolate->cost() << " €";


    return 0;
}