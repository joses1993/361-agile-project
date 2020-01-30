#include <iostream>
#include "climate.h"

using namespace std;

int main()
{

    climate a;
    cout << "initial stats: ";
    a.printClimate();

    a.setHumidity(10.5);
    a.setFreezerTemp(20.8);
    a.setFridgeTemp(30.8);
    a.printClimate();

    return 0;
}
