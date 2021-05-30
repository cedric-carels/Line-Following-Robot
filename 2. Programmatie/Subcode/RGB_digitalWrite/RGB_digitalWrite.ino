int red_led= 5;
int green_led = 1;
int blue_led = 0;

void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
}

void loop() {
  digitalWrite(red_led,HIGH);
  digitalWrite(green_led,LOW);
  digitalWrite(blue_led,LOW);
  delay(5000);
  
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,HIGH);
  digitalWrite(blue_led,LOW);
  delay(5000);
  
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  digitalWrite(blue_led,HIGH);
  delay(5000);
}
