#define sensor A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(map(analogRead(0), 0, 1024, 0, 255));
  delay(300);
}