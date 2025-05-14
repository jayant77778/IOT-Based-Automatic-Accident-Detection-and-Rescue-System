#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// GPS & GSM Module
#define RXD1 D5   // GSM TX to ESP8266 D1 (GPIO5)
#define TXD1 D6  // GSM RX to ESP8266 D2 (GPIO4)
#define GPS_RX D7 // GPS TX to ESP8266 D6 (GPIO12)
#define GPS_TX D8 // GPS RX to ESP8266 D7 (GPIO13)

// Fire Sensor, Buzzer, Button
#define FIRE_SENSOR A0
#define BUZZER D3   // D5
#define EMERGENCY_BUTTON D0  // D3

// LCD Setup (Address 0x27 or 0x3F depending on module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareSerial gsmSerial(RXD1, TXD1);
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;

String phoneNumber = "+917976571390"; // Change this to your phone number

void setup() {
    Serial.begin(115200);
    gpsSerial.begin(9600);
    gsmSerial.begin(9600);

    pinMode(FIRE_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(EMERGENCY_BUTTON, INPUT_PULLUP);

    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("System Start...");
    
    delay(2000);
    lcd.clear();
}

void loop() {
    // GPS Processing
    if (gpsSerial.available()) {
        if (gps.encode(gpsSerial.read())) {
            displayGPS();
        }
    }

    // Fire Detection
    int fireValue = analogRead(FIRE_SENSOR);
    if (fireValue > 6000) {  // Adjust threshold if needed
        Serial.println("Fire detected!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("FIRE DETECTED!");
        
        digitalWrite(BUZZER, HIGH);
        sendSMS("Fire detected! Location: " + getGPSLocation());
        delay(5000);
        digitalWrite(BUZZER, LOW);
    }

    // Emergency Button Press
    if (digitalRead(EMERGENCY_BUTTON) == LOW) {
        Serial.println("Emergency Button Pressed!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("EMERGENCY ALERT!");
        
        sendSMS("Emergency Alert! Vehicle location: " + getGPSLocation());
        delay(5000);
    }
}

// Function to Display GPS Data on LCD
void displayGPS() {
    if (gps.location.isValid()) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Lat: ");
        lcd.print(gps.location.lat(), 6);
        
        lcd.setCursor(0, 1);
        lcd.print("Lon: ");
        lcd.print(gps.location.lng(), 6);
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("GPS Searching...");
    }
}

// Get GPS Location for SMS
String getGPSLocation() {
    if (gps.location.isValid()) {
        String latitude = String(gps.location.lat(), 6);
        String longitude = String(gps.location.lng(), 6);
        return "https://www.google.com/maps?q=" + latitude + "," + longitude;
    } else {
        return "GPS signal lost!";
    }
}

// Send SMS using GSM Module
void sendSMS(String message) {
    gsmSerial.println("AT+CMGF=1");
    delay(1000);
    gsmSerial.println("AT+CMGS=\"" + phoneNumber + "\"");
    delay(1000);
    gsmSerial.println(message);
    delay(1000);
    gsmSerial.write(26);
    delay(5000);
}
