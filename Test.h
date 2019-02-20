//
// Created by Korisnik on 20/02/2019.
//

#ifndef DESIGNPATTERNS_TEST_H
#define DESIGNPATTERNS_TEST_H

#endif //DESIGNPATTERNS_TEST_H

enum strategy {ORDINARY, REAL};

class DiscriminantStrategy {
public:
    virtual double checkResult(double x) = 0;
};

class OrdinaryDiscriminant : public DiscriminantStrategy {
public:
    double checkResult(double x) override {
        std::cout << "Its ok";
        return x;
    }
};

class RealDiscriminant : public DiscriminantStrategy {
public:
    double checkResult(double x) override {
        if(x < 0){
            std::cout << "It's not ok!";
            return std::numeric_limits<double>::quiet_NaN();
        }
        return x;
    }
};

class QuadraticEquation {
    double a, b, c;
    double x;
    DiscriminantStrategy* ds;
public:
    void insertValues(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void choseStrategy(strategy s){
       switch (s){
            case REAL:
                this->ds = new RealDiscriminant();
                break;
            case ORDINARY:
                this->ds = new OrdinaryDiscriminant();
                break;
           default:
               break;
        }
    }
    void calculateX(){
        double result = (-(this->b) + sqrt((this->b * this->b) - 4 * this->a * this->c) / 2 * this->a);
        this->x = ds->checkResult(this->x);
        if(!this->x){
            std::cout << "\n" << this->x;
        }
    }

};

