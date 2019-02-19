//
// Created by Korisnik on 19/02/2019.
//

#ifndef DESIGNPATTERNS_STRATEGY_H
#define DESIGNPATTERNS_STRATEGY_H

#endif //DESIGNPATTERNS_STRATEGY_H


/**
 * interface that serves as Strategy
 */
class IStrategy {
public:
    virtual void algorithm() = 0;
};

/**
 * Strategy implementation A
 */
class StrategyA : public IStrategy {
public:
    void algorithm() override {
        std::cout << "Strategy A: Concrete A Strategy implementation";
    }
};
/**
 * Strategy implementation B
 */
class StrategyB : public IStrategy {
public:
    void algorithm() override {
        std::cout << "Strategy B: Concrete B Strategy implementation";
    }
};
/**
 * Strategy implementation C
 */
class StrategyC : public IStrategy {
public:
    void algorithm() override {
        std::cout << "Strategy C: Concrete C Strategy implementation";
    }
};
/**
 * Context class that holds reference to Strategy
 */
class Context {
protected:
    IStrategy* strategy;    //reference to interface
public:
    Context(){
        strategy = new StrategyA(); //sets implementation
    }
    Context(IStrategy* strategy){
        this->strategy = strategy;
    }
    void algorithmAction(){
        strategy->algorithm();  //method can be invoked because "Polymorphism"
    }
    void setStrategy(IStrategy* strategy){
        this->strategy = strategy;
    }
};