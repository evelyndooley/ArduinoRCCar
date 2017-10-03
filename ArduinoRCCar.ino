/*
  
  Controls a DC motor to power the car and a servo to adjust the steering rack.
  
  How to use:
  
    * Connect joystick shield to your Arduino
    * Upload this sketch to your Arduino
    * Open the Arduino IDE Serial Monitor (set to 9600 baud)
    * Waggle joystick, push buttons, and the motors move
  
  Requires:
  
    * Arduino
    * SparkFun Joystick Shield
    * DC motor controller on pin 9, servo on pin 10

  Based on original example by Ryan Owens

 */


// Store the Arduino pin associated with each input
const byte PIN_BUTTON_SELECT = 2; // Select button is triggered when joystick is pressed

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 4;
const byte PIN_BUTTON_DOWN = 5;
const byte PIN_BUTTON_LEFT = 6;

const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;
int serVal = 0;
int serVal2 = 0;
int serVal3 = 0;
#include <Servo.h>
Servo myservo;
Servo myservo2;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  myservo.attach(10);
  myservo2.attach(9);
}


void loop() {

  //servo now
  serVal = map(analogRead(PIN_ANALOG_X), 0, 1023, 0, 180);
  myservo.write(serVal);
  serVal2 = map(analogRead(PIN_ANALOG_Y), 0, 1023, -255, 255);
  Serial.println(serVal2);
  if(serVal2 > -12 && serVal2 < -9){;
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    analogWrite(9, 0);
    Serial.println(0);
  }
  else if(serVal2 > -8) {
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    myservo2.write(serVal2);
  }
  else if(serVal2 < -13){
    serVal3 = -serVal2;
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    myservo2.write(serVal3);
  }
}

