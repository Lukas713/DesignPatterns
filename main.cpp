#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <math.h>
#include <algorithm>

#include "Introduction.h"
#include "Builder.h"
#include "Strategy.h"
#include "Observer.h"
#include "Test.h"



int main() {

    WeatherData* wd = new WeatherData();
    wd->setMeasurements(12, 21, 41);

    IObserver* current = new CurrentObserver(wd);
    IObserver* forecase = new ForecastObserver(wd);
    IObserver* statistics = new StatisticsObserver(wd);
    wd->notifyObjects();



    return 0;
}