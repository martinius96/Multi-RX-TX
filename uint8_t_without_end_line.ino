//LED 13 sa rozsvieti iba pri STATE 1
//Revízia: Martin Chlebovec (martinius96)
#include <stdint.h>
int pin_LED = 13;
const int buttonPin1 = 2;
int buttonState1 = HIGH;
int lastButtonState1 = HIGH;
unsigned long lastDebounceTime1 = 0;
unsigned long debounceInterval = 50;
int inByte = 0;
byte state = 0;
uint8_t a[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
uint8_t b[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
uint8_t c[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  Serial.begin(9600);
  establishContact();
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LOW);
}

void loop() {
  int reading1 = digitalRead(buttonPin1);
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }
  if ((millis() - lastDebounceTime1) > debounceInterval) {
    if (reading1 != buttonState1) {
      buttonState1 = reading1;
      if (buttonState1 == HIGH) {
        state++;
        if (state > 3) {
          state = 0;
        }
      }
    }
  }
  lastButtonState1 = reading1;
  if (state == 1) {
    digitalWrite(pin_LED, HIGH);
  } else {
    digitalWrite(pin_LED, LOW);
  }
  if (Serial.available() > 0) {
    inByte = Serial.read();
    delay(1);
    switch (state) {
      case 1:
        //PRE HODNOTU STATE 1
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        {
          Serial.print(a[i]);
        }
        break;
      case 2:
        //PRE HODNOTU STATE 2
        for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
        {
          Serial.print(b[i]);
        }
        break;
      case 3:
        //PRE HODNOTU STATE 3
        for (int i = 0; i < sizeof(c) / sizeof(c[0]); i++)
        {
          Serial.print(c[i]);
        }
        break;
      default:
        //PRE HODNOTU STATE 0 alebo inu
        Serial.print("STATE 0! BUFFER PRAZDNY");
        break;
    }
    delay(1000);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println(" SEND ME DATA ");
    delay(1000);
  }
}
