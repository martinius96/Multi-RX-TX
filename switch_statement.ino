const int relay = 13; //D13 DIGITAL OUTPUT PIN
const int relay2 = 12; //D12 DIGITAL OUTPUT PIN
void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay, LOW); // turn relay off
  digitalWrite(relay2, LOW); // turn relay off
  while (Serial.available() <= 0) {
    Serial.println(" SEND ME DATA ");
    delay(1000);
  }
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    Serial.println();
    Serial.print("COMMAND FROM USER: ");
    Serial.print(value);
    Serial.println();
    switch (value) {
      case 1:
        digitalWrite(relay, HIGH); //turn on relay
        Serial.println("RELAY IS ON");
        delay(500);
        digitalWrite(relay, LOW); //turn off relay
        Serial.println("RELAY IS OFF");
        break;
      case 2:
        digitalWrite(relay2, HIGH); //turn on relay
        Serial.println("RELAY2 IS ON");
        delay(500);
        digitalWrite(relay2, LOW); //turn off relay
        Serial.println("RELAY2 IS OFF");
        break;
      case 3:
        digitalWrite(relay, HIGH); //turn on relay
        digitalWrite(relay2, HIGH); //turn on relay
        Serial.println("RELAYS ARE ON");
        break;
      case 4:
        digitalWrite(relay, LOW); //turn on relay
        digitalWrite(relay2, LOW); //turn on relay
        Serial.println("RELAYS ARE OFF");
        break;
      default :
        Serial.println("UNSUPPORTED COMMAND");
    }
  }
}
