


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
      Serial.println(" sensors working");
      delay(1000);
      
      }
      

      else
      { 
        Serial.println("the distance larger");
        noTone(buzzerPin);
        delay(1000);
        }

    }
