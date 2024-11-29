#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include "traffic_light.h"

// Traffic light states
TrafficLights currentState = RED;
bool pedestrianCrossingButtonPressed = false;

// Function to set terminal to non-blocking mode
void setNonBlockingInput()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON; // disable canonicale mode (input not buffered)
    term.c_lflag &= ~ECHO;   // disable the echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // set to non-blocking mode
}

// Function to reset terminal to blocking mode
void resetTerminal()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON; // enable canonicale mode (input is buffered)
    term.c_lflag |= ECHO;   // enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void handleRedLight()
{
    printf("RED Light ON -> 🔴\n");
    sleep(30);
    currentState = GREEN;
}

void handleGreenLight()
{
    printf("GREEN Light ON -> 🟢\n");
    sleep(30);
    currentState = YELLOW;
}

void handleYellowLight()
{
    printf("YELLOW Light ON -> 🟡\n");
    sleep(6);
    currentState = RED;
}

void checkPedestrianButton()
{
    if (pedestrianCrossingButtonPressed)
    {
        printf("\nPedestrian button PRESSED!🏃‍♂️🏃‍♀️ Waiting for transition to RED light -> 🔴 🚗🚙🚕\n");
        pedestrianCrossingButtonPressed = false;
        currentState = RED;
    }
}

// this allows for a non-blocking check for crossings
void simulateButtonPress()
{
    char input = 0; // Initialize input as zero
    if (read(STDIN_FILENO, &input, 1) == 1)
    { // Read one character, non-blocking
        if (input == 'p')
        {
            pedestrianCrossingButtonPressed = true;
        }
    }
}

void trafficLightCycle()
{
    while (1)
    {
        simulateButtonPress(); // Continuously check for button press

        switch (currentState)
        {
        case RED:
            handleRedLight();
            break;
        case GREEN:
            handleGreenLight();
            break;
        case YELLOW:
            handleYellowLight();
            break;
        }

        // Check if pedestrian button was pressed during this cycle
        checkPedestrianButton();
    }
}