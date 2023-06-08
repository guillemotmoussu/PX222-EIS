#include <PID_v1.h>

double Consigne;
double Entree;
double Sortie;
double Kp, Ki, Kd;

PID myPID(&Entree, &Sortie, &Consigne, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(9600);
  Consigne = map(analogRead(0), 0, 1023, 0, 255) + 15;

  Kp = (map(analogRead(1), 0, 1023, 5000, 0));
  Ki = (map(analogRead(2), 0, 1023, 2000, 0));
  Kd = (map(analogRead(3), 0, 1023, 5000, 0));

  Kp = Kp/1000;
  Ki = Ki/1000;
  Kd = Kd/1000;

  myPID.SetTunings(Kp, Ki, Kd);  

  myPID.SetMode(AUTOMATIC);

  Serial.println(Kp);
  Serial.println(Ki);
  Serial.println(Kd);
}

void loop()
{
  Kp = (map(analogRead(1), 0, 1023, 5000, 0));
  Ki = (map(analogRead(2), 0, 1023, 1000, 0));
  Kd = (map(analogRead(3), 0, 1023, 5000, 0));

  Kp = Kp/1000;
  Ki = Ki/10;
  Kd = Kd/1000;

  myPID.SetTunings(Kp, Ki, Kd);  

  Entree = 255 - map(analogRead(0), 0, 1023, 0, 255);
  myPID.Compute();
  analogWrite(3,Sortie);
}