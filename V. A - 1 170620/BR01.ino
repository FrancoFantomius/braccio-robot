#include <Servo.h>;

Servo mx;
Servo my;

int ang_x=0;
int ang_y=0;
int ang_x_vecchio=ang_x;
int ang_y_vecchio=ang_y;

void setup()
{
    mx.attach(10);
    my.attach(13);
    Serial.begin(9600);
}

void loop()
{
    int n;
    int scelta=0;
    int fatto=0;
    if (Serial.available() > 0){
        n = Serial.parseInt();
        Serial.println(n);
        ang_x=n;
        ang_y=n;
        n=0;
    }
    if (ang_x > 180){
        ang_x=79;
    }
    if (ang_x_vecchio!=ang_x){
        mx.write(ang_x);
    }
    if (ang_y > 180){
        ang_y=79;
    }
    if (ang_y_vecchio!=ang_y){
        my.write(ang_y);
    }
    ang_x_vecchio=ang_x;
    ang_y_vecchio=ang_y;
    delay(1000);
}