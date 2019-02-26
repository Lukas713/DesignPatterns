//
// Created by Korisnik on 26/02/2019.
//

#ifndef DESIGNPATTERNS_ABSTRACTFACTORY_H
#define DESIGNPATTERNS_ABSTRACTFACTORY_H

#endif //DESIGNPATTERNS_ABSTRACTFACTORY_H

/**
 * Abstract products
 */
class Castle {
public:
   virtual void getDescription() = 0;
};

class King {
public:
    virtual void getDescription() = 0;
};

class Army {
public:
    virtual void getDescription() = 0;
};

/**
 * Concrete implementation of abstract products.
 * Creating family of dependent objects.
 */
class OrcCastle : public Castle {
public:
    void getDescription() override;
};

class OrcKing : public King {
public:
    void getDescription() override;
};

class OrcArmy : public Army {
public:
    void getDescription() override;
};

class HumanCastle : public Castle {
public:
    void getDescription() override;
};

class HumanKing : public King {
public:
    void getDescription() override;
};

class HumanArmy : public Army {
public:
    void getDescription() override;
};

/**
 * Abstract Factory that defines interface for creating objects
 */
class AbstractFactory {
public:
    virtual Castle* createCastle() = 0;
    virtual King* createKing() = 0;
    virtual Army* createArmy() = 0;
};
/**
 * Concrete factory that creates objects
 */
class OrcFactory : public AbstractFactory {
public:
    Castle* createCastle() override;
    King* createKing() override;
    Army* createArmy() override;
};

class HumanFactory : public AbstractFactory {
public:
    Castle* createCastle() override;
    King* createKing() override;
    Army* createArmy() override;
};




/**
 * ###########################################
 * FUNCTION DEFINITIONS
 * ###########################################
 */

 /**
  * Orcs
  */
 void OrcCastle::getDescription() {
    std::cout << "Castle of Orcs!\n";
 }

void OrcKing::getDescription() {
    std::cout << "KING of Orcs!\n";
}

void OrcArmy::getDescription() {
    std::cout << "Army of Orcs!\n";
}
/**
 * Humans
 */
void HumanCastle::getDescription() {
    std::cout << "Castle of Humans!\n";
}

void HumanKing::getDescription() {
    std::cout << "KING of Humans!\n";
}

void HumanArmy::getDescription() {
    std::cout << "Army of Humans!\n";
}

/**
 * Concrete Factories
 */

/**
 * Orcs
 */
King* OrcFactory::createKing() {
    return new OrcKing();
}

Castle* OrcFactory::createCastle() {
    return new OrcCastle();
}

Army* OrcFactory::createArmy() {
    return new OrcArmy();
}

/**
 * Humans
 */
King* HumanFactory::createKing() {
    return new HumanKing();
}

Castle* HumanFactory::createCastle() {
    return new HumanCastle();
}

Army* HumanFactory::createArmy() {
    return new HumanArmy();
}

/**
 * TEST CODE:
 *
    AbstractFactory* orcFactory = new OrcFactory();
    AbstractFactory* humanFactory = new HumanFactory();

    Castle* orcCastle = orcFactory->createCastle();
    Army* orcArmy = orcFactory->createArmy();
    King* orcKing = orcFactory->createKing();

    Castle* humanCastle = humanFactory->createCastle();
    Army* humanArmy = humanFactory->createArmy();
    King* humanKing = humanFactory->createKing();

    orcKing->getDescription();
    orcCastle->getDescription();
    orcArmy->getDescription();

    std::cout << "-------------------------------------------------------------------------------------------\n";

    humanArmy->getDescription();
    humanCastle->getDescription();
    humanKing->getDescription();
 *
 * */