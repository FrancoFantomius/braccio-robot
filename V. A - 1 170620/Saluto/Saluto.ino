#include <Servo.h>;

Servo mx;
Servo my;

int ang_x=0;
int ang_y=0;
int ang_x_vecchio=ang_x;
int ang_y_vecchio=ang_y;
int parte=0;

void setup()
{
    mx.attach(10);
    my.attach(13);
}

void loop()
{
    int fatto=0;
    if (parte==0){
        ang_x=75;
        parte=1;
        fatto=1;
    }
    if (parte==1){
        if (fatto==0){
        ang_y=105;
        fatto=1;
        parte=2;
        }
    }
    if (parte==2){
        if (fatto==0){
        ang_y=175;
        parte=1;
        }
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
    delay(2000);
}