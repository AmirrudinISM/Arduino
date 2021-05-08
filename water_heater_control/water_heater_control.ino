// Arduino pin connected to button's pin
const int heaterButtonPin = 6; 
// Arduino pin connected to LED's pin
const int heaterPin    = 5; 
//pin to increment counter
int inc_button = 8;
//pin to decrement
int dec_button = 7;

// the current state of LED
int heaterState = LOW;     
// the previous state of button
int lastButtonState;    
// the current state of button
int currentButtonState; 
//counter
int count = 0;


void setup() {
  // initialize serial
  Serial.begin(9600);
  // set arduino pin to input pull-up mode
  pinMode(heaterButtonPin, INPUT_PULLUP);
  // set arduino pin to output mode
  pinMode(heaterPin, OUTPUT);   
  pinMode(inc_button,INPUT);
  pinMode(dec_button,INPUT);
  currentButtonState = digitalRead(heaterButtonPin);

}

void loop() {
  // save the last state
  lastButtonState    = currentButtonState;      
  // read new state
  currentButtonState = digitalRead(heaterButtonPin); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    

    // toggle state of LED
    heaterState = !heaterState;

    // control LED arccoding to the toggled state
    digitalWrite(heaterPin, heaterState); 
    Serial.print("Heater state: ");
    Serial.println(heaterState);
  }
  
  if (digitalRead(inc_button) == HIGH){
    count++;
  }
  else if(digitalRead(dec_button) == HIGH){
    count--;
  }
  Serial.print("Count: ");
  Serial.println(count);
  delay(250);
}
