#include <Servo.h>
Servo myservo;
int pos=0;

int trigPin=11;
int echoPin=12;
long duration;
int cm;

int m_f=7;
int m_b=6;

void setup()
{
  myservo.attach(4);
  Serial.begin(9600);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(m_f,OUTPUT);
  pinMode(m_b,OUTPUT);
}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  pinMode(echoPin,INPUT);
  duration=pulseIn(echoPin,HIGH);
  cm=(duration/2)/28.1;
  Serial.print(cm);
  Serial.println();
  if(cm>=9)
  {
    digitalWrite(m_f,HIGH);
    digitalWrite(m_b,LOW);
    delay(5);
  }
  else
  {
    digitalWrite(m_f,LOW);
    digitalWrite(m_b,LOW);
    delay(5);
     for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
        } 
      for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
          delay(15);
  }
  
}
}