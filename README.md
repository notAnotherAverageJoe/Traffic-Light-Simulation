# 🚦 Traffic Light Simulation with Pedestrian Crossing 🚦

Welcome to the Traffic Light Simulation project! This program simulates a basic traffic light system, complete with a pedestrian crossing button, allowing for interactive, real-time control. The system is designed to run continuously, handle non-blocking input, and simulate real-world scenarios in an efficient and non-intrusive manner. 💡

## 🌟 Key Features:

Traffic Light Simulation: Simulates a traffic light cycle with RED, GREEN, and YELLOW lights.
Pedestrian Crossing: Allows pedestrians to press a button to request crossing, which transitions the traffic light to RED.
Non-Blocking Input: The program continuously checks for user input (button press) without interrupting the traffic light cycle.
Interactive Console: A real-time simulation with the ability to simulate the button press at any time, using non-blocking input.

## 🚀 How It Works:

🟥 Traffic Light Cycle
The traffic light system operates in a continuous cycle, transitioning from RED → GREEN → YELLOW and back to RED. Here’s how the cycle functions:

#### RED Light: The system stays in RED for 30 seconds, signaling vehicles to stop.

#### GREEN Light: The system switches to GREEN for 30 seconds, signaling vehicles to go.

#### YELLOW Light: The system briefly switches to YELLOW for 6 seconds, signaling vehicles to slow down and prepare to stop.

## 🚶‍♂️ Pedestrian Crossing

When the pedestrian button is pressed (simulated by user input), the traffic light system will transition to RED to allow pedestrians to cross. The button press is checked at the end of every cycle without blocking the flow of the system.

## ⏳ Non-Blocking Input

To handle the pedestrian button press without pausing the entire system, the program uses non-blocking input. This ensures the traffic light cycle continues running smoothly while constantly listening for user input.

## 💻 How to Run the Project:

🛠 Prerequisites:
GCC (GNU Compiler Collection)
Linux/macOS terminal for non-blocking I/O functionality.
Ensure you have GCC installed. If not, you can install it using:

bash
Copy code
sudo apt-get install build-essential
⚙️ Steps to Build & Run:
Clone the repository or download the project files.
Open your terminal and navigate to the project folder.
Build the project using make:
bash
Copy code
make
Run the program:
bash
Copy code
./traffic_light
📚 Code Explanation:
🛠 Terminal Configuration: Non-Blocking Input
We use terminal configuration techniques to ensure the program doesn't block the flow of execution when waiting for user input.
c
Copy code
void setNonBlockingInput()
{
struct termios term;
tcgetattr(STDIN_FILENO, &term);
term.c_lflag &= ~ICANON; // Disable canonical mode
term.c_lflag &= ~ECHO; // Disable echo (don't show typed characters)
tcsetattr(STDIN_FILENO, TCSANOW, &term);
fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // Set non-blocking mode
}
Key Concepts:
Canonical Mode: In canonical mode, the terminal waits for the user to press Enter before submitting input. We disable this mode to allow immediate input processing.
Echo: By disabling echo, typed characters are not shown on the terminal screen, making the input process more discreet.
Non-Blocking Mode: This ensures the program checks for input without blocking or waiting. If no input is available, the program continues execution.
🚦 Traffic Light Cycle
The traffic light system uses three functions to handle the different states of the traffic lights:

handleRedLight(): Simulates the RED light for 30 seconds.
handleGreenLight(): Simulates the GREEN light for 30 seconds.
handleYellowLight(): Simulates the YELLOW light for 6 seconds.
These functions are called in a loop to simulate the continuous cycle of the traffic light.

🟢 Handling Pedestrian Crossing Button
The pedestrian crossing functionality is handled by the function handlePedestrianCrossing():

c
Copy code
void handlePedestrianCrossing()
{
if (pedestrianCrossingButtonPressed)
{
printf("Pedestrian button has been PRESSED! Please wait for light to transition to RED\n\n");
pedestrianCrossingButtonPressed = false;
currentState = RED;
};
}
If the pedestrian button is pressed (detected through non-blocking input), the traffic light will immediately transition to RED.

🔄 Main Loop
The main loop continuously cycles through the traffic light states while listening for button presses:

c
Copy code
while (1)
{
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

    simulateButtonPress();  // Check for user input without blocking

}
The program checks for input after each cycle and adjusts the state based on whether the pedestrian button was pressed.

## 🛠 Project Structure:

main.c: The main entry point of the program, where the loop runs and the traffic light cycle is controlled.
traffic_light.c: Contains the logic for handling the traffic light states, pedestrian crossing, and input simulation.
traffic_light.h: The header file that defines the traffic light states and function declarations.

## 💡 Conclusion:

This project demonstrates how to handle real-time, interactive simulations with non-blocking input in C. It provides a great foundation for embedded systems programming, traffic control, and understanding terminal handling for non-blocking input.

## 🤖 Skills Demonstrated:

Embedded System Simulation using C
Real-time Programming with non-blocking input
Terminal Input Handling (non-blocking and echo management)
Finite State Machines for the traffic light logic
System Design for interactive programs
