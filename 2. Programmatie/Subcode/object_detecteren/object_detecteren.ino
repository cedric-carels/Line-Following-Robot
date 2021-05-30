/*object_detecteren*/
#include <Servo.h>
#define SERVO_PIN     9
#define Echo_PIN    2
#define Trig_PIN    10
 
int distanceThreshold = 0;
int cm = 0;

Servo head;

long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

/*RGB_led*/
int red_led= 5;
int green_led = 13;
int blue_led = 4;

void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  head.attach(SERVO_PIN); 
  head.write(30);
}

/*start of stop loop*/
void loop(){
  // set threshold distance to activate LEDs
  distanceThreshold = 20;
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(Trig_PIN, Echo_PIN);  
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  digitalWrite(blue_led,LOW);

  if (cm > distanceThreshold){
    digitalWrite(green_led,HIGH);
  }
  
  if (cm <= distanceThreshold - 0 && cm > distanceThreshold - 20){
    digitalWrite(red_led,HIGH);
  }
  delay(100); // Wait for 100 millisecond(s)
}
