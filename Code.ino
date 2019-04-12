#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int pos = 175;


void setup() {
  
  Serial.begin(9600);
  servo6.attach(3);
  servo5.attach(5);
  servo4.attach(6);
  servo3.attach(9);
  servo2.attach(10);
  
}

void loop() {
  
  int sensorValue = analogRead(A0);
  int threshold = 100;
  int num;
  int flag;
 
  if(sensorValue > threshold)
  {
    
      servo5.write(50);
      servo6.write(50);
      servo4.write(50);
      servo3.write(50);
      servo2.write(50);
      if (sensorValue > 400) {
      servo5.write(pos);
      servo6.write(pos);
      servo4.write(pos);
      servo3.write(50);
      servo2.write(50);
      }
    else{
        
    }
  }
    
  
   
  else {
    servo5.write(pos);
      servo6.write(pos);
      servo4.write(pos);
      servo3.write(pos);
      servo2.write(pos);
      
  }
  
  Serial.println(sensorValue);
   
} 
