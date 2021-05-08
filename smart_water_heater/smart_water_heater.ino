#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

// Arduino pin connected to button's pin
const int heaterButtonPin = 5; 
// Arduino pin connected to LED's pin
const int heaterPin    = 8; 
//pin to increment counter
int inc_button = 6;
//pin to decrement
int dec_button = 7;

//temperature
int temperature = 0;

//buzzer for alamr
int alarm = 9;
int alarmState = LOW;


// the current state of LED
int heaterState = HIGH;
    
// the previous state of button
int lastButtonState;    
// the current state of button
int currentButtonState; 
//counter
int desiredTemperature = 20;


void setup() {
  // initialize serial
  Serial.begin(19200);
  // set arduino pin to input pull-up mode
  pinMode(heaterButtonPin, INPUT_PULLUP);
  // set arduino pin to output mode
  pinMode(heaterPin, OUTPUT);
  digitalWrite(heaterPin, HIGH);
  pinMode(inc_button,INPUT);
  pinMode(dec_button,INPUT);
  currentButtonState = digitalRead(heaterButtonPin);
  //alarm
  pinMode(alarm, OUTPUT);
  sensors.begin();
}

void loop() {
  // save the last state
  lastButtonState    = currentButtonState;      
  // read new state
  currentButtonState = digitalRead(heaterButtonPin);
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    // toggle state of LED
    if (temperature >= desiredTemperature){
      Serial.println("Alarm already at desired temperature!");
      if (alarmState == HIGH){
        digitalWrite(alarm,LOW);
        alarmState = LOW;
      }
    }
      
    heaterState = !heaterState;
    // control heater arccoding to the toggled state
    digitalWrite(heaterPin, heaterState);
  }
  
  if (digitalRead(inc_button) == HIGH){
    desiredTemperature++;
  }
  else if(digitalRead(dec_button) == HIGH){
    desiredTemperature--;
  }
  
  Serial.print("Heater state: ");
  Serial.println(heaterState);
  Serial.print("Desired temp: ");
  Serial.println(desiredTemperature);
  sensors.requestTemperatures(); 
  temperature=sensors.getTempCByIndex(0);
  Serial.print("Current Temp: ");
  Serial.println(temperature);
  Serial.println("----------------");
  
  
  if(heaterState == LOW){
    if (temperature >= desiredTemperature){
      digitalWrite(alarm, HIGH);
      digitalWrite(heaterPin, HIGH);
        alarmState = HIGH;
    }
  }
  
}
