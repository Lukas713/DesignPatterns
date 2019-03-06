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
#include "Adapter.h"
#include "Test.h"

int main() {

    MallardDuck* mallardDuck = new MallardDuck();
    mallardDuck->fly();
    mallardDuck->quack();

    FriedTurkey* friedTurkey = new FriedTurkey();
    friedTurkey->fly();
    friedTurkey->gobble();

    std::cout << "\n\n\n";
    Duck* turkeyAdapter = new TurkeyAdapter(friedTurkey);
    turkeyAdapter->quack();
    turkeyAdapter->fly();


    return 0;
}
