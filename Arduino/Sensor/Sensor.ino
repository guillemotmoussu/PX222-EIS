#define sensor A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  float volts = analogRead(sensor)*0.0048828125;
  int distance = 13*pow(volts, -1);
  if (distance <= 30){
    Serial.println(distance);
  }
  delay(300);
}