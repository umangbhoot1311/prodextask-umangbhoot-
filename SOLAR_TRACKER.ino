#include <Servo.h>

Servo horizontal;
Servo vertical;
int hangle=90,vangle=90;
int threshold=50;

void setup(){
    horizontal.attach(10);
    vertical.attach(9);
    horizontal.write(hangle);
    vertical.write(vangle);
    Serial.begin(9600);
}

void loop(){
    int tl=analogRead(A0);
    int tr=analogRead(A1);
    int bl=analogRead(A2);
    int br=analogRead(A3);

    int left=(tl+bl)/2;
    int right=(tr+br)/2;
    int top=(tl+tr)/2;
    int bottom=(bl+br)/2;

    if(left-right>threshold){
        hangle--;
    }
    else if(right-left>threshold){
        hangle++;
    }

    if(top-bottom>threshold){
        vangle--;
    }
    else if(bottom-top>threshold){
        vangle++;
    }

    hangle=constrain(hangle,20,160);
    vangle=constrain(vangle,20,160);

    horizontal.write(hangle);
    vertical.write(vangle);

    Serial.print("TL: ");
    Serial.print(tl);
    Serial.print(" TR: ");
    Serial.print(tr);
    Serial.print(" BL: ");
    Serial.print(bl);
    Serial.print(" BR: ");
    Serial.print(br);
    Serial.print(" H: ");
    Serial.print(hangle);
    Serial.print(" V: ");
    Serial.println(vangle);

    delay(50);
}