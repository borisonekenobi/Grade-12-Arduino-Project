#include <LiquidCrystal_I2C.h>

#define blue 2
#define red 3
#define yellow 4
#define green 5

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int xPin = A0;
const int yPin = A1;
const int swPin = 7;

int xCoord;
int yCoord;
int input;

const int MAX_SCORE = 10;
int order[MAX_SCORE];
int score = 0;

bool startGame = false;

void setup()
{
  Serial.begin(9600);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  lcd.init();
  lcd.backlight();

  randomSeed(analogRead(A3) * analogRead(xPin) * analogRead(yPin) + digitalRead(swPin));
  randomSequenceGenerator();

  pinMode(swPin, INPUT_PULLUP);
}

void loop()
{
  if (startGame)
  {
    lcd.setCursor(0, 0);
    lcd.print("Round: ");
    lcd.setCursor(7, 0);
    lcd.print(score + 1);

    if (score >= MAX_SCORE)
    {
      winSequence();
      return;
    }

    for (int i = 0; i <= score; i++)
    {
      digitalWrite(order[i], HIGH);
      delay(500);
      digitalWrite(order[i], LOW);
      delay(100);
    }

    for (int i = 0; i <= score; i++)
    {
      do
      {
        checkInput();
      } while (input == 0);

      digitalWrite(input, HIGH);

      if (input != order[i])
      {
        loseSequence();
        return;
      }
      Serial.println("correct input");

      do
      {
        checkInput();
      } while (input != 0);

      digitalWrite(order[i], LOW);
    }

    score++;
    delay(1000);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Move stick");
    lcd.setCursor(4, 1);
    lcd.print("to start");

    do
    {
      checkInput();
    } while (input == 0);
    do
    {
      checkInput();
    } while (input != 0);

    lcd.clear();
    startGame = true;
  }
}

void randomSequenceGenerator()
{
  randomSeed(analogRead(A3));
  for (int i = 0; i < sizeof(order) / sizeof(order[0]); i++)
  {
    order[i] = round(random(0, 4)) + 2;
    Serial.println(order[i]);
  }
}

void winSequence()
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("You won!");
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(yellow, HIGH);
    delay(250);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(250);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(250);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    delay(250);
    digitalWrite(blue, LOW);
  }
  digitalWrite(yellow, HIGH);
  delay(250);
  digitalWrite(yellow, LOW);
  startGame = false;
  score = 0;
}

void loseSequence()
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("You suck ass!");
  lcd.setCursor(4, 1);
  lcd.print("Score: ");
  lcd.setCursor(11, 1);
  lcd.print(score);
  Serial.println("incorrect input");

  delay(250);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  delay(5000);

  startGame = false;
  randomSequenceGenerator();
  score = 0;
}

void checkInput()
{
  xCoord = map(analogRead(xPin), 0, 1023, 0, 2);
  yCoord = map(analogRead(yPin), 0, 1023, 0, 2);
  input = joystickResult(xCoord, yCoord);
  Serial.print(xCoord);
  Serial.print(" : ");
  Serial.println(yCoord);
}

int joystickResult(int xCoord, int yCoord)
{
  if (xCoord == 0)
    return blue;
  else if (xCoord == 2)
    return red;
  else if (yCoord == 0)
    return yellow;
  else if (yCoord == 2)
    return green;
  else
    return 0;
}