//
// Created by Korisnik on 25/02/2019.
//

#ifndef DESIGNPATTERNS_SIMPLEFACTORY_H
#define DESIGNPATTERNS_SIMPLEFACTORY_H

#endif //DESIGNPATTERNS_SIMPLEFACTORY_H

enum PRODUCTS {A, B, C, D};


class Product {
protected:
    std::string name;
public:
    void methodOne();
    virtual void methodTwo() = 0;
};

class ConcreteProductA : public Product {
public:
    ConcreteProductA();
    void methodTwo() override;
};

class ConcreteProductB : public Product {
public:
    ConcreteProductB();
    void methodTwo() override;
};

class ConcreteProductC : public Product {
public:
    ConcreteProductC();
    void methodTwo() override;
};

class ConcreteProductD : public Product {
public:
    ConcreteProductD();
    void methodTwo() override;
};

class ProductFactory {
public:
    static Product* createFactory(PRODUCTS x);  //static method that decides which Abstract implementation will be used
};

/**
 * Creator class that creates factory
 */
class Creator {
public:
    void orderFactory(PRODUCTS x);  //invokes static factory method
};


/**
 * #####################################
 * METHOD DEFINITIONS
 * #####################################
 */
void Creator::orderFactory(PRODUCTS x){
    Product* product = NULL;
    product = ProductFactory::createFactory(x);
    product->methodOne();
    product->methodTwo(); 
}
Product* ProductFactory::createFactory(PRODUCTS x){

    Product* product = NULL;
    switch(x){
        case A:
            product = new ConcreteProductA();
            break;
        case B:
            product = new ConcreteProductB();
            break;
        case C:
            product = new ConcreteProductC();
            break;
        case D:
            product = new ConcreteProductD();
            break;
        default:
            product = new ConcreteProductA();
            break;
    }
    return product;
}

ConcreteProductD::ConcreteProductD(){
    this->name = "Concrete product D";
}

void ConcreteProductD::methodTwo(){
    std::cout << "Second, overriden method on " << name << "\n";
    std::cout << "concrete product D\n";
}

ConcreteProductC::ConcreteProductC(){
    this->name = "Concrete product C";
}

void ConcreteProductC::methodTwo(){
    std::cout << "Second, overriden method on " << name << "\n";
    std::cout << "concrete product C\n";
}

ConcreteProductB::ConcreteProductB(){
    this->name = "Concrete product B";
}

void ConcreteProductB::methodTwo(){
    std::cout << "Second, overriden method on " << name << "\n";
    std::cout << "concrete product B\n";
}

ConcreteProductA::ConcreteProductA(){
    this->name = "Concrete product A";
}

void ConcreteProductA::methodTwo(){
    std::cout << "Second, overriden method on " << name << "\n";
    std::cout << "concrete product A\n";
}

void Product::methodOne(){
    std::cout << "First method on " << name << "\n";
}