#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int button = 2;

int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  lcd.begin(16, 2);
  lcd.print("Button State:");
}

void loop() {
  buttonState = digitalRead(button);
  lcd.setCursor(1, 1);
  
  if (buttonState == LOW) {
    lcd.print("Not Pressed");
  }
  else {
    lcd.print("Pressed    ");
  }
}
