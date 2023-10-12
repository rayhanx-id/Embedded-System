#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 2; // Pin trigger sensor ultrasonik
const int echoPin = 4; // Pin echo sensor ultrasonik

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); // Inisialisasi LCD 16x2
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  lcd.clear();
  
  if (distance >= 2 && distance < 30) { 
    lcd.setCursor(0,0);
    lcd.print("Banjir Terdeteksi");
    lcd.setCursor(0,1);
    lcd.print("Rendah!!!");
  } else if (distance >= 30 && distance < 60) {
    lcd.setCursor(0,0);
    lcd.print("Banjir Terdeteksi");
    lcd.setCursor(0,1);
    lcd.print("Normal!!!");
  } else if (distance >= 60) {
    lcd.setCursor(0,0);
    lcd.print("Banjir Terdeteksi");
    lcd.setCursor(0,1);
    lcd.print("Tinggi!!!");
  } else {
    lcd.print("Tidak Ada Banjir");
  }
  
  delay(3000);
}
