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
    void methodOne(){
        std::cout << "First method on " << name << "\n";
    }
};

class ConcreteProductA : public Product {
public:
    ConcreteProductA(){
        this->name = "Concrete product A";
    }
};

class ConcreteProductB : public Product {
public:
    ConcreteProductB(){
        this->name = "Concrete product B";
    }
};

class ConcreteProductC : public Product {
public:
    ConcreteProductC(){
        this->name = "Concrete product C";
    }
};

class ConcreteProductD : public Product {
public:
    ConcreteProductD(){
        this->name = "Concrete product D";
    }
};

class ProductFactory {
public:
    Product* createFactory(PRODUCTS x){

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
};

class Creator {
    ProductFactory* factory;
public:
    Creator(ProductFactory* f){
        this->factory = f;
    }
    void orderFactory(PRODUCTS x){
        Product* product;
        product = this->factory->createFactory(x);
        product->methodOne();
    }
};