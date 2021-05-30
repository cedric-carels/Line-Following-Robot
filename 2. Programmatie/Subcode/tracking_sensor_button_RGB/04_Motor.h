/*motor*/
#define FAST_SPEED 220          //hoge snelheid
#define SLOW_SPEED 100          //min snelheid
#define speedPinR 3             //snelheid bepalen van de rechte motor(K2 & K1): door fast, mid en slow
#define RightMotorDirPin1  12   //rechtsvooraan motor K2 
#define RightMotorDirPin2  11   //rechtsachteraan motor K1
#define speedPinL 6             //snelheid bepalen van de linkse motor(K4 & K3): door fast, mid en slow
#define LeftMotorDirPin1  7     //linkssvooraan motor K4 
#define LeftMotorDirPin2  8     //linkssachteraan motor K3 

/*motor control*/
/*vooruit*/
void go_Advance(void){
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
}

/*links draaien*/
void go_Left(int t=0){
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}

/*rechts draaien*/
void go_Right(int t=0){
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}

void go_Back(int t=0)  //Reverse
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,200);
  analogWrite(speedPinR,200);
  delay(t);
}

/*stop*/
void stop_Stop(){
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,LOW);
}

/*snelheid van motor instellen*/
void set_Motorspeed(int speed_L,int speed_R){
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}
