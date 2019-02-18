//
// Created by Korisnik on 18/02/2019.
//

#ifndef DESIGNPATTERNS_ENCAPSULATEWHATVARIES_H
#define DESIGNPATTERNS_ENCAPSULATEWHATVARIES_H

#endif //DESIGNPATTERNS_ENCAPSULATEWHATVARIES_H

//method that varies in Base class
class FlyBehavior {
public:
    virtual void fly() = 0;
};
//variation one
class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        std::cout << "Fly with wings!";
    }
};
//variation two
class NoFly : public FlyBehavior {
public:
    void fly() override {
        std::cout << "I cant fly!";
    }
};

//program to an interface, not an implementation
class Duck {
protected:
    FlyBehavior* flyBehavior;   //delegates to fly behavior
public:
    void performFly(){
        flyBehavior->fly(); //performs flying
    }
};

class Mallard : public Duck {
public:
    Mallard(){
        this->flyBehavior = new FlyWithWings();
    }
};

class CantFlyDuck : public Duck{
public:
    CantFlyDuck(){
        this->flyBehavior = new NoFly();
    }
};