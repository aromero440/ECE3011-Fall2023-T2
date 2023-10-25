#include "hardware.h"

// flash light

// speaker

// sensors
void initProxSensors() {
  // set all prox pins to INPUT
  pinMode(Prox_0,INPUT);
  pinMode(Prox_1,INPUT);
  pinMode(Prox_2,INPUT);
  pinMode(Prox_3,INPUT);
  pinMode(Prox_4,INPUT);
  pinMode(Prox_5,INPUT);
  pinMode(Prox_6,INPUT);
  pinMode(Prox_7,INPUT);
  pinMode(Prox_8,INPUT);
}

int currProxActive() {
  // intializing pin state variables
  int P0,P1,P2 = 0;
  int P3,P4,P5 = 0;
  int P6,P7,P8 = 0;

  // reading all prox sensor pins 
  P0 = digitalRead(Prox_0); 
  P1 = digitalRead(Prox_1); 
  P2 = analogRead(Prox_2); 
  P3 = analogRead(Prox_3); 
  P4 = digitalRead(Prox_4); 
  P5 = analogRead(Prox_5); 
  P6 = digitalRead(Prox_6); 
  P7 = analogRead(Prox_7); 
  P8 = digitalRead(Prox_8); 

  // for analog pins, convert to digital
  P2 = roundAnalogToDigital(P2);
  P3 = roundAnalogToDigital(P3);
  P5 = roundAnalogToDigital(P5);
  P7 = roundAnalogToDigital(P7);

  return (9 - P1 - P2 - P3 - P4 - P6 - P7 - P8 - 2); // P0 and P5 currently defective, when working add -P0, -P5
}

int roundAnalogToDigital(int analogVar){
  // convert analog voltage reading to digital
  if (analogVar > 514) {
    return 1;
  }
  else return 0;
}

// enter button
void enterButtonInit(){
  pinMode(ENTER_BUTTON,INPUT_PULLUP);
}

// cycle difficulties button
void cycleButtonInit(){
  pinMode(CYCLE_BUTTON,INPUT_PULLUP);
}