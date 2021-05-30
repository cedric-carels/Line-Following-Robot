#include "02_RGB.h"
#include "03_Tracking_sensor.h"
#include "04_Motor.h"
#include "05_extra.h"

void setup() {     
  /*RGB*/
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  /*Motor*/
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
 
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT);  
  stop_Stop();          //stop move

  /*button*/
  pinMode (button, INPUT);
}

void auto_tracking(){
  /*tracking sensor*/
  String sensorval= read_sensor_values();

  /*button*/
  button = digitalRead(1);

  /*witte lijn*/
  if (sensorval=="00000"){
    stop_Stop();
    set_Motorspeed(0,0);   //motorsnelheid instellen
    if (button ==LOW){
    stop_Stop();
    set_Motorspeed(0,0);   //motorsnelheid instellen
    digitalWrite (blue_led,HIGH);   // blauw led
    }
    if (button == HIGH){
      go_Advance();
      set_Motorspeed(SLOW_SPEED,SLOW_SPEED);   //motorsnelheid instellen
      digitalWrite(green_led,HIGH); // groen led
    }
  }

  /*Vooruit*/
  if (sensorval=="11011"){
    go_Advance();
    set_Motorspeed(SLOW_SPEED,SLOW_SPEED);   //motorsnelheid instellen
    digitalWrite(green_led,HIGH); // groen led    
  }
  
  /*Sla linksaf*/
  if (sensorval=="01111"){
    go_Left();
    set_Motorspeed(FAST_SPEED,FAST_SPEED);   //motorsnelheid instellen
    digitalWrite(green_led,HIGH); // groen led    
  }
  
  /*Flauwe bocht naar links*/
  if (sensorval=="01011"  || sensorval=="10111" || sensorval=="10011" || sensorval=="00011"  || sensorval=="01101" || sensorval=="00101"){
    go_Advance();
    set_Motorspeed(0,FAST_SPEED);   //motorsnelheid instellen
    digitalWrite(green_led,HIGH); // groen led
  }
  
  /*Sla rechtsaf*/
  if (sensorval=="11110"){
    go_Right();
    set_Motorspeed(FAST_SPEED,FAST_SPEED);   //motorsnelheid instellen
    digitalWrite(green_led,HIGH); // groen led
  }
  
  /*Flauwe bocht naar rechts*/
  if (sensorval=="11100" || sensorval=="11101"  || sensorval=="11010" || sensorval=="11001" || sensorval=="11000" || sensorval=="10010" || sensorval=="10000"   || sensorval=="10100"  || sensorval=="10110"){
    go_Advance();
    set_Motorspeed(FAST_SPEED,0);   //motorsnelheid instellen
    digitalWrite(green_led,HIGH); // groen led
  }  
  
  /*spoor verloren*/
  if (sensorval=="11111"){
    stop_Stop();
    set_Motorspeed(0,0);   //motorsnelheid instellen
    digitalWrite (red_led,HIGH);   // rood led
  }
}

/*start of stop loop*/
void loop(){        
  /*start loop alle led LOW*/
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  digitalWrite(blue_led,LOW);
  auto_tracking();
}
