#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

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

LiquidCrystal_I2C lcd(0x27, 16, 2);

//initial states
int alarmState = LOW;
int temperature = 0;
int heaterState = HIGH;
int lastButtonState;    
int currentButtonState; 
int desiredTemperature = 35;


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
  currentButtonState = digitalRead(heaterButtonPin);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  //get temperature reading
  sensors.requestTemperatures(); 
  temperature=sensors.getTempCByIndex(0);
  // save the last state
  lastButtonState    = currentButtonState;      
  // read new state
  currentButtonState = digitalRead(heaterButtonPin);
  
  lcd.clear();
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    if (temperature >= desiredTemperature){
      
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
      lcd.print("Temp reached!");
      lcd.print(temperature);
      
      alarmState = HIGH;
      digitalWrite(alarm, alarmState);
      //digitalWrite(heaterPin, HIGH);
      heaterState != heaterState;
      digitalWrite(heaterPin, !heaterState);
    }
  }

  lcd.print("Curr:");
  lcd.print(temperature);
  lcd.print(", Want:");
  lcd.print(desiredTemperature);
  lcd.setCursor (0,1); 
  lcd.print("Heater: ");
  if(heaterState == HIGH){
    lcd.print("OFF");
  }
  else{ 
    lcd.print("ON");
  }
  
}
