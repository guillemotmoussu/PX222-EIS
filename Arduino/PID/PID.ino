/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, REVERSE);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(0);
  Setpoint = 520;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  //Serial.begin(9600); // start the serial port
}

void loop()
{
  Input = analogRead(0);
  myPID.Compute();
  analogWrite(3,Output);
  //Serial.println(analogRead(0));
  //Serial.println(Output);
  //delay(100);
}