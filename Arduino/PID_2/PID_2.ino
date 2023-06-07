#include <PID_v1.h>

double Consigne;
double Entree;
double Sortie;
double Kp, Ki, Kd;

PID myPID(&Entree, &Sortie, &Consigne, Kp, Ki, Kd, DIRECT);

void setup()
{
  Consigne = map(analogRead(0), 0, 1023, 0, 255) + 15;

  Kp = (map(analogRead(1), 0, 1023, 1000, 0));
  Ki = (map(analogRead(2), 0, 1023, 1000, 0));
  Kd = (map(analogRead(3), 0, 1023, 1000, 0));

  Kp = Kp/100;
  Ki = Ki/100;
  Kd = Kd/100;

  myPID.SetTunings(Kp, Ki, Kd);  

  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Kp = (map(analogRead(1), 0, 1023, 1000, 0));
  Ki = (map(analogRead(2), 0, 1023, 1000, 0));
  Kd = (map(analogRead(3), 0, 1023, 1000, 0));

  Kp = Kp/100;
  Ki = Ki/100;
  Kd = Kd/100;

  myPID.SetTunings(Kp, Ki, Kd);  

  Entree = 255 - map(analogRead(0), 0, 1023, 0, 255);
  myPID.Compute();
  analogWrite(3,Sortie);
}