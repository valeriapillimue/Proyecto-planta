#include <stdio.h>
#include <DS1302.h>

const int RST   = 5;  
const int DAT   = 6;  
const int CLK = 7;  

DS1302 rtc(RST, DAT, CLK);

void setup() {
  Serial.begin(9600);
  // Para escribir la hora inicial
  //rtc.writeProtect(false);
  //rtc.halt(false);
  //Time t(2022, 6, 2, 6, 46, 10, Time::kThursday);
  //rtc.time(t);
}

void loop() {
  Time t = rtc.time();
  Serial.print(t.yr);
  Serial.print("-");
  Serial.print(t.mon);
  Serial.print("-");
  Serial.print(t.date);
  Serial.print(" ");
  Serial.print(t.hr);
  Serial.print(":");
  Serial.println(t.min);
  delay(1000);
}
