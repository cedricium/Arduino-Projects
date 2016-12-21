#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

byte squareChar[8] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};

int posX = 0;
int posY = 0;

const int VRxPin = 0; //VRx pin connected to arduino pin A0
const int VRyPin = 1; //VRy pin connected to arduino in A1
const int SwButtonPin = 2; //SW pin connected to arduino pin D8

int pressed = -1; //this variable will determine whether joystick has been pressed down (selected)
int x = -1; //this variable will hold the X-coordinate value
int y = -1; //this variable will hold the Y-coordinate value

void readJoystick() {
//  pressed = digitalRead(SwButtonPin); //reads whether joystick has been pressed down (selected) or not
  x = analogRead(VRxPin); //reads the X-coordinate value
  y = analogRead(VRyPin); //reads the Y-coordinate value
}

void setup() {
  lcd.createChar(0, squareChar);
  lcd.begin(16, 2);
  lcd.write(byte(0));

  pinMode(SwButtonPin, INPUT);
//  digitalWrite(SwButtonPin, HIGH);
}

void loop() {
  readJoystick();

  if (x > 1000) {
    if (posX != 15) {
      posX += 1;
      lcd.setCursor(posX, posY);
      lcd.write(byte(0));
      lcd.setCursor(posX - 1, posY);
      lcd.print(" ");
      delay(300);
    }
  }

  else if (x < 10) {
    if (posX != 0) {
      posX -= 1;
      lcd.setCursor(posX, posY);
      lcd.write(byte(0));
      lcd.setCursor(posX + 1, posY);
      lcd.print(" ");
      delay(300);
    }
  }

  if (y > 1000) {
    if (posY != 1) {
      posY += 1;
      lcd.setCursor(posX, posY);
      lcd.write(byte(0));
      lcd.setCursor(posX, posY - 1);
      lcd.print(" ");
      delay(300);
    }
  }

  if (y < 10) {
    if (posY != 0) {
      posY -= 1;
      lcd.setCursor(posX, posY);
      lcd.write(byte(0));
      lcd.setCursor(posX, posY + 1);
      lcd.print(" ");
      delay(300);
    }
  }
}
