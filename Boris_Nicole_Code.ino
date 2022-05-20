#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo xAxis;
Servo yAxis;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int xPin = A0;
const int yPin = A1;
const int swPin = 0;

bool startTimer = false;
double timer = 0;
double tSecs = 0;
double secs = 0;
int mins = 0;
unsigned long startTime;

int buttonInput = 4;
int buttonOutput = 5;

void setup() {
  xAxis.attach(2);
  xAxis.write(90);

  yAxis.attach(3);
  yAxis.write(90);

  lcd.init();
  lcd.backlight();

  pinMode(swPin, INPUT_PULLUP);
  pinMode(buttonInput, INPUT);
  pinMode(buttonOutput, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if (startTimer) {
    if (digitalRead(buttonInput)) {
      startTimer = false;
      delay(5000);
      lcd.clear();
      return;
    }
    
    int xCoord = map(analogRead(xPin), 0, 1023, 0, 180);
    int yCoord = map(analogRead(yPin), 0, 1023, 0, 180);
  
    xAxis.write(xCoord);
    yAxis.write(yCoord);

    timer = millis() - startTime;
    tSecs = timer / 1000;
    mins = tSecs / 60;
    secs = tSecs - 60 * mins;

    char s[17];
    dtostrf(secs, 6, 3, s);
    if (s[0] == ' ') {
      s[0] = '0';
    }
    char t[17];
    sprintf(t, "%02d:%s", mins, s);
  
    lcd.setCursor(5, 0);
    lcd.print("Time");
    lcd.setCursor(0, 1);
    lcd.print(t);
    
  } else {
    if (!digitalRead(swPin)) {
      startTimer = true;
      startTime = millis();
      digitalWrite(buttonOutput, HIGH);
      lcd.clear();
      
    } else {
      lcd.setCursor(1, 0);
      lcd.print("Click Joystick");
      lcd.setCursor(4, 1);
      lcd.print("To Begin");
    }
  }
}
