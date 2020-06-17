#include <Servo.h>;

Servo mx;
Servo mx1;
/*Servo my;
Servo my1;*/

int ang_x=0;
int ang_x_1=0;
int ang_y=0;
int ang_y_1=0;
int scelta=0;
int n=0;
int fatto=0;
int vecchion=n;

void setup()
{
    /*Servomotori*/
    mx.attach(13);
    mx1.attach(10);
    /*my.attach(7);
    my1.attach(5);*/
    Serial.begin(9600);
}


void loop()
{
    //PARTE DI COMUNICAZIONE COLL'UTENTE
    if (Serial.available() > 0){
        n = Serial.parseInt();
    }
    if (scelta==0){
        if (n!=vecchion){
            if (fatto!=1){
                ang_x=n;
                scelta=0;
                fatto=1;
                Serial.println(n);
            }
        }
    }/*
    if (scelta==1){
        if (n!=vecchion){
            if (fatto!=1){
                ang_y=n/2;
                ang_y_1=n;
                scelta=0;
                fatto=1;
                Serial.println(n);
            }
        }
    }*/
    //EFFETUAZIONE DELLA DECISIONE DELL'UTENTE
    if (ang_x>=180){
        /*↓↓↓↓↓↓↓↓↓↓↓↓↓ Quando ang_x ha più gradi di quanti mx ne possa compiere, questo si distribuisce anche nel secondo motore (mx_1)*/
        if (ang_x<258){
            ang_x_1 = ang_x-179;
            ang_x = ang_x - ang_x_1;
        }
        if (ang_x>258)
        {
            ang_x=0;
        }
        
    }
    if (ang_y>=180){
        ang_y=10;
    }
    if (ang_y_1>=180){
        ang_y_1=20;
    }
    mx.write(ang_x);
    mx1.write(ang_x_1);/*
    my.write(ang_y);
    my1.write(ang_y_1);*/
    delay(1000);
    Serial.println("ESEGUITO");
    fatto=0;
    vecchion=n;
}