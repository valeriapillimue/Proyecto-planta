//humedad y tiempo

#include <stdio.h>
#include <DS1302.h>

//Esto es para el Tiempo
const int RST   = 8;  
const int DAT   = 7;  
const int CLK = 6;  
DS1302 rtc(RST, DAT, CLK);

//Esto es para la Humedad
int voltaje_hm;
const int humedad = 0;
const int motor = 4;

void setup() {
  Serial.begin(9600); //Inicializamos el puerto serie.
  pinMode(motor,OUTPUT);
  // Para escribir la hora inicial
  //rtc.writeProtect(false);
  //rtc.halt(false);
  //Time t(2022, 11, 18, 16, 29, 00, Time::kFriday);
  //rtc.time(t);
}

void loop() {
  Time t = rtc.time();
  voltaje_hm =  analogRead(humedad);
  if(t.hr==16 && t.min==45){
      if(voltaje_hm < 650){
        digitalWrite(motor,LOW);
        
      }else{
        digitalWrite(motor,HIGH); 
        delay(4000);
        digitalWrite(motor,LOW); 
      }
  }
  Serial.print("valor leido en A0:");  
  Serial.println(voltaje_hm);
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
