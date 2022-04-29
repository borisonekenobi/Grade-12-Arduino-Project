#include <Servo.h>

Servo xAxis;
Servo yAxis;

const int xPin = A0;
const int yPin = A1;

void setup() {
  xAxis.attach(2);
  xAxis.write(0);

  yAxis.attach(3);
  yAxis.write(0);
}

void loop() {
  int xCoord = map(analogRead(xPin), 0, 1023, 0, 180);
  int yCoord = map(analogRead(yPin), 0, 1023, 0, 180);

  xAxis.write(xCoord);
  yAxis.write(yCoord);
}
