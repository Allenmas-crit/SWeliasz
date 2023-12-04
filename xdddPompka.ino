const int pump = 11;
const int humiditySensor = A0;
const int lowHumidityThreshold = 60;
const int sensorReadingMin = 310;
const int sensorReadingMax = 570;
const int pumpActivationTime = 5000;
const int measurementInterval = 30 * 60 * 1000;

enum pumpState {
  OFF,
  ON,
  WAITING
};

pumpState currentState = OFF;
unsigned long lastMeasurementTime = 0;

void setup() {
  pinMode(pump, OUTPUT);
  digitalWrite(pump, LOW);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentTime = millis();

  // Wykonaj pomiar co określony interwał czasowy
  if (currentTime - lastMeasurementTime >= measurementInterval) {
    int humidity = analogRead(humiditySensor);
    int mappedHumidity = map(humidity, sensorReadingMin, sensorReadingMax, 0, 100);

    Serial.print("Wilgotność: ");
    Serial.print(mappedHumidity);
    Serial.println("%");

    // Sprawdź wilgotność i podejmij odpowiednie działania
    if (mappedHumidity < lowHumidityThreshold) {
      if (currentState != ON) {
        currentState = ON;
        digitalWrite(pump, HIGH);
        Serial.println("Włącz");
        delay(pumpActivationTime);
      }
    } else {
      if (currentState != OFF) {
        currentState = OFF;
        digitalWrite(pump, LOW);
        Serial.println("Wyłącz");
      }
    }

    // Zaktualizuj czas ostatniego pomiaru
    lastMeasurementTime = currentTime;
  }

  delay(100);  // Drobne opóźnienie dla stabilności pętli
}
