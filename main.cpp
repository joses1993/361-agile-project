#include <iostream>
#include "climate.h"

using namespace std;

int main()
{

    climate a;
    a.printClimate();


    a.setFridgeTemp(59.8);
    a.printClimate();
    return 0;
}
