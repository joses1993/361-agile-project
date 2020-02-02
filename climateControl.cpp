#include "climateControl.h"

climateControl::climateControl()
{
    //ctor

    utcTime();
    std::ifstream checkCsv("currentClimate.csv");

    if(checkCsv.good())
    {
        cout << "Previous Data Found!" << endl;
    }
    else
    {
        std::ofstream csv("currentClimate.csv");

        cout << "No Previous Data Found" << endl;
        climateEntry newEntry(0.0,0.0,0.0, utcTime());
        saveClimateToFile( newEntry);

    }

}

void climateControl::saveClimateToFile(climateEntry entry)
{

    ofstream csv("currentClimate.csv");

    string data =  std::to_string(entry.getHumidity()) +
    "," + std::to_string(entry.getFreezer()) +
    "," + std:: to_string(entry.getFridge()) +
     "," + entry.getTime();

    csv << data;

}

//add this to seperate class so that can be used in other files.
string climateControl::timeNow()
{
    //referenced: https://www.youtube.com/watch?v=qXB5icpo0qY
    time_t now;
    struct tm nowLocal;

    now = time(NULL);
    nowLocal = *localtime(&now);
    string time = std::to_string(nowLocal.tm_hour) + ":" + std::to_string(nowLocal.tm_min) + ":" + std::to_string(nowLocal.tm_sec);
    cout << time << endl;

    return time;
}

string climateControl::utcTime()
{
    //referenced: https://www.youtube.com/watch?v=YjGrUVGKcgs
    time_t now;
    struct tm nowLocal;

    now = time(NULL);

    tm *gmtm = gmtime(&now);
    char* dt = asctime(gmtm);

    return dt;
}

climateEntry climateControl::getClimateFromFile()
{

    string humidtyStr, freezerStr, fridgeStr, time;
    double humidityDub, freezerDub, fridgeDub;
    ifstream csv("currentClimate.csv");

    if(csv.bad())
    {
        cout << "Error reading file" << endl;
    }

    string line;
     getline(csv, line);

     std::stringstream ss(line);
     vector<string> vect;

     while(ss.good())
     {
         string substr;
         getline(ss, substr, ',');
         vect.push_back(substr);
     }

    climateEntry newClimate(stod(vect[0]), stod(vect[1]), stod(vect[2]), vect[3]);

    return newClimate;
}

void climateControl::printClimate()
{
    climateEntry curr = getClimateFromFile();

    cout << "\n---Current Climate---" << endl;
    cout << "Humidity: " << curr.getHumidity() << endl;
    cout << "Freezer Temp: " << curr.getFreezer() << endl;
    cout << "Fridge Temp: " << curr.getFridge() << endl;
    cout << "Entry Date: " << curr.getTime() << endl;

}

void climateControl::setHumidity(double humidity)
{

    climateEntry current = getClimateFromFile();
    current.setHumidity(humidity);
    saveClimateToFile(current);

}

void climateControl::setFridge(double fridge)
{

    climateEntry current = getClimateFromFile();
    current.setFridge(fridge);
    saveClimateToFile(current);

}

void climateControl::setFreezer(double freezer)
{

    climateEntry current = getClimateFromFile();
    current.setFreezer(freezer);
    saveClimateToFile(current);

}

void climateControl::climateMenu()
{

    int y = 1;
    while(y)
    {
        int x;
        double humidity, freezer, fridge;
        cout << endl << endl;
        cout << "1. Get the current device climate" << endl;
        cout << "2. Change Humidity" << endl;
        cout << "3. Change Freezer Temperature" << endl;
        cout << "4. Change Fridge Temperature" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Selection: ";

        cin >> x;

        switch(x)
        {
            case 1:
                cout << endl;
                printClimate();
                break;

            case 2:
                cout << endl << "enter Humidity: " << endl;
                cin >> humidity;
                if(1)
                    setHumidity(humidity);
                break;


            case 3:
                cout << endl << "Enter Freezer Temperature: " << endl;
                cin >> freezer;
                setFreezer(freezer);
                break;

            case 4:
                cout << endl << "Enter Fridge Temperature: " << endl;
                cin >> fridge;
                setFridge(fridge);
                break;

            case 5:
                y = 0;
                break;
        }



    }

}
