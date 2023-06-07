#include <PID_v1.h>

double Consigne;
double Entree;
double Sortie;
double Kp = 0.8, Ki = 5, Kd = 3;

PID myPID(&Entree, &Sortie, &Consigne, Kp, Ki, Kd, DIRECT);

void setup()
{
  //Serial.begin(9600);

  Consigne = map(analogRead(0), 0, 1023, 0, 255) + 15;

  Serial.println();
  Serial.println(Kp);
  Serial.println(Ki);
  Serial.println(Kd);

  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);  
}

void loop()
{
  Entree = 255 - map(analogRead(0), 0, 1023, 0, 255);
  myPID.Compute();
  analogWrite(3,Sortie);

  //Serial.println(Entree);
  //Serial.print(" ");
  //Serial.println(Consigne);
  //Serial.println(" ");
  //delay(100);
}