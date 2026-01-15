#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.println("+++++++++++++++++++++++++++++++++++ setup of empty2 here");
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  Serial.println("+++++++++++++++++++++++++++++++++++ loop of empty2 here");
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}