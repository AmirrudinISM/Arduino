#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
int buzzer = 8;
float Celcius=0;
float Fahrenheit=0;

void setup(void){
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  if(Celcius > 30){
    digitalWrite(buzzer,HIGH);
  }
  else{
     digitalWrite(buzzer,LOW);
  }
  delay(1000);
}
