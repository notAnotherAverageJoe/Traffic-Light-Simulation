#include "traffic_light.h"

int main()
{
    setNonBlockingInput(); // Set terminal to non-blocking mode
    trafficLightCycle();   // Start the traffic light cycle
    resetTerminal();       // Reset terminal settings before exiting
    return 0;
}