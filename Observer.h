//
// Created by Korisnik on 21/02/2019.
//

#ifndef DESIGNPATTERNS_OBSERVER_H
#define DESIGNPATTERNS_OBSERVER_H

#endif //DESIGNPATTERNS_OBSERVER_H
/**
 * INTERFACE DECLARATIONS
 */

/**
 * interface that observer uses to update their own state
 */
class IObserver{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

/**
 * interface that objects use to register as observer, remove from observer list
 * and to get notified
 */
class ISubject {
public:
    virtual void getRegister(IObserver* o) = 0;
    virtual void getRemove(IObserver* o) = 0;
    virtual void notifyObjects() = 0;
};

/**
 * interface that observers use to represent data
 */
class IDisplay{
    virtual void display() = 0;
};

class WeatherData : public ISubject {
    float temperature;
    float humidity;
    float pressure;
    std::vector<IObserver*> observers;  //list with observers

public:
    void getRegister(IObserver* o) override;
    void getRemove(IObserver* o) override;
    void notifyObjects() override;
    void setMeasurements(float temp, float humidity, float pressure);

protected:
    void measurementsChanged();
};

/**
 * 1. concrete observer
 * */
class CurrentObserver : public IObserver, public IDisplay {
    float temperature;
    float humidity;
    float pressure;
    ISubject* weatherData;
public:
    CurrentObserver(ISubject* wd);
    void display() override;
    void update(float temp, float humidity, float pressure) override;
};
/**
 * 2. concrete observer
 */
class StatisticsObserver : public IObserver, public IDisplay {
    float temperature;
    ISubject* weatherData;
public:
    StatisticsObserver(ISubject* wd);
    void display() override;
    void update(float temp, float humidity, float pressure) override;
};
/**
 * 3. concrete observer
 */
class ForecastObserver : public IObserver, public IDisplay {
    float humidity;
    float pressure;
    ISubject* weatherData;
public:
    ForecastObserver(ISubject* wd);
    void display() override;
    void update(float temp, float humidity, float pressure) override;
};





/**
 * FUNCTION DEFINITIONS
 */

/**
 * method that notifies ALL observers inside observer List
 * @return void
 */
void WeatherData::notifyObjects(){
    typename std::vector<IObserver*>::iterator p = observers.begin();
    for(p; p != observers.end(); ++p){  //update concrete observer state
        (*p)->update(this->temperature, this->humidity, this->pressure);
    }
}

/**
 * method that registers new user
 * @param object, Observer object
 * @return void
 * */
void WeatherData::getRegister(IObserver* o){
    observers.push_back(o);
}

/**
 * method that removes observer from subject
 * @param object, Observer object
 * @return void
 */
void WeatherData::getRemove(IObserver* o) {
    typename std::vector<IObserver*>::iterator p = observers.begin();
    p = std::find(p, observers.end(), o);
    observers.erase(p);
}

/**
 * method that notifies when state of subject changes
 * @return void
 */
void WeatherData::measurementsChanged() {
    this->notifyObjects();
}

/**
 * sets new subject state and notifies observers
 * @param float, degrees Celsius
 * @param float, amount of water vapour present in air
 * @param float
 * @return void
 */
void WeatherData::setMeasurements(float temp, float humidity, float pressure){
    this->temperature = temp;
    this->humidity = humidity;
    this->pressure = pressure;
    this->measurementsChanged();//state has changed (notify objects)
}

/**
 * constructor for the first observer
 * inserts user inside observer list
 * @param object, Subject object
 */
CurrentObserver::CurrentObserver(ISubject *wd){
    this->weatherData = wd;
    this->weatherData->getRegister(this);
}

/**
 * present weather informations
 * @return void
 */
void CurrentObserver::display(){
    std::cout << "Current window: \n";
    std::cout << "temperature = " << this->temperature << " °C\n";
    std::cout << "humidity = " << this->humidity << "\n";
    std::cout << "pressure = " << this->pressure << "\n";
}

/**
 * updates weather information and displays them
 * @param float
 * @param float
 * @param float
 * @return void
 */
void CurrentObserver::update(float temp, float humidity, float pressure){
    this->temperature = temp;
    this->humidity = humidity;
    this->pressure = pressure;
    this->display();
}

/**
 * constructor for the first observer
 * inserts user inside observer list
 * @param object, Subject object
 */
StatisticsObserver::StatisticsObserver(ISubject* wd){
    this->weatherData = wd;
    this->weatherData->getRegister(this);
}

/**
 * present weather information
 * @return void
 */
void StatisticsObserver::display(){
    std::cout << "Statistics window: \n";
    std::cout << "temperature = " << this->temperature << " °C\n";
}

/**
 * updates weather information and displays them
 * @param float
 * @param float
 * @param float
 * @return void
 */
void StatisticsObserver::update(float temp, float humidity, float pressure){
    this->temperature = temp;
    this->display();
}

/**
 * constructor for the second observer
 * inserts user inside observer list
 * @param object, Subject object
 */
ForecastObserver::ForecastObserver(ISubject* wd){
    this->weatherData = wd;
    this->weatherData->getRegister(this);
}

/**
 * present weather information
 * @return void
 */
void ForecastObserver::display(){
    std::cout << "Forecast window: \n";
    std::cout << "humidity = " << this->humidity << " °C\n";
    std::cout << "pressure = " << this->pressure << "\n";
}

/**
 * updates weather information and displays them
 * @param float
 * @param float
 * @param float
 * @return void
 */
void ForecastObserver::update(float temp, float humidity, float pressure){
    this->humidity = humidity;
    this->pressure = pressure;
    this->display();
}




