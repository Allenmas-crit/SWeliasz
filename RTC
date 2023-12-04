#include <RTClib.h>

RTC_DS1307 rtc;

char daysOfWeek[7][12] = {
  "Pon",
  "Wt",
  "Sr",
  "Czw",
  "Pt",
  "Sb",
  "Nd"
};

void setup() {
  Serial.begin(115200);

  if (!rtc.begin()) {
    Serial.println("Nie można nawiązać połączenia z modułem RTC");
    Serial.flush();
    while (1);
  }

  // Spróbuj automatycznie ustawiać RTC na datę i godzinę kompilacji
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("Moduł RTC gotowy.");
}

void loop() {
  DateTime now = rtc.now();
  Serial.print("Nasza data: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  delay(30000); // Oczekiwanie 30 sekund przed kolejnym odczytem
}
