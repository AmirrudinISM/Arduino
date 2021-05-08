#include <OneWire.h>
#include <DallasTemperature.h>

//pins for buttons
const int heaterButtonPin = 5; 
const int inc_button = 6;
const int dec_button = 7;

//pins for functional modules
const int heaterPin = 8; 
const int alarm = 9;
#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//initial states
int alarmState = LOW;
int temperature = 0;
int heaterState = HIGH;
int lastButtonState;    
int currentButtonState; 
int desiredTemperature = 20;


void setup() {
  // inputs
  pinMode(heaterButtonPin, INPUT_PULLUP);
  pinMode(inc_button,INPUT);
  pinMode(dec_button,INPUT);
  sensors.begin();
  
  // outputs
  pinMode(heaterPin, OUTPUT);
  digitalWrite(heaterPin, HIGH);
  pinMode(alarm, OUTPUT);
  
  // initialize 
  Serial.begin(19200);
  currentButtonState = digitalRead(heaterButtonPin);
}

void loop() {
  //get temperature reading
  sensors.requestTemperatures(); 
  temperature=sensors.getTempCByIndex(0);
  // save the last state
  lastButtonState    = currentButtonState;      
  // read new state
  currentButtonState = digitalRead(heaterButtonPin);
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    if (temperature >= desiredTemperature){
      Serial.println("Alarm already at desired temperature!");
      if (alarmState == HIGH){
        digitalWrite(alarm,LOW);
        alarmState = LOW;
      }
    }
    //toggle heater on/off
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
 
  if(heaterState == LOW){
    if (temperature >= desiredTemperature){
      digitalWrite(alarm, HIGH);
      digitalWrite(heaterPin, HIGH);
      heaterState != heaterState;
      alarmState = HIGH;
    }
  }

  Serial.print("Heater state: ");
  Serial.println(!heaterState);
  Serial.print("Desired temp: ");
  Serial.println(desiredTemperature);
  Serial.print("Current Temp: ");
  Serial.println(temperature);
  Serial.println("----------------");
  
}
