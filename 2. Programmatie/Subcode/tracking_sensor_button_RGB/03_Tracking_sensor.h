/*Tracking sensor module*/
#define LFSensor_0 A0  //IR1
#define LFSensor_1 A1  //IR2
#define LFSensor_2 A2  //IR3
#define LFSensor_3 A3  //IR4
#define LFSensor_4 A4  //IR5

boolean flag=false;

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
