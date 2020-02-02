#ifndef CLIMATEENTRY_H
#define CLIMATEENTRY_H

#include <time.h>
#include <string>
using std::string;

class climateEntry
{
    public:

        climateEntry(){};
        climateEntry(double h, double freeze, double fridge, string t){

            setHumidity(h);
            setFreezer(freeze);
            setFridge(fridge);
            setTime(t);
            //setDate(d);
        };

        void setHumidity(double h){humidity = h;};
        void setFreezer(double freeze){freezerTemp = freeze;}
        void setFridge(double fridge){fridgeTemp = fridge;}
        void setTime(string t){time = t;}
        //void setDate(string d){date = d;}

        double getHumidity() {return humidity;}
        double getFreezer() {return freezerTemp;}
        double getFridge() {return fridgeTemp;}
        string getTime(){return time;}
        //string getDate(){return date;}

    private:

        double humidity;
        double freezerTemp;
        double fridgeTemp;
        string time;
//        string date;
};

#endif // CLIMATEENTRY_H
