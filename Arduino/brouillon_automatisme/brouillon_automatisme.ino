#define consigne 450
#define sensor A0
#define sortie 3

void setup() {
  // put your setup code here, to run once:
  pinMode(sortie, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(sensor) > 500) {analogWrite(sortie, 255);}
  if (analogRead(sensor) < 400) {analogWrite(sortie, 0);}
  Serial.println(analogRead(sensor));
  delay(50);
}
