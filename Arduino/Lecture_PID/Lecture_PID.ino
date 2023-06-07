float P, I, D;

void setup() {
  Serial.begin(9600);
}

void loop() {
  P = map(analogRead(1), 0, 1023, 1000, 0);
  I = map(analogRead(2), 0, 1023, 1000, 0);
  D = map(analogRead(3), 0, 1023, 1000, 0);
  Serial.println(P/100);
  Serial.println(I/100);
  Serial.println(D/100);
  delay(100);
}
