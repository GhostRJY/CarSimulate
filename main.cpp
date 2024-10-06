#include <iostream>
#include "AutoSim.h"

int main()
{

    Auto audiA6("Audi", "A6", "3.0 TDI", 3.0, "ZF", 6, "BBS", "Pirelli", 245, 50, 18);

    std::cout << audiA6;

    audiA6.turnOn();
    audiA6.startMoving();
    audiA6.stopMoving();
    audiA6.turnOff();

    return 0;
}
