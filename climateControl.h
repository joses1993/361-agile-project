#ifndef CLIMATECONTROL_H
#define CLIMATECONTROL_H

#include "climateEntry.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <typeinfo>
#include <vector>

using namespace std;

//this file is going to create climateEntrys and
//read and write them to a static csv file used for climate that 1 entry.
//It will also write to a climate log file that will keep writing.
//
//maybe just use last entry from logging file?

class climateControl
{
    public:
        climateControl();

        void printClimate();
        void setHumidity(double);
        void setFreezer(double);
        void setFridge(double);
        void climateMenu();

    private:
        string timeNow();
        string dateNow();
        string utcTime();
        void setClimate(climateEntry);
        void writeClimateLog(ofstream&, climateEntry);
        void saveClimateToFile(climateEntry);
        climateEntry getClimateFromFile();
};

#endif // CLIMATECONTROL_H
