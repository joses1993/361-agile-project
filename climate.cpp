#include "climate.h"
#include <iostream>

using namespace std;

climate::climate()
{
    //ctor
    fridgeTemp = 21;
    humidity = 0;
    freezerTemp = 34;
}

climate::~climate()
{
    //dtor
}



double climate::getFreezerTemp()
{
    return freezerTemp;
}


double climate::getFridgeTemp()
{
    return fridgeTemp;
}

double climate::getHumidity()
{
    return humidity;
}

void climate::setFreezerTemp(double x)
{
    //do some input validation here.
    freezerTemp = x;
}

void climate::setFridgeTemp(double x)
{
    fridgeTemp = x;
}

void climate::setHumidity(double x)
{
    humidity = x;
}

void climate::printClimate()
{
    std::cout << "Current climate of your fridge is: " << endl;
    cout << "Humidity: " << getHumidity() << endl;
    cout << "Freezer Temp: " << getFreezerTemp() << endl;
    cout << "Fridge Temp: " << getFridgeTemp() << endl;
}
