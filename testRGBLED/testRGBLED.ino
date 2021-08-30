const int ledRed_1 = 2;
const int ledGreen_1 = 3;
const int ledBlue_1 = 4;

const int ledRed_2 = 5;
const int ledGreen_2 = 6;
const int ledBlue_2 = 7;

const int ledRed_3 = 8;
const int ledGreen_3 = 9;
const int ledBlue_3 = 10;

//char terminalRead = ' ';

void setup(){
  Serial.begin(9600);

  pinMode(ledRed_1, OUTPUT);
  pinMode(ledGreen_1, OUTPUT);
  pinMode(ledBlue_1, OUTPUT);
  
  digitalWrite(ledRed_1, LOW);
  digitalWrite(ledGreen_1, LOW);
  digitalWrite(ledBlue_1, LOW);

  pinMode(ledRed_2, OUTPUT);
  pinMode(ledGreen_2, OUTPUT);
  pinMode(ledBlue_2, OUTPUT);
  
  digitalWrite(ledRed_2, LOW);
  digitalWrite(ledGreen_2, LOW);
  digitalWrite(ledBlue_2, LOW);

  pinMode(ledRed_3, OUTPUT);
  pinMode(ledGreen_3, OUTPUT);
  pinMode(ledBlue_3, OUTPUT);
  
  digitalWrite(ledRed_3, LOW);
  digitalWrite(ledGreen_3, LOW);
  digitalWrite(ledBlue_3, LOW);
}

void loop(){
    byte terminalRead = 0;
    if(Serial.available() > 0){
      terminalRead = Serial.read();
      delay(2);

   
      if(terminalRead >= '0' && terminalRead <= '9'){
        terminalRead =  25*(terminalRead - '0');
        analogWrite(ledRed_1, terminalRead);
        analogWrite(ledRed_2, terminalRead);
        analogWrite(ledRed_3, terminalRead);
        analogWrite(ledGreen_1, terminalRead);
        analogWrite(ledGreen_2, terminalRead);
        analogWrite(ledGreen_3, terminalRead);
        analogWrite(ledBlue_1, terminalRead);
        analogWrite(ledBlue_2, terminalRead);
        analogWrite(ledBlue_3, terminalRead);
      }
    }
}
