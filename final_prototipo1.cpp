#include <stdio.h>
#include <DS1302.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Esto es para el Tiempo
const int RST   = 8;  
const int DAT   = 7;  
const int CLK = 6;  
DS1302 rtc(RST, DAT, CLK);

//Esto es para la Humedad
int voltaje_hm;
const int humedad = 0;
const int motor = 4;

//esto es para la pantalla
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  
  Serial.begin(9600); //Inicializamos el puerto serie.
  pinMode(motor,OUTPUT);
  // Para escribir la hora inicial
  //rtc.writeProtect(false);
  //rtc.halt(false);
  //Time t(2022, 11, 18, 16, 29, 00, Time::kFriday);
  //rtc.time(t);

  //PANTALLA------------------------------------
  lcd.init(); // Inicializar el LCD
  lcd.backlight();  //Encender la luz de fondo.
  lcd.print("FELIZ NAVIDAD");// Escribimos el Mensaje en el LCD.
  
}

void loop() {
  Time t = rtc.time();
  voltaje_hm =  analogRead(humedad);
  lcd.setCursor(0, 0);
  lcd.print("FELIZ NAVIDAD");// Escribimos el Mensaje en el LCD.
  if(t.hr==17 && t.min==33){
      if(voltaje_hm < 650){
        digitalWrite(motor,LOW);
        
        
      }else{
        lcd.setCursor(0, 1);
        lcd.print("S.O.S");
        delay(2000);
        digitalWrite(motor,HIGH); 
        lcd.setCursor(0, 1); // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
        delay(4000);
        digitalWrite(motor,LOW);
        lcd.clear(); 
        lcd.setCursor(0, 1);
        lcd.print("Gracias Pana!");
        lcd.clear(); 
      }
  }

  if(t.hr==17 && t.min==33){
        lcd.setCursor(0, 1);
        lcd.print("Buenos días :)");
        lcd.clear(); 
  }
  if(t.hr==17 && t.min==33){
        lcd.setCursor(0, 1);
        lcd.print("Buenas Tardes :)");
        lcd.clear(); 
  }
  if(t.hr==17 && t.min==33){
        lcd.setCursor(0, 1);
        lcd.print("Buenas noches :)");
        lcd.clear(); 
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
