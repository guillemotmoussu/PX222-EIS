#include <PID_v1.h>

double Consigne;
double Entree;
double Sortie;
double Kp = 5, Ki = 1, Kd = 0;

PID myPID(&Entree, &Sortie, &Consigne, Kp, Ki, Kd, REVERSE);

void setup()
{
  Serial.begin(9600);

  Consigne = map(analogRead(0), 0, 1024, 0, 255);
  Serial.print(Consigne);
  delay(1000);

  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);  
}

void loop()
{
  Entree = map(analogRead(0), 0, 1024, 0, 255);
  myPID.Compute();
  analogWrite(3,Sortie);

  Serial.print(Entree);
  Serial.print(" ");
  Serial.println(Sortie);
  Serial.print(" ");  
  Serial.println(Consigne);
  //delay(50);
}