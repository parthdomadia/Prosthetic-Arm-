#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int pos = 175;


void setup() {
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  servo6.attach(3);
  servo5.attach(5);
  servo4.attach(6);
  servo3.attach(9);
  servo2.attach(10);
 

  
}

void loop() {
  
  int sensorValue = analogRead(A0);
  int threshold = 150;
  
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
   int c=0;
  c = millis();
  if(sensorValue > threshold)
  {
    if(sensorValue >= 300){
      int a = millis();
      if(sensorValue < 250){
      int e = a - c ;
      e = a/1000;
      Serial.println(e);
      switch (e) {
        case 1: 
        Serial.println("POWER GRIP");
        digitalWrite(2, HIGH);
          servo5.write(50);
          servo6.write(50);
          servo4.write(50);
          servo3.write(50);
          servo2.write(50);
          if(sensorValue > 400){
            break;
          }

        case 2:
        Serial.println("PINCH GRIP");
        digitalWrite(7, HIGH);
        servo5.write(pos);
        servo6.write(pos);
        servo4.write(pos);
        servo3.write(50);
        servo2.write(50);
        if(sensorValue > 400){
            break;
          }

        case 3:
        Serial.println("CUSTOMIZED");
        digitalWrite(8, HIGH);
         servo5.write(pos);
         servo6.write(50);
         servo4.write(50);
         servo3.write(50);
         servo2.write(pos);
        if(sensorValue > 400){
            break;
          }
          
        default: 
        Serial.println("START AGAIN");
        break;
      }
      c = a ;

      }
    }
      
  }
    
  
   
  else {
    servo5.write(pos);
      servo6.write(pos);
      servo4.write(pos);
      servo3.write(pos);
      servo2.write(pos);
      
  }
  

   
} 
