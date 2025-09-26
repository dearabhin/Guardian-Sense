// ---- LIBRARIES ----
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---- WI-FI & TELEGRAM CREDENTIALS ----
const char* ssid     = "ByteDance";  // Your Wi-Fi network name
const char* password = "passwordtharilla";   // Your Wi-Fi password

#define BOT_TOKEN "8014479264:AAHOYuYkwj6SRLWgpa-31FqvLSJtYB321Bk" // Your bot token
#define CHAT_ID "7406956703"                                   // Your chat ID

// ---- NEW PIN DEFINITIONS ----
const int tiltPin   = 7;
const int buzzerPin = 2; // Moved from pin 5
const int ledPin    = 4;
const int sdaPin    = 5; // Confirmed working SDA pin
const int sclPin    = 6; // Confirmed working SCL pin

// ---- OBJECT INITIALIZATION ----
LiquidCrystal_I2C lcd(0x27, 16, 2); // Use your confirmed address
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

// ---- GLOBAL VARIABLES ----
unsigned long lastAlertTime = 0;
const long alertCooldown = 30000; // 30-second cooldown

void setup() {
  Serial.begin(115200);

  // --- Initialize I2C and LCD first ---
  Wire.begin(sdaPin, sclPin); // Explicitly set the I2C pins
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  // --- Initialize other components ---
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);

  // --- Connect to Wi-Fi ---
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    lcd.print(".");
  }
  Serial.println("\nWiFi connected!");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected!");
  delay(2000);

  secured_client.setInsecure();

  // --- Send online message to Telegram ---
  bot.sendMessage(CHAT_ID, "✅ Guardian Sense (ESP32) is online.", "");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Active");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...");
}

void loop() {
  int sensorState = digitalRead(tiltPin);

  if (sensorState == LOW && (millis() - lastAlertTime > alertCooldown)) {
    Serial.println("FALL DETECTED! Sending alert...");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("! FALL DETECTED !");
    lcd.setCursor(0, 1);
    lcd.print("Sending Alert...");
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    bot.sendMessage(CHAT_ID, "🚨 Fall detected by Guardian Sense!", "");

    delay(5000);

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    lastAlertTime = millis();
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Active");
    lcd.setCursor(0, 1);
    lcd.print("Monitoring...");
  }
}