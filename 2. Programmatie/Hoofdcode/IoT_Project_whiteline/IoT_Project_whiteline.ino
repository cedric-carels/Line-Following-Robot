//onder #include staan alle bibliotheken en functies die de hoofdcode ophaalt
#include "01_object_detecteren.h"
#include "02_RGB.h"
#include "03_Tracking_sensor.h"
#include "04_Motor.h"
#include "05_extra.h"

void setup() {
  /*object_detecteren*/
  head.attach(SERVO_PIN);

  /*RGB*/
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);

  /*Motor*/
  pinMode(RightMotorDirPin1, OUTPUT);
  pinMode(RightMotorDirPin2, OUTPUT);
  pinMode(speedPinR, OUTPUT);

  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT);
  pinMode(speedPinL, OUTPUT);
  stop_Stop();

  /*button*/
  pinMode (button, INPUT);
}

//hier maak je een void loop voor de auto tracking
void auto_tracking() {
  /*tracking sensor*/
  /*wit=0, zwart=1*/
  String sensorval = read_sensor_values();

  /*Vooruit*/
  if (sensorval == "11011") {
    go_Advance();
    set_Motorspeed(SLOW_SPEED, SLOW_SPEED);   // motorsnelheid instellen
    head.write(30);
    digitalWrite (red_led, LOW);              // instellen rode led
    digitalWrite(green_led, HIGH);            // instellen groene led
    digitalWrite (blue_led, LOW);             // instellen blauwe led
  }

  /*Sla linksaf*/
  if (sensorval == "01111") {
    go_Left();
    set_Motorspeed(FAST_SPEED, FAST_SPEED);   // motorsnelheid instellen    
    head.write(45);
    digitalWrite (red_led, LOW);              // instellen rode led
    digitalWrite(green_led, HIGH);            // instellen groene led
    digitalWrite (blue_led, LOW);             // instellen blauwe led
  }

  /*Flauwe bocht naar links*/
  if (sensorval == "00111"  || sensorval == "10111" || sensorval == "01011" || sensorval == "10011"  || sensorval == "00011" || sensorval == "01001" || sensorval == "00001" || sensorval == "00101" || sensorval == "01101") {
    go_Advance();
    set_Motorspeed(0, FAST_SPEED);            // motorsnelheid instellen
    head.write(60);
    digitalWrite (red_led, LOW);              // instellen rode led
    digitalWrite(green_led, HIGH);            // instellen groene led
    digitalWrite (blue_led, LOW);             // instellen blauwe led
  }

  /*Sla rechtsaf*/
  if (sensorval == "11110") {
    go_Right();
    set_Motorspeed(FAST_SPEED, FAST_SPEED);   // motorsnelheid instellen
    head.write(15);
    digitalWrite (red_led, LOW);              // instellen rode led
    digitalWrite(green_led, HIGH);            // instellen groene led
    digitalWrite (blue_led, LOW);             // instellen blauwe led
  }
  
  /*Flauwe bocht naar rechts*/
  if (sensorval == "11100" || sensorval == "11101"  || sensorval == "11010" || sensorval == "11001" || sensorval == "11000" || sensorval == "10010" || sensorval == "10000"   || sensorval == "10100"  || sensorval == "10110") {
    go_Advance();
    set_Motorspeed(FAST_SPEED, 0);            // motorsnelheid instellen
    head.write(0);
    digitalWrite (red_led, LOW);              // instellen rode led
    digitalWrite(green_led, HIGH);            // instellen groene led
    digitalWrite (blue_led, LOW);             // instellen blauwe led
  }

  /*spoor verloren*/
  if (sensorval == "11111") {
    stop_Stop();
    set_Motorspeed(0, 0);                     // motorsnelheid instellen
    head.write(30);
    digitalWrite (red_led, HIGH);             // instellen rode led
    digitalWrite(green_led, LOW);             // instellen groene led
    digitalWrite (blue_led, LOW);             // instellen blauwe led

  }

  /*witte lijn*/
  if (sensorval == "00000") {
    stop_Stop();
    set_Motorspeed(0, 0);                     // motorsnelheid instellen    
    head.write(30);
    digitalWrite (red_led, LOW);              // instellen rode led
    digitalWrite(green_led, LOW);             // instellen groene led
    digitalWrite (blue_led, HIGH);            // instellen blauwe led

    /*tijd*/
    int start = millis();                    //data meegeven : timer wordt gestart bij zien van witte lijn
    int periode = millis() - start;          //data meegeven : timer begin traject – resultaat timer start

    /*na 5 sec doorrijden*/
    while (digitalRead(1) == LOW && periode < 5000) {
      periode = millis() - start;
    }
    go_Advance();
    set_Motorspeed(SLOW_SPEED, SLOW_SPEED);  //motorsnelheid instellen
    digitalWrite (red_led, LOW);             // instellen rode led
    digitalWrite(green_led, HIGH);           // instellen groene led
    digitalWrite (blue_led, LOW);            // instellen blauwe led
  }
}

// hier maak je een void loop voor het detecteren van een object
void auto_object() {
  /*afstand object decteren*/
  distanceThreshold = 20;           // instellen afstand detecteren object
  cm = 0.01723 * readUltrasonicDistance(Trig_PIN, Echo_PIN);
  // meet de ping-tijd in cm

  /*object_detecteren*/
  while (cm <= distanceThreshold) {
    stop_Stop();
    set_Motorspeed(0, 0);           //motorsnelheid instellen
    digitalWrite (red_led, LOW);    // instellen rode led
    digitalWrite(green_led, LOW);   // instellen groene led
    digitalWrite (blue_led, HIGH);  // instellen blauwe led
    cm = 0.01723 * readUltrasonicDistance(Trig_PIN, Echo_PIN);      // meet de ping-tijd in cm
  }
}

//hier zorg je ervoor dat er een loop wordt gemaakt
/*start of stop loop*/
void loop() {
  auto_object();      //haalt de code op die je schreef onder void auto_object
  auto_tracking();    //haalt de code op die je schreef onder void auto_tracking
}
