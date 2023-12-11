const int sensor_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float moisture_percentage;
  int sensor_analog;

  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = 100.0 - (sensor_analog / 10.23);  // Poprawiony wzór

  Serial.print("Wilgotność w procentach = ");
  Serial.print(moisture_percentage);
  Serial.println("%\n");

  delay(1000);
}
