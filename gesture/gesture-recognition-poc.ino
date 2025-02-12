#include <Wire.h>
#include "paj7620.h"

// Gesture sensor address
#define GES_REACTION_TIME    500
#define GES_ENTRY_TIME      800
#define GES_QUIT_TIME       1000

void setup() {
  Serial.begin(9600);
  uint8_t error = paj7620Init();  // Initialize gesture sensor
  
  if (error) {
    Serial.print("Init error code: ");
    Serial.println(error);
  } else {
    Serial.println("Gesture sensor ready");
  }
}

void loop() {
  uint8_t data = 0;
  paj7620ReadReg(0x43, 1, &data);  // Read gesture data

  switch (data) {
    case GES_RIGHT_FLAG:
      Serial.println("Right");
      break;
    case GES_LEFT_FLAG:
      Serial.println("Left");
      break;
    case GES_UP_FLAG:
      Serial.println("Up");
      break;
    case GES_DOWN_FLAG:
      Serial.println("Down");
      break;
    case GES_FORWARD_FLAG:
      Serial.println("Forward");
      break;
    case GES_BACKWARD_FLAG:
      Serial.println("Backward");
      break;
    case GES_CLOCKWISE_FLAG:
      Serial.println("Clockwise");
      break;
    case GES_COUNT_CLOCKWISE_FLAG:
      Serial.println("Counter Clockwise");
      break;
    default:
      break;
  }
  delay(100);
}
