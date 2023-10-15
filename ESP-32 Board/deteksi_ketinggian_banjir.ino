#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 2; // Pin trigger sensor ultrasonik
const int echoPin = 4; // Pin echo sensor ultrasonik
const int buzzer = 13; // Pin buzzer

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); // Inisialisasi LCD 16x2
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
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
  
  int minDistance = 0;   
  int maxDistance = 300; 
  
  // Calculate the percentage of flood height
  int floodPercentage = map(distance, minDistance, maxDistance, 100, 0); 

  if (distance >= 0 && distance <= 30) { 
    lcd.setCursor(0,0);
    lcd.print("Banjir Sangat Tinggi:");
    lcd.setCursor(0,1);
    lcd.print(floodPercentage);
    lcd.print("%");
    tone(buzzer, 1000, 1000); // Nada 1000 Hz selama 1 detik
  } else if (distance >= 31 && distance <= 100) {
    lcd.setCursor(0,0);
    lcd.print("Banjir Tinggi:");
    lcd.setCursor(0,1);
    lcd.print(floodPercentage);
    lcd.print("%");
    tone(buzzer, 800, 1000); // Nada 800 Hz selama 1 detik
  } else if (distance >= 101 && distance <= 200) {
    lcd.setCursor(0,0);
    lcd.print("Banjir Sedang:");
    lcd.setCursor(0,1);
    lcd.print(floodPercentage);
    lcd.print("%");
    tone(buzzer, 600, 1000); // Nada 600 Hz selama 1 detik
  } else if (distance >= 201 && distance <= 300) {
    lcd.setCursor(0,0);
    lcd.print("Banjir Ringan:");
    lcd.setCursor(0,1);
    lcd.print(floodPercentage);
    lcd.print("%");
    tone(buzzer, 400, 1000); // Nada 400 Hz selama 1 detik
  } else {
    lcd.print("Tidak Ada Banjir");
  }
  
  delay(2000);
  noTone(buzzer); // Mematikan buzzer setelah 1 detik
}
