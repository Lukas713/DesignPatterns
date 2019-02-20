#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <math.h>

#include "Introduction.h"
#include "Builder.h"
#include "Strategy.h"
#include "Test.h"


int main() {

    QuadraticEquation* a = new QuadraticEquation;
    a->choseStrategy(REAL);
    a->insertValues(0, 0, 0);
    a->calculateX();

    return 0;
}