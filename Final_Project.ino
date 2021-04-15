/*This is the sketch for the Final Project of CS 207
 * Named "AUTOMATIC HAND SANITIZER DOSPENSER"
 * DATE: APRIL 10,2021
 */




#include<Servo.h> // Adding Servo library
Servo servo1;
Servo servo2;
int echoPin =2; // Adding pin for Ultrasonic Sensor
int trigPin =3;
int buzzerPin =9;
double Time;
double Distance;


void setup()
{
  Serial.begin(9600); //Serial baud

  pinMode(echoPin,INPUT); //Setting digital pin for Ultrasoniic sensor as input
  pinMode(trigPin,OUTPUT); //Setting digital pin for Ultrasoniic sensor as output
  pinMode(buzzerPin,OUTPUT); //Setting digital pin for buzzer as output
  servo1.attach(4);  // Attatching pin for motor
  servo2.attach(5);
  servo1.write(0);  //Setting motor to initial position
  servo2.write(0);
  
  }

  void loop()
  {
    digitalWrite(trigPin,LOW); // disable the pin for sensor
    delayMicroseconds(1);
    digitalWrite(trigPin,HIGH); // ensable the pin for sensor
    delayMicroseconds(15);
    digitalWrite(trigPin,LOW);
    Time= pulseIn(echoPin,HIGH);
    Distance=(Time/2)/29.1; // the measured distance

     if(Distance<=15)
     {
      tone(buzzerPin,500);// buzzer will make sound in 500 Hz
      servo1.write(100); // turn servo motor to 100-degree
      servo2.write(100);
      delay(1000);
      servo1.write(0);
      servo2.write(0);
      }
      

      else
      { 
        servo1.write(0);
        servo2.write(0);
        noTone(buzzerPin);
        delay(1000);
        }

    }
