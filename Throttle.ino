/**
 * NOTE
 * If you change this file, don't forget to change usb pid in the boards file
 */

#include <Joystick.h>

Joystick_ Joystick;

int THROTTLE = 0;

#define maxThrottle 660
#define minThrottle 400

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Joystick.begin(false);


  // Set "joystick" to center
  Joystick.setXAxisRange(0, 2);
  Joystick.setXAxis(1);

  Joystick.setYAxisRange(0, 2);
  Joystick.setYAxis(1);
  
  Joystick.setThrottleRange(minThrottle, maxThrottle);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(0));

  int currThrottle = analogRead(THROTTLE);

  Joystick.setThrottle(currThrottle);
  Joystick.sendState();
}
