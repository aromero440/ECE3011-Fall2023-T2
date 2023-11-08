#include "genProblem.h"
#include "hardware.h"
#include "globals.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Grade currGrade;
Servo myservo;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Serial...");

  screenInit();

  enterButtonInit();
  cycleButtonInit();

  initProxSensors();

  myservo.attach(MOTOR_PIN);
  myservo.write(0);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2); 
  display.setCursor(0,0);
  display.println(F("Select a\nGrade"));
  display.display();

  currGrade = Init;
}

void loop() {
  int cycleButtonState = digitalRead(CYCLE_BUTTON);
  if (cycleButtonState == 0) { // Cycle the grade
    currGrade = cycleGrade(currGrade);
    Serial.println(currGradeToString(currGrade));
    displayGrade();
    delay (200);
  } else if (currGrade != Init) { // A grade is already selected
    problem p = generateProblem(currGrade); 
    displayProblem(p);
    Serial.println(probToString(p));
    int enterButtonState = 1;

    int pos = 0; // start position of motor
    while ((enterButtonState == 1 || cycleButtonState == 0) && pos <= 180) { // Wait until user selects enter or out of time
      myservo.write(pos);
      //Serial.println(pos);
      pos += 1;
      delay(100);

      cycleButtonState = digitalRead(CYCLE_BUTTON);
      if (cycleButtonState == 0) { // if changed grade during a problem
        myservo.write(0);
        currGrade = cycleGrade(currGrade);
        displayGrade();
        Serial.println(currGradeToString(currGrade));
        delay(250);
        goto Skip;
      }
      enterButtonState = digitalRead(ENTER_BUTTON);
    } 

    if (p.result != currProxActive()) { // Was the user correct?
      wrongProb();
    } else {
      correctProb();
    }
    Serial.println(currProxActive());
    
    Skip: delay(250);
    // reset motor to pos 0
    myservo.write(0);
  }
}

// Display functions declared here due to scope issues ----------------------
void screenInit() {
  // Display init
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Set display settings
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);  
  display.setTextSize(1); 
  display.setCursor(0,0);
}

void displayProblem(problem prob) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(3); 
    display.setCursor(0,0);
    String message = probToString(prob);
    display.println(message);
    display.display();
}

void displayGrade() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2); 
  display.setCursor(0,0);
  String message = currGradeToString(currGrade);
  display.println(message);
  display.display();
}

void correctProb() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2); 
  display.setCursor(0,0);
  String message = "Correct\nAnswer :)";
  Serial.println("Correct Answer :(");
  display.println(message);
  display.display();
  soundCorrect(SPEAKER_PIN);
}

void wrongProb() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2); 
  display.setCursor(0,0);
  String message = "Wrong\nAnswer :(";
  Serial.println("Wrong Answer :(");
  display.println(message);
  display.display();
  soundIncorrect(SPEAKER_PIN);
}


