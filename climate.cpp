#include "climate.h"
#include <iostream>
#include <string>

using namespace std;

climate::climate()
{
    //init climateConfig if does not already exist.
    if(!checkFile())
        writeFile(0,0,0);
}

climate::~climate()
{
    //dtor
}


double climate::getFreezerTemp()
{
    //return fridge temp;
    string fileFreezer;
    ifstream h("climateConfig.txt");

    if(h)
    {
        //done twice to access second line in file.
        h >> fileFreezer;
        h >> fileFreezer;
    }

    double x = stod(fileFreezer);
    return x;
}

double climate::getFridgeTemp()
{
    //return fridge temp;
    string fileFridge;
    ifstream h("climateConfig.txt");

    if(h)
    {
        //done thrice to access 3rd line in file.
        h >> fileFridge;
        h >> fileFridge;
        h >> fileFridge;
    }

    double x = stod(fileFridge);
    return x;
}

double climate::getHumidity()
{
    //return humidity;
    string fileHumidity;
    ifstream h("climateConfig.txt");

    if(h)
        h >> fileHumidity;

    double x = stod(fileHumidity);
    return x;
}

void climate::setFreezerTemp(double x)
{

    writeFile(getHumidity(), x, getFridgeTemp());
}

void climate::setFridgeTemp(double x)
{
    writeFile(getHumidity(), getFreezerTemp(), x);
}

void climate::setHumidity(double x)
{
    writeFile(x, getFreezerTemp(), getFridgeTemp());
}

void climate::printClimate()
{
    std::cout << "Current climate of your fridge is: " << endl;
    cout << "Humidity: " << getHumidity() << endl;
    cout << "Freezer Temp: " << getFreezerTemp() << endl;
    cout << "Fridge Temp: " << getFridgeTemp() << endl;
}

bool climate::checkFile()
{
    ifstream file("climateConfig.txt");

    return file.good();
}

void climate::writeFile(double hum, double freezer, double fridge)
{
        ofstream outFile("climateConfig.txt");

        outFile << hum << endl;
        outFile << freezer << endl;
        outFile << fridge << endl;
}
