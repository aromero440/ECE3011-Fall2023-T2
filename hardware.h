/*  Responsible for handling all interactions with hardware.
    This includes: light, speaker, screen, and sensors */

#include "globals.h"

#ifndef HARDWARE_H
#define HARDWARE_H 

// flash light

// speaker
void soundCorrect(int speaker);

void soundIncorrect(int speaker);

// sensors
void initProxSensors();

int currProxActive();

int roundAnalogToDigital(int analogVar);

// enter button
void enterButtonInit();

// cycle difficulties button
void cycleButtonInit();

#endif