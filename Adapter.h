//
// Created by lukas on 06.03.19..
//

#ifndef DESIGNPATTERNS_ADAPTER_H
#define DESIGNPATTERNS_ADAPTER_H

#endif //DESIGNPATTERNS_ADAPTER_H

class Duck {
public:
    virtual void fly() = 0;
    virtual void quack() = 0;
};

class MallardDuck : public Duck {
public:
    void fly() override {
        std::cout << "I'm flyng!\n";
    }
    void quack() override {
        std::cout << "Quack Quack!\n";
    }
};

class Turkey {
public:
    virtual void fly() = 0;
    virtual void gobble() = 0;
};


class FriedTurkey : public Turkey {
public:
    void fly() override {
        std::cout << "I'm barely fling!\n";
    }
    void gobble() override {
        std::cout << "Strange sound!\n";
    }
};

/**
 * user expects turkey, but we have only duck as response
 */
class TurkeyAdapter : public Duck { //extends duck
    Turkey* turkey; //implements turkey
public:
    TurkeyAdapter(Turkey* turkey){
        this->turkey = turkey;
    }
    void quack() override {
        this->turkey->gobble();
    }
    void fly() override {
        this->turkey->fly();
        this->turkey->fly();
    }
};