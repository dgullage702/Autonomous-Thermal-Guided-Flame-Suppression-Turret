#include <ESP32Servo.h>

const int PAN_PIN = 18;
const int TILT_PIN = 19;
Servo pan;
Servo tilt;

void setup() {
  Serial.begin(115200);
  pan.setPeriodHertz(50);
  tilt.setPeriodHertz(50);
  pan.attach(PAN_PIN, 500, 2500);
  tilt.attach(TILT_PIN, 500, 2500);
  pan.write(90);
  tilt.write(90);
  delay(2000);
}

void loop() {
  pan.write(45);
  tilt.write(70);
  delay(1500);
  pan.write(90);
  tilt.write(90);
  delay(1500);
  pan.write(135);
  tilt.write(110);
  delay(1500);
  pan.write(90);
  tilt.write(90);
  delay(1500);
}
