#include <Arduino.h>
#include "AwesomeSerial.h"

uint8_t ledArray[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledArray[i], OUTPUT);
  }
  Serial.begin(9600);
}

uint8_t ledStatus[8];

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
    int N;
    while (1) {
      if (Serial.available() == 1) {
        N = Serial.read();
        break;
      }
    }
    // Send O (means OK)
    Serial.print('O');
    while (1) {
      if (Serial.available() == N) {
        for (int i = 0; i < N; i++) {
          ledStatus[i] = Serial.read();
        }
        break;
      }
    }
    Serial.print('O');
    for (int i = 0; i < N; i++) {
      showLed(ledStatus[i]);
      delay(500);
    }
  }
}

void showLed(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    bool status = data >> i & 0b00000001;
    digitalWrite(ledArray[i], status);
  }
}
