//
// Created by Korisnik on 18/02/2019.
//

#ifndef DESIGNPATTERNS_INTRODUCTION_H
#define DESIGNPATTERNS_INTRODUCTION_H

#endif //DESIGNPATTERNS_INTRODUCTION_H

/**
 * interface, abstract supertype
 */
class FlyAbility {
public:
    virtual void fly() = 0;
};

/**
 * implementation of the interface
 */
class Flyer : public FlyAbility {
public:
    void fly() override{
        std::cout << "I'm flying!";
    }
};

/**
 * implementation of the interface
 */
class AntiFlyer : public FlyAbility {
public:
    void fly() override {
        std::cout << "I cant fly!";
    }
};

/**
 * interface
 */
class SoundAbility {
public:
    virtual void makeSound() = 0;
};

/**
 * implementations of the interface
 */
class BigQuackers : public SoundAbility {
public:
    void makeSound() override {
        std::cout << "big QUACK big QUACK big QUACK";
    }
};
class SmallQuackers : public SoundAbility {
public:
    void makeSound() override {
        std::cout << "small QUACK small QUACK small QUACK";
    }
};
class MediumQuackers : public SoundAbility {
public:
    void makeSound() override {
        std::cout << "medium QUACK medium QUACK medium QUACK";
    }
};





class Duck {
protected:
    FlyAbility* fa; //supertype
    SoundAbility* sa;
public:
    void action() {
        fa->fly();
        sa->makeSound();
    }
};

class BigDuck : public Duck {
public:
    BigDuck(){
        fa = new Flyer(); //class doesnt care which object is this
        sa = new BigQuackers();
    }
};

class SmallDuck : public Duck {
public:
    SmallDuck() {
        fa = new AntiFlyer();
        sa = new SmallQuackers();
    }
};

class MediumDuck : public Duck {
public:
    MediumDuck(){
        fa = new Flyer();
        sa = new MediumQuackers();
    }
};
