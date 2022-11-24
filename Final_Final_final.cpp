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
const int motor = 3;

//esto es para la pantalla
LiquidCrystal_I2C lcd(0x27,16,2);
//LiquidCrystal_I2C lcd(0x3f,16,2);

void setup() {
  
  Serial.begin(9600); //Inicializamos el puerto serie.
  pinMode(motor,OUTPUT);
  // Para escribir la hora inicial
  //rtc.writeProtect(false);
  //rtc.halt(false);
  //Time t(2022, 11, 24, 12, 44, 00, Time::kFriday);
  //rtc.time(t);

  //PANTALLA------------------------------------
  lcd.init(); // Inicializar el LCD
  lcd.backlight();  //Encender la luz de fondo.

}

void loop() {
  Time t = rtc.time();
  voltaje_hm =  analogRead(humedad);
  lcd.setCursor(2, 0);
  lcd.print("FELIZ NAVIDAD");// Escribimos el Mensaje en el LCD.
  if(t.hr==07 && t.min==00){
      if(voltaje_hm < 650){
        analogWrite(motor,0);
        
        
      }else{
        lcd.setCursor(2, 1);
        lcd.print("            ");
        lcd.setCursor(3, 1);
        lcd.print("S.O.S");
        delay(2000);
        analogWrite(motor,120); 
        lcd.setCursor(3, 1); // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
        delay(4000);
        analogWrite(motor,0);
        lcd.clear(); 
        lcd.setCursor(2, 1);
        lcd.print("Gracias Pana!");
        lcd.clear(); 
      }
  }

  if(t.hr==06 && t.min==00){
        lcd.setCursor(0, 1);
        lcd.print("Buenos días :)");
        lcd.clear(); 
  }
  if(t.hr==12 && t.min==00){
        lcd.setCursor(0, 1);
        lcd.print("Buenas Tardes :)");
        lcd.clear(); 
  }
  if(t.hr==19 && t.min==00){
        lcd.setCursor(0, 1);
        lcd.print("Buenas noches :)");
        lcd.clear(); 
  }

  if(voltaje_hm > 800){
        lcd.setCursor(2, 1);
        lcd.print("Tengo sed :c");
  }else{
        lcd.setCursor(2, 1);
        lcd.print("            ");
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
