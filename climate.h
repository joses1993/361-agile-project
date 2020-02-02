#ifndef CLIMATE_H
#define CLIMATE_H

#include <iostream>
#include <string>
#include <fstream>


/* Do file validation on setters*/

class climate
{
    public:
        climate();

        double getHumidity();
        double getFreezerTemp();
        double getFridgeTemp();

        void setHumidity(double);
        void setFreezerTemp(double);
        void setFridgeTemp(double);

        //humidty, freezer, fridge
        void writeFile(double, double, double);
        double readFile(std::ifstream&, int);

        //couts humidity and temps in formated text.
        void printClimate();

        virtual ~climate();

    private:

        bool checkFile();

        //could be helpful with future case where we want to show users a
        //summary/dashboard of their fridge. log with timestamp and temps.
        //could be added to cron job to repeatedly log this.
        void writeToLog();




};

#endif // CLIMATE_H
