<<<<<<< HEAD
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <DHT.h>

const char* ssid = "Rheyyy";
const char* password = "22229999";

const char* serverName = "http://172.20.10.5/relay/on";

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nClient Terhubung ke Wi-Fi!");
}

void loop() {
  float temperature = dht.readTemperature();

  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" C");

  if ((WiFi.status() == WL_CONNECTED) && (temperature > 35)) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverName);

    int httpResponseCode = http.GET();

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    http.end();

    delay(10000);
  }

  delay(2000);
=======
#include <DHT.h>

const byte dhtPin = 13;
#define DHTTYPE DHT11

DHT dht(dhtPin, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Memulai Sensor Lingkungan...");
}

void loop() {
  delay(2500);

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Gagal membaca data dari sensor DHT!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.print(" Celcius | Kelembapan: ");
  Serial.print(hum);
  Serial.println(" %");
>>>>>>> f5f13955e8f29aa868e2fc93e05da60469dc6cba
}