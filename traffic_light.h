#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

// Enum for traffic light states
typedef enum
{
    RED,
    GREEN,
    YELLOW
} TrafficLights;

extern TrafficLights currentState;
extern bool pedestrianCrossingButtonPressed;

// Function prototypes
void setNonBlockingInput(void);
void resetTerminal(void);
void handleRedLight(void);
void handleGreenLight(void);
void handleYellowLight(void);
void checkPedestrianButton(void);
void simulateButtonPress(void);
void trafficLightCycle(void);

#endif // TRAFFIC_LIGHT_H
