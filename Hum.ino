#include <DHTesp.h>

#define DHTPIN 4  // Numer pinu, do którego podłączony jest czujnik DHT11

DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(DHTPIN, DHTesp::DHT11);
}

void loop() {
  delay(2000);  // Poczekaj kilka sekund między odczytami

  float humidity = dht.getHumidity();
  //float temperature = dht.getTemperature();

  if (isnan(humidity)) {      // if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Błąd odczytu z czujnika DHT11");
    return;
  }

  Serial.print("Wilgotność: ");
  Serial.print(humidity);
  //Serial.print("%  Temperatura: ");
  //Serial.print(temperature);
  //Serial.println("°C");

  delay(3000);  // Poczekaj przed kolejnym odczytem
}
