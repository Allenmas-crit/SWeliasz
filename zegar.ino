#include <RTClib.h>

RTC_DS1307 rtc;

char daysOfWeek[7][12] = {
  "Nd",
  "Pn",
  "Wt",
  "Sr",
  "Czw",
  "Pt",
  "Sb"
};

void setup () {
  Serial.begin(9600);

  // SETUP RTC MODULE
  if (! rtc.begin()) {
    Serial.println("RTC nie znaleziono");
    Serial.flush();
    while (1);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // ustawia czas w momencie kompilacji
}

void loop () {
  DateTime now = rtc.now();
  Serial.print("ESP32 RTC Date Time: ");
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

  delay(1000); // delay 1 seconds
}
