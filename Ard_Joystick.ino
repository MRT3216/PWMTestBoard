#include <Servo.h>

Servo servo; //Allows arduino to send PWM outputs easily
// Arduino pin numbers
const int joystick_pin = 0; // analog in pin connected to joystick VRx or VRy
const int signal_out_pin = 5; // digital output pin (PWM~)
int val;

void setup() {
  servo.attach(signal_out_pin);             // Output PWM signal
  //Serial.begin(19200);                      // Begins Logging on 19200 baud (Uncomment for debugging)
  //Serial.println("Ready");                  // Prints to Serial Monitor
}

void loop() {
  val = analogRead(joystick_pin);            // reads the value of the joytsick (value between 0 and 1023)
  //Serial.print("Unscaled Value: \n");
  //Serial.print(String(val));
  //Serial.print("\n");
  val = map(val, 0, 1023, 0, 180);           // scale joystick input to use it with the servo (value between 0 and 180)
  //Serial.print("Scaled Value: \n");
  //Serial.print(val);
  //Serial.print("\n");
  servo.write(val);                          // sets the PWM output according to the scaled value
  delay(15);                                 // delay to slow the loop() (15 for normal operations : 100 for debugging/logging)
}
