/**
 * NOTE
 * If you change this file, don't forget to change usb pid in the boards file
 */

#include <Joystick.h>

Joystick_ Joystick;

#define PITCH 2
#define ROLL 3

#define TRIGGER 0
#define TRIM 1

#define SW_1 1
#define SW_2 0
#define SW_3 3
#define SW_4 2

#define BTN_1 6
#define BTN_2 5
#define BTN_3 4
#define BTN_4 7

#define MIN_ROLL 765
#define MAX_ROLL 275

#define MIN_PITCH 250
#define MAX_PITCH 710

#define MIN_TRIGGER 587
#define MAX_TRIGGER 852

#define MIN_TRIM 0
#define MAX_TRIM 1023

void setup() {
  // put your setup code here, to run once:

  pinMode(SW_1, INPUT_PULLUP);
  pinMode(SW_2, INPUT_PULLUP);
  pinMode(SW_3, INPUT_PULLUP);
  pinMode(SW_4, INPUT_PULLUP);
  
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);
  
  Joystick.setXAxisRange(MIN_ROLL, MAX_ROLL);
  Joystick.setYAxisRange(MIN_PITCH, MAX_PITCH);
  Joystick.setZAxisRange(MIN_TRIM, MAX_TRIM);
  Joystick.setRzAxisRange(MIN_TRIGGER, MAX_TRIGGER);
  
  Joystick.begin(false);
}



void loop() {
  Joystick.setXAxis(analogRead(ROLL));
  Joystick.setYAxis(analogRead(PITCH));
  
  Joystick.setZAxis(analogRead(TRIM));
  Joystick.setRzAxis(analogRead(TRIGGER));
  
  Joystick.setButton(0, digitalRead(SW_1));
  Joystick.setButton(1, digitalRead(SW_2));
  Joystick.setButton(2, digitalRead(SW_3));
  Joystick.setButton(3, digitalRead(SW_4));
  
  Joystick.setButton(4, !digitalRead(BTN_1));
  Joystick.setButton(5, !digitalRead(BTN_2));
  Joystick.setButton(6, !digitalRead(BTN_3));
  Joystick.setButton(7, !digitalRead(BTN_4));

  Joystick.sendState();
}
