int red_led = 5;
int green_led = 13;
int blue_led = 4;

void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
}

void loop() {
  RGB_color(255, 165, 0); // oranje
}

void RGB_color(int red_led_value, int green_led_value, int blue_led_value) {
  analogWrite(red_led, red_led_value);
  analogWrite(green_led, green_led_value);
  analogWrite(blue_led, blue_led_value);
}
