#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address. Common addresses are 0x27 or 0x3F.
// If this doesn't work, try changing 0x27 to 0x3F.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();
  
  // Turn on the backlight.
  lcd.backlight();
  
  // Print a message to the LCD.
  lcd.setCursor(0, 0); // Go to the first column of the first row
  lcd.print("Uno R4 Testing");
  
  lcd.setCursor(0, 1); // Go to the first column of the second row
  lcd.print("Display is OK!");
}

void loop() {
  // The code runs once in setup, so the loop is empty.
}