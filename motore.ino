#include <Servo.h>;

Servo mx;

void setup()
{
    mx.attach(13);
}

void loop()
{
    mx.write(130);
    delay(4000);
    mx.write(100);
}