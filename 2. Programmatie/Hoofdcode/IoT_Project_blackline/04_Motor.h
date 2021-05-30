/*motor*/
#define FAST_SPEED 200          //instellen van hoge snelheid
#define SLOW_SPEED 110          //instellen van lage snelheid
#define speedPinR 3             //snelheid bepalen van de rechter motor(K2 & K1): door fast en slow
#define RightMotorDirPin1  12   //aansluiting Motor – Rechts Vooraan = K2 
#define RightMotorDirPin2  11   //aansluiting Motor - Rechts Achteraan = K1

#define speedPinL 6             //snelheid bepalen van de linker motor(K4 & K3): door fast en slow 
#define LeftMotorDirPin1  7     // aansluiting Motor – Links Vooraan = K4 
#define LeftMotorDirPin2  8     // aansluiting Motor -Links Achteraan = K3 

/*motor control*/       
/*vooruit*/           //controle van de motor indien de wagen rechtdoor rijdt
void go_Advance(void){
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
}

/*links draaien*/     // controle van de motor indien de wagen links draait
void go_Left(int t=0){
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}

/*rechts draaien*/      // controle van de motor indien de wagen rechts draait
void go_Right(int t=0){
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}

/*stop*/                // zegt wanneer de wagen moet stoppen
void stop_Stop(){
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,LOW);
}

/*makkelijke command snelheid*/   //variabelen meegeven Linker en Rechterkant
void set_Motorspeed(int speed_L,int speed_R){
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}
