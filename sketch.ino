#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22

#define LED_PIN 2
#define BUZZER_PIN 4

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.println(temp);

  if (temp > 30) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000);
}