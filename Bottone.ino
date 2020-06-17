#include <Servo.h>;

Servo mx;

int ang_x=0;
int ang_x_1=0;
int ang_y=0;

void setup() {
 
  Serial.begin(9600);

}

int scelta=0;

void loop() {
    if (scelta==0){
        Serial.println("ARDUINO CONNESSO");
        Serial.println("Digita di quanti gradi devono girare i motori");
        scelta=1;
    }
    else if (scelta==1)
    {
        if (n!=0){
            ang_x=n;
            scelta=2;
        }
    }
    else if (scelta==2)
    {
        ang_y=n;
        scelta=1;
    }
    
    if (Serial.available() > 0){ //Controlliamo se ci sono dati da leggere
        int n;
        n = Serial.parseInt(); //Legge il numero
        Serial.println(n);
    if (ang_x>=180){
        if (ang_x<258){
            ang_x_1 = ang_x-179;
            ang_x = ang_x - ang_x_1;
        }
        else if (ang_x>258)
        {
            ang_x=0;
            ang_x_1=0
        }
            
    }
    if (ang_y>=180){
        ang_y=10;
    }
    }
}
    /*char carattere;
    if (Serial.available() > 0){ //Controlliamo se ci sono dati da leggere
        carattere = Serial.read(); //Leggiamo un carattere
        if (carattere != '\n'){ //Se il carattere non è l'invio
            Serial.print("ARDUINO: ");
            Serial.println(carattere); //Lo scriviamo indietro
        }
        elif (carattere == 'q'){
            Serial.print("90°→")
        }
    }*/
}