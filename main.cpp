#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Introduction.h"
#include "Builder.h"
#include "Strategy.h"


int main() {

    Context* a = new Context(new StrategyA);
    a->setStrategy(new StrategyB);

    a->algorithmAction();


    return 0;
}