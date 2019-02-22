//
// Created by Korisnik on 20/02/2019.
//

#ifndef DESIGNPATTERNS_TEST_H
#define DESIGNPATTERNS_TEST_H

#endif //DESIGNPATTERNS_TEST_H

class IFlower {
public:
    virtual void str() = 0;
};

class Rose : public IFlower {
public:
    void str() override {
        std::cout << "I am a Rose " ;
    }
};

class Color : public IFlower {
protected:
    IFlower* f;
};

class Red : public Color {
public:
    Red(IFlower*& f){
        this->f = f;
    }
    void str() override {
        f->str();
        std::cout << " that is red";
    }
};

class Blue : public Color {
public:
    Blue(IFlower*& f){
        this->f = f;
    }
    void str() override {
        f->str();
        std::cout << " that is blue";
    }
};
