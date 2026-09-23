const int ldrPin = 3;   // Pin sensor LDR (AO)
const int ledPin = 2;   // Pin untuk LED

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); // Atur pin LED sebagai output
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  Serial.print("Nilai ADC LDR: ");
  Serial.println(ldrValue);

  // Logika Latihan 4: Nyalakan LED JIKA lingkungan gelap gulita (di bawah angka 200)
  if (ldrValue < 200) {
    digitalWrite(ledPin, HIGH); // Nyalakan LED
    Serial.println("Kondisi: Gelap -> LED Menyala");
  } else {
    digitalWrite(ledPin, LOW);  // Matikan LED
    Serial.println("Kondisi: Terang -> LED Padam");
  }

  delay(1000);
}