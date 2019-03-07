#include "headers.h"

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
