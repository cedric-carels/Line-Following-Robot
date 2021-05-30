int button = 1;
int led = 8;

void setup() {
pinMode(button, INPUT);
pinMode(led, OUTPUT);

}

void loop() {
  button = digitalRead(1);
  if (button == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
