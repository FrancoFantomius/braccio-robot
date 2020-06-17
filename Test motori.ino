#include <Servo.h>;

Servo mx;

void setup() {
  mx.attach(13);
}

void loop() {
  mx.write(160);
  delay(1000);
  mx.write(0);
}
