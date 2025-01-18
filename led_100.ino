#define LED1_R 3 // Red pin for LED 1
#define LED1_G 5 // Green pin for LED 1
#define LED1_B 6 // Blue pin for LED 1

#define LED2_R 9 // Red pin for LED 2
#define LED2_G 10 // Green pin for LED 2
#define LED2_B 11 // Blue pin for LED 2

#define LED3_R 4 // Red pin for LED 3
#define LED3_G 7 // Green pin for LED 3
#define LED3_B 8 // Blue pin for LED 3

void smoothTransition(int pin, int startValue, int endValue, int steps, int delayTime) {
  int stepValue = (endValue - startValue) / steps;
  for (int i = 0; i <= steps; i++) {
    analogWrite(pin, startValue + (stepValue * i));
    delay(delayTime);
  }
}

void setRGB(int rPin, int gPin, int bPin, int r, int g, int b) {
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
}

void generateColors(int &r, int &g, int &b) {
  r = random(50, 256); // Ensuring visible colors
  g = random(50, 256);
  b = random(50, 256);
}

void setup() {
  pinMode(LED1_R, OUTPUT);
  pinMode(LED1_G, OUTPUT);
  pinMode(LED1_B, OUTPUT);

  pinMode(LED2_R, OUTPUT);
  pinMode(LED2_G, OUTPUT);
  pinMode(LED2_B, OUTPUT);

  pinMode(LED3_R, OUTPUT);
  pinMode(LED3_G, OUTPUT);
  pinMode(LED3_B, OUTPUT);

  randomSeed(analogRead(A0)); // Randomize seed
}

void loop() {
  int r1, g1, b1;
  int r2, g2, b2;
  int r3, g3, b3;

  generateColors(r1, g1, b1);
  generateColors(r2, g2, b2);
  generateColors(r3, g3, b3);

  for (int i = 0; i <= 255; i++) {
    // Smoothly transition colors for all LEDs
    smoothTransition(LED1_R, analogRead(LED1_R), r1, 100, 20);
    smoothTransition(LED1_G, analogRead(LED1_G), g1, 100, 20);
    smoothTransition(LED1_B, analogRead(LED1_B), b1, 100, 20);
    
    smoothTransition(LED2_R, analogRead(LED2_R), r2, 100, 20);
    smoothTransition(LED2_G, analogRead(LED2_G), g2, 100, 20);
    smoothTransition(LED2_B, analogRead(LED2_B), b2, 100, 20);

    smoothTransition(LED3_R, analogRead(LED3_R), r3, 100, 20);
    smoothTransition(LED3_G, analogRead(LED3_G), g3, 100, 20);
    smoothTransition(LED3_B, analogRead(LED3_B), b3, 100, 20);
  }

  delay(500); // Pause briefly before transitioning to the next set of colors
}
