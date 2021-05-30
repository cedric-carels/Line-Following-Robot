/*Tracking sensor module*/
#define LFSensor_0 A0  //IR1
#define LFSensor_1 A1  //IR2
#define LFSensor_2 A2  //IR3
#define LFSensor_3 A3  //IR4
#define LFSensor_4 A4  //IR5

int red_led= 5;
int green_led = 13;
int blue_led = 4;

void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
}

boolean flag=false;

/*start of stop loop*/
void loop(){ 
 auto_tracking();
}

/*sensorwaardestring: 1= zwart & 0= wit*/
char sensor[5];
String read_sensor_values(){
  int sensorvalue=32;
  sensor[0]=!digitalRead(LFSensor_0); 
  sensor[1]=!digitalRead(LFSensor_1); 
  sensor[2]=!digitalRead(LFSensor_2); 
  sensor[3]=!digitalRead(LFSensor_3); 
  sensor[4]=!digitalRead(LFSensor_4);
  sensorvalue +=sensor[0]*16+sensor[1]*8+sensor[2]*4+sensor[3]*2+sensor[4];
  
  String senstr= String(sensorvalue,BIN);
  senstr=senstr.substring(1,6);
  return senstr;
}

/*steek in void loop*/
void auto_tracking(){
 String sensorval= read_sensor_values();
  Serial.println(sensorval);

  /*IR1 gedetecteerd*/
  if (sensorval=="01111"){
    digitalWrite(red_led,HIGH);
    digitalWrite(green_led,LOW);
    digitalWrite(blue_led,LOW);
  }
  
  /*IR2 gedetecteerd*/
  if (sensorval=="10111"){
    digitalWrite(red_led,LOW);
    digitalWrite(green_led,HIGH);
    digitalWrite(blue_led,LOW);
  }
  
  /*IR3 gedetecteerd*/
  if (sensorval=="11011"){
    digitalWrite(red_led,LOW);
    digitalWrite(green_led,LOW);
    digitalWrite(blue_led,HIGH);
  }
  
  /*IR4 gedetecteerd*/
  if (sensorval=="11101"){
    digitalWrite(red_led,LOW);
    digitalWrite(green_led,HIGH);
    digitalWrite(blue_led,LOW);
  }
  
  /*IR5 gedetecteerd*/
  if (sensorval=="11110"){
    digitalWrite(red_led,HIGH);
    digitalWrite(green_led,LOW);
    digitalWrite(blue_led,LOW);
  }

  
}
