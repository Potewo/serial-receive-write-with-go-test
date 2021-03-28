#include <Arduino.h>

uint8_t ledArray[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledArray[i], OUTPUT);
  }
  Serial.begin(9600);
}

uint8_t ledStatus;

void showLed(uint8_t);

void loop() {
  char key = Serial.read();

  // Arduino: Send, PC: Receive
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

  // Arduino: Receive, PC: send
  if (key == 'S') {
    // Send O (means OK)
    Serial.print('R');
    while (1) {
      if (Serial.available()) {
        ledStatus = Serial.read() - '0';
        break;
      }
    }
    Serial.print('O');
    showLed(ledStatus);
  }
}

void showLed(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    bool status = data >> i & 0b00000001;
    digitalWrite(ledArray[i], status);
  }
}
