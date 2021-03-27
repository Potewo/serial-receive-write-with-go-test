#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = Serial.read();
  if (key == 'R') {
    Serial.print("hello\n");
    while (true) {
      if (Serial.available()) {
        char OK = Serial.read();
        if (OK == 'O') {
          break;
        }
      }
    }
  }
}
