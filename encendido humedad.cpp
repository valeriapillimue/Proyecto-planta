int voltaje_hm;
const int humedad = 0;
const int motor = 4;

void setup() {
  Serial.begin(9600);//Inicializamos el puerto serie.
 
  pinMode(motor,OUTPUT);  
}

void loop() {
  
  voltaje_hm =  analogRead(humedad);
  Serial.print("valor leido en A0:");  
  Serial.println(voltaje_hm);
  delay(500);
  
  if(voltaje_hm < 650){
    digitalWrite(motor,LOW);

  }else{
    digitalWrite(motor,LOW); 
  }
  
}
