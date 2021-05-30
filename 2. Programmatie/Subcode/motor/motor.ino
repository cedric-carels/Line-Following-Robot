#define speedPinR 3             //snelheid bepalen van de rechter motor(K2 & K1): door fast en slow
#define RightMotorDirPin1  12   //aansluiting Motor – Rechts Vooraan = K2 
#define RightMotorDirPin2  11   //aansluiting Motor - Rechts Achteraan = K1

#define speedPinL 6             //snelheid bepalen van de linker motor(K4 & K3): door fast en slow 
#define LeftMotorDirPin1  7     // aansluiting Motor – Links Vooraan = K4 
#define LeftMotorDirPin2  8     // aansluiting Motor -Links Achteraan = K3 

/*motor control*/
void go_Advance(void){  //vooruit
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,255);
  analogWrite(speedPinR,255);
}
void go_Left(int t=0){  //links
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}
void go_Right(int t=0){  //rechts
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}
void go_Back(int t=0){  //achteruit
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}
void stop_Stop(){    //Stop
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,LOW);
}
/*moter snelheid */
void set_Motorspeed(int speed_L,int speed_R){
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}

//Pins initialize
void init_GPIO(){
	pinMode(RightMotorDirPin1, OUTPUT); 
	pinMode(RightMotorDirPin2, OUTPUT); 
	pinMode(speedPinL, OUTPUT);  
 
	pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
	stop_Stop();
}

void setup(){
	init_GPIO();
	go_Advance();//vooruit
 
  delay(2000);
  
  go_Back();//achteruit
 
  delay(2000);
  
  go_Left();//links
 
  delay(2000);
  
  go_Right();//rechts
 
  delay(2000);
  
  stop_Stop();//Stop

}

void loop(){
}
