
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <unistd.h>

// Define the GPIO pin numbers
#define DATA_PIN 17      // GPIO 17 (physical pin 11)
#define CMD_PIN 14       // GPIO 14 (physical pin 8)
#define SELECT_PIN 15    // GPIO 15 (physical pin 10)
#define CLOCK_PIN 18     // GPIO 18 (physical pin 12)

void setupPins() {
    // Set up the WiringPi library
    if (wiringPiSetupGpio() == -1) {
        printf("Error setting up WiringPi\n");
        exit(1);
    }

    // Set the pins as input
    pinMode(DATA_PIN, INPUT);
    pinMode(CMD_PIN, INPUT);
    pinMode(SELECT_PIN, INPUT);
    pinMode(CLOCK_PIN, INPUT);

    // Enable pull-up resistors (optional if needed)
    pullUpDnControl(DATA_PIN, PUD_UP);
    pullUpDnControl(CMD_PIN, PUD_UP);
    pullUpDnControl(SELECT_PIN, PUD_UP);
    pullUpDnControl(CLOCK_PIN, PUD_UP);
}

void readPins() {
    while (1) {
        // Read the state of each pin
        int dataState = digitalRead(DATA_PIN);
        int cmdState = digitalRead(CMD_PIN);
        int selectState = digitalRead(SELECT_PIN);
        int clockState = digitalRead(CLOCK_PIN);

        // Print the pin states
        printf("DATA_PIN: %d, CMD_PIN: %d, SELECT_PIN: %d, CLOCK_PIN: %d\n",
               dataState, cmdState, selectState, clockState);

        // Delay for a short while to avoid overwhelming output
        usleep(100000); // 100 ms delay
    }
}

int main() {
    // Set up the pins
    setupPins();

    // Read the pin states continuously
    readPins();

    return 0;
}
