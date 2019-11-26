//Author: Martin Chlebovec
const int relay = 13; //D13 DIGITAL OUTPUT PIN
void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW); // turn relay off
  while (Serial.available() <= 0) {
    Serial.println(" SEND ME DATA ");
    delay(1000);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String value = Serial.readStringUntil('\n');
    Serial.println();
    Serial.print("COMMAND VALUE FROM USER: ");
    Serial.print(value);
    Serial.println();
    digitalWrite(relay, HIGH); //turn on relay
    Serial.println("RELAY IS ON");
    delay(value.toInt());
    digitalWrite(relay, LOW); //turn off relay
    Serial.println("RELAY IS OFF");
  }
}
