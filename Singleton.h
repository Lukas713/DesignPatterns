//
// Created by Korisnik on 26/02/2019.
//

#ifndef DESIGNPATTERNS_SINGLETON_H
#define DESIGNPATTERNS_SINGLETON_H

#endif //DESIGNPATTERNS_SINGLETON_H

/**
 * Singleton class
 */
class ChocolateBoiler {
    bool empty;
    bool boiled;

    ChocolateBoiler();
public:
    static ChocolateBoiler* getInstance();
    bool isEmpty();
    bool isBoiled();
    void draing();
    void boil();
    void fill();
};

/**
 * ##############################################
 * FUNCTION DEFINITIONS
 * ##############################################
 */
 /**
  * private constructor (accessible only with static getInstance())
  */
 ChocolateBoiler::ChocolateBoiler(){
    empty = true;
    boiled = false;
}

/**
 * static method that ensures only one object within application
 */
ChocolateBoiler* ChocolateBoiler::getInstance(){
    static ChocolateBoiler* object;
    if(object == NULL){
        std::cout << "Boiler constructed!\n";
        object = new ChocolateBoiler();
    }
    return object;
}

/**
 * methods that uses ONE and ONLY one object
 */
bool ChocolateBoiler::isEmpty(){
    ChocolateBoiler* object = ChocolateBoiler::getInstance();
    return object->empty;
}

bool ChocolateBoiler::isBoiled(){
    ChocolateBoiler* object = ChocolateBoiler::getInstance();
    return object->boiled;
}

void ChocolateBoiler::draing(){
    ChocolateBoiler* object = ChocolateBoiler::getInstance();
    if(!object->isEmpty() && object->isBoiled()){
        std::cout << "Drained!\n";
        object->empty = true;
        return;
    }
    std::cout << "You cant do that\n";
}

void ChocolateBoiler::boil(){
    ChocolateBoiler* object = ChocolateBoiler::getInstance();
    if(!object->isEmpty() && !object->isBoiled()){
        std::cout << "Boiled!\n";
        object->boiled = true;
        return;
    }
    std::cout << "You cant do that\n";
}

void ChocolateBoiler::fill(){
    ChocolateBoiler* object = ChocolateBoiler::getInstance();
    if(object->isEmpty()){
        std::cout << "Filled!\n";
        object->empty = false;
        object->boiled = false;
        return;
    }
    std::cout << "You cant do that\n";
}
/**
 * TEST CODE

    ChocolateBoiler* boiler = ChocolateBoiler::getInstance();   //constructed
    boiler->fill();     //filled
    boiler->boil();     //boiled
    boiler->draing();   //drained

    ChocolateBoiler* boiler2 = ChocolateBoiler::getInstance();  //
    boiler2->fill();    //filled
    boiler2->boil();    //boiled
    boiler2->draing();  //drained
 */

