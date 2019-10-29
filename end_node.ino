#include <SoftwareSerial.h>

SoftwareSerial hwSerial_1(3, 4); // RX, TX
void setup() {
  // Zahájení komunikace pro:
  //  HW serial port pro propojení s PC
  Serial.begin(9600);
  //  HW Serial porty na daných pinech RX a TX
  hwSerial_1.begin(9600);
}

void loop() {
  while (hwSerial_1.available()) {
    // vytvoření proměnné pro uložení načteného znaku
    char c = hwSerial_1.read();
    Serial.write(c);
    //hwSerial_1.write(c);
  }
  while (Serial.available()) {
    // vytvoření proměnné pro uložení načteného znaku
    char d = Serial.read();
    hwSerial_1.write(d);
    //Serial.write(d);
  }
}
