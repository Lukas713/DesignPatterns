//
// Created by Korisnik on 22/02/2019.
//

#ifndef DESIGNPATTERNS_DECORATOR_H
#define DESIGNPATTERNS_DECORATOR_H

#endif //DESIGNPATTERNS_DECORATOR_H

/**
 * Component interface
 */
class IBeverage {
public:
    virtual double cost() = 0;
};

/**
 * Decorator that is the same type as super class.
 * Decorator HAS A component component's interface
 */
class Condiments : public IBeverage {
protected:
    IBeverage* beverage;
};

/**
 * Concrete component implementations
 */
class Coffe : public IBeverage {
public:
    double cost() override;
};

class Cacao : public IBeverage {
public:
    double cost() override;
};

/**
 * Concrete decorators
 */
class Cream : public Condiments {
public:
    Cream(IBeverage* beverage); //decorates object
    double cost() override;
};

class Chocolate : public Condiments {
public:
    Chocolate(IBeverage* beverage);
    double cost() override;
};


/**
 * ##########################################################
 * FUNCTION DEFINITIONS
 * ##########################################################
 */
/**
 * Coffee cost
 * @return double
 * @override
 */
double Coffe::cost(){
    return 1.00;
}

/**
 * Cacao cost
 * @return double
 * @override
 */
double Cacao::cost(){
    return 1.50;
}

/**
 * @param object, beverage object
 */
Cream::Cream(IBeverage *beverage) {
    this->beverage = beverage;
}

/**
 * returns own price plus price of drink that is decorated
 * @return double
 */
double Cream::cost() {
    return this->beverage->cost() + 0.50;
}

/**
 * @param object, beverage object that will be decorated
 */
Chocolate::Chocolate(IBeverage *beverage) {
    this->beverage = beverage;
}

/**
 * returns own price plus price of drink that is decorated
 * @return double
 */
double Chocolate::cost() {
    return this->beverage->cost() + 0.80;
}


