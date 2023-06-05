#define broche_pwm 3

void setup() {
  pinMode(broche_pwm, OUTPUT);
}

void loop() {
  int rapport_cyclique = 0;  
  while (rapport_cyclique <= 255)
  {
    analogWrite(broche_pwm, rapport_cyclique);
    rapport_cyclique += 10;
    delay(100);
  }
}