const int merahPin = 2;
const int kuningPin = 4;
const int hijauPin = 5;

void setup() {
  pinMode(merahPin, OUTPUT);
  pinMode(kuningPin, OUTPUT);
  pinMode(hijauPin, OUTPUT);
}

void loop() {
  // Lampu hijau menyala, sementara lainnya mati
  digitalWrite(hijauPin, HIGH);
  digitalWrite(kuningPin, LOW);
  digitalWrite(merahPin, LOW);
  delay(5000);  // Tunggu 5 detik

  // Lampu kuning menyala, sementara lainnya mati
  digitalWrite(hijauPin, LOW);
  digitalWrite(kuningPin, HIGH);
  digitalWrite(merahPin, LOW);
  delay(2000);  // Tunggu 2 detik

  // Lampu merah menyala, sementara lainnya mati
  digitalWrite(hijauPin, LOW);
  digitalWrite(kuningPin, LOW);
  digitalWrite(merahPin, HIGH);
  delay(5000);  // Tunggu 5 detik
}
