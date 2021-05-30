/*object_detecteren*/
#include <Servo.h>                //ophalen van de Servo bibliotheek
#define SERVO_PIN 9               //Servo Pin connectie met D9
#define Echo_PIN 2                // Ultrasonic Echo Pin connective met D2
#define Trig_PIN 10               // Ultrasonic Trig Pin connective met D10
 
int distanceThreshold = 0;        //waarde van de afstand bij start meting
int cm = 0;                       //omzetting naar cm
Servo head;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);    // TriggerPin wordt gereset
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);          //TriggerPin wordt 10 microsec. op HOOG gezet
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); 
  return pulseIn(echoPin, HIGH);  //leest de EchoPin en geeft de reistijd van de geluidsgolf weer in microsec.
}
