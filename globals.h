#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#ifndef GLOBALS_H
#define GLOBALS_H

#define DEBUG

/* Holds all the information for a problem*/
typedef struct _problem {
    int arg1;
    int operation;
    int arg2;
    int result;
} problem;

/**
 * @brief Describes which grade difficulty
 */
enum Grade
{
    Kindergarden, First, Second, Third, Init
};

#define ADDITION 0
#define SUBTRACTION 1
#define MULTIPLICATION 2
#define DIVISION 3

// Hardware globals

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1

// arduino pinout from PCB
#define ENTER_BUTTON 3 
#define CYCLE_BUTTON 2

#define MOTOR_PIN 5

#define Prox_0 8
#define Prox_1 7
#define Prox_2 A1
#define Prox_3 A2
#define Prox_4 13
#define Prox_5 A3
#define Prox_6 9
#define Prox_7 A0
#define Prox_8 4

#define SPEAKER_PIN 6

#endif // GLOBALS_H