#include <ESP32Servo.h>

const int PAN_PIN = 18;
Servo pan;

void setup() {
  Serial.begin(115200);
  pan.setPeriodHertz(50);
  pan.attach(PAN_PIN, 500, 2500);
  pan.write(90);
  delay(2000);
}

void loop() {
  pan.write(45);
  delay(1500);
  pan.write(90);
  delay(1500);
  pan.write(135);
  delay(1500);
  pan.write(90);
  delay(1500);
}
