void setup() {
 Serial.begin(115200);
 Serial.println("Connected!");

  Serial.print("Init: ");
  for (int s = 0; s <= 3; s++) {
    pinMode(s, INPUT);
    Serial.print(s);
    Serial.print("\t");
  }
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  
}

void loop() {
  for (int s = 0; s <= 3; s++) {
    int reading = analogRead(s);
    Serial.print(s);
    Serial.print(": ");
    Serial.print(reading);
    Serial.print("\t");
    delay(10);
  }
  Serial.print("\n");
  delay(500);
}
