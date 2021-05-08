// Arduino pin connected to button's pin
const int heaterButtonPin = 6; 
// Arduino pin connected to LED's pin
const int heaterPin    = 5; 

// the current state of LED
int heaterState = LOW;     
// the previous state of button
int lastButtonState;    
// the current state of button
int currentButtonState; 

void setup() {
  // initialize serial
  Serial.begin(9600);
  // set arduino pin to input pull-up mode
  pinMode(heaterButtonPin, INPUT_PULLUP);
  // set arduino pin to output mode
  pinMode(heaterPin, OUTPUT);   

  currentButtonState = digitalRead(heaterButtonPin);
}

void loop() {
  // save the last state
  lastButtonState    = currentButtonState;      
  // read new state
  currentButtonState = digitalRead(heaterButtonPin); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    heaterState = !heaterState;

    // control LED arccoding to the toggled state
    digitalWrite(heaterPin, heaterState); 
  }
}
