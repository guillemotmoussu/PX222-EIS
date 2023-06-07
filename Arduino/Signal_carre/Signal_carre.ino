void setup() {
  pinMode(3,OUTPUT);
}

void loop() {
  digitalWrite(3,0);
  delay(5000);
  digitalWrite(3,255);
  delay(5000);
}
