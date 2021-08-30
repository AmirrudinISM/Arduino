const int ledRed_1 = 2;
const int ledGreen_1 = 3;
const int ledBlue_1 = 4;

const int ledRed_2 = 5;
const int ledGreen_2 = 6;
const int ledBlue_2 = 7;

const int ledRed_3 = 8;
const int ledGreen_3 = 9;
const int ledBlue_3 = 10;

char terminalRead = ' ';

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
    if(Serial.available() > 0){
      terminalRead = Serial.read();
      delay(2);

      //control RED
      if(terminalRead == '1'){
        digitalWrite(ledRed_1, HIGH);
        digitalWrite(ledRed_2, HIGH);
        digitalWrite(ledRed_3, HIGH);
        Serial.println("Red ON");
      }

      if(terminalRead == '0'){
        digitalWrite(ledRed_1, LOW);
        digitalWrite(ledRed_2, LOW);
        digitalWrite(ledRed_3, LOW);
        Serial.println("Red OFF");
      }

      //control GREEN
      if(terminalRead == '3'){
        digitalWrite(ledGreen_1, HIGH);
        digitalWrite(ledGreen_2, HIGH);
        digitalWrite(ledGreen_3, HIGH);
        Serial.println("GREEN ON");
      }

      if(terminalRead == '2'){
        digitalWrite(ledGreen_1, LOW);
        digitalWrite(ledGreen_2, LOW);
        digitalWrite(ledGreen_3, LOW);
        Serial.println("GREEN OFF");
      }

      //control BLUE
      if(terminalRead == '5'){
        digitalWrite(ledBlue_1, HIGH);
        digitalWrite(ledBlue_2, HIGH);
        digitalWrite(ledBlue_3, HIGH);
        Serial.println("BLUE ON");
      }

      if(terminalRead == '4'){
        digitalWrite(ledBlue_1, LOW);
        digitalWrite(ledBlue_2, LOW);
        digitalWrite(ledBlue_3, LOW);
        Serial.println("BLUE OFF");
      }
    }
}
