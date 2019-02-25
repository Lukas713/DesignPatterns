//
// Created by Korisnik on 25/02/2019.
//

#ifndef DESIGNPATTERNS_SIMPLEFACTORY_H
#define DESIGNPATTERNS_SIMPLEFACTORY_H

#endif //DESIGNPATTERNS_SIMPLEFACTORY_H

enum PIZZA {MEXICANA, VEGGIE, CAPRICCIOSA};

/**
 * Product that is produced inside PizzaStore
 */
class Pizza {
protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> ingredients;
public:
    void prepare();
    void bake();
    void cut();
    void box();
};

/**
 * Concrete products - all pizzas that are produced by stores
 */
class NYMexicana : public Pizza {
public:
    NYMexicana();
};

class NYVeggie : public Pizza {
public:
    NYVeggie();
};

class NYCapricciosa : public Pizza {
public:
    NYCapricciosa();
};

class LAMexicana : public Pizza {
public:
    LAMexicana();
};

class LAVeggie : public Pizza {
public:
    LAVeggie();
};

class LACapricciosa : public Pizza {
public:
    LACapricciosa();
};

/**
 * Creator classes - abstract class that ONLY defines method that factories use to produce products!
 */
class PizzaStore {
public:
    void orderPizza(PIZZA a);

protected:
    virtual Pizza* createPizza(PIZZA a) = 0;    //factory method that encapsulates knowledge about making proper object
};
/**
 * Concrete factories
 */
class NYPizzaStore : public PizzaStore {
protected:
    Pizza* createPizza(PIZZA a) override;
};

class LAPizzaStore : public PizzaStore {
protected:
    Pizza* createPizza(PIZZA a) override;
};



/**
 * ###################################
 *          METHOD DEFINITIONS
 * ###################################
 */
void Pizza::prepare(){
    std::cout << "Preparing " << name << "\n";
    std::cout << "Tossing dough..." << "\n";
    std::cout << "Adding sauce..." << "\n";
    std::vector<std::string>::iterator p = ingredients.begin();
    std::cout << "Adding ingredients: " ;
    for(p; p != ingredients.end(); ++p){
        std::cout << (*p) << ", ";
    }
    std::cout << "\n";
}
void Pizza::bake(){
    std::cout << "Baking " << name << "\n";
}
void Pizza::cut(){
    std::cout << "Cutting "  << "\n";
}
void Pizza::box(){
    std::cout << "Boxing " << "\n";
}

NYMexicana::NYMexicana() {
    this->name = "NYStyle Mexicana pizza";
    this->dough = "Thin crust dough";
    this->sauce = "Hot ketchup";
    ingredients.push_back("Onion");
    ingredients.push_back("Pepper");
    ingredients.push_back("Salami");
    ingredients.push_back("Cheese");
}

NYVeggie::NYVeggie() {
    this->name = "NYStyle Veggie pizza";
    this->dough = "Fat crust dough";
    this->sauce = "Slight ketchup";
    ingredients.push_back("Cheese");
    ingredients.push_back("Pepper");
    ingredients.push_back("Oregano");
    ingredients.push_back("Onion");
}

NYCapricciosa::NYCapricciosa() {
    this->name = "NYStyle Capricciosa pizza";
    this->dough = "Fat crust dough";
    this->sauce = "Hot ketchup and";
    ingredients.push_back("Cheese");
    ingredients.push_back("Salami");
    ingredients.push_back("Oregano");
}

LAMexicana::LAMexicana() {
    this->name = "LAStyle Mexicana pizza\n";
    this->dough = "Fat crust dough\n";
    this->sauce = "Hot ketchup\n";
    ingredients.push_back("Onion");
    ingredients.push_back("Pepper");
    ingredients.push_back("Salami");
    ingredients.push_back("Cheese");
}

LAVeggie::LAVeggie() {
    this->name = "LAStyle Veggie pizza\n";
    this->dough = "Fat crust dough\n";
    this->sauce = "Hot ketchup\n";
    ingredients.push_back("Cheese");
    ingredients.push_back("Pepper");
    ingredients.push_back("Oregano");
    ingredients.push_back("Onion");
}

LACapricciosa::LACapricciosa() {
    this->name = "LAStyle Capricciosa pizza";
    this->dough = "Thin crust dough";
    this->sauce = "Slight ketchup and";
    ingredients.push_back("Cheese");
    ingredients.push_back("Salami");
    ingredients.push_back("Oregano");
}

void PizzaStore::orderPizza(PIZZA a){
    std::cout << "Pizza is ordered!\n";
    this->createPizza(a);
}

Pizza* NYPizzaStore::createPizza(PIZZA a){
    Pizza* pizza = NULL;

    switch(a){
        case MEXICANA:
            pizza = new NYMexicana();
        break;
        case CAPRICCIOSA:
            pizza = new NYCapricciosa();
        break;
        case VEGGIE:
            pizza = new NYVeggie();
        break;
        default:
            pizza = new NYCapricciosa();
        break;
    }
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}
/**
 * encapsulates all the knowledge about how to make LA style pizza
 * @param object, concrete Product object
 * @return object, concrete Product object
 */
Pizza* LAPizzaStore::createPizza(PIZZA a){
    Pizza* pizza = NULL;
    switch(a){
        case MEXICANA:
            pizza = new LAMexicana();
        break;
        case CAPRICCIOSA:
            pizza = new LACapricciosa();
        break;
        case VEGGIE:
            pizza = new LAVeggie();
        break;
        default:
            pizza = new LACapricciosa();
        break;
    }
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}



