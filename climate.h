#ifndef CLIMATE_H
#define CLIMATE_H

/* Do file validation on setters*/

class climate
{
    public:
        climate();

        //currently are just using local variables
        //should use file io to write this to a file so
        //that it is static.
        double getHumidity();
        double getFreezerTemp();
        double getFridgeTemp();

        void setHumidity(double);
        void setFreezerTemp(double);
        void setFridgeTemp(double);

        //could be helpful with future case where we want to show users a
        //summary/dashboard of their fridge. log with timestamp and temps.
        //could be added to cron job to repeatedly log this.
        void writeToLog();

        //couts humidity and temps in formated text.
        void printClimate();

        virtual ~climate();

    private:
        double humidity;
        double freezerTemp;
        double fridgeTemp;


};

#endif // CLIMATE_H
