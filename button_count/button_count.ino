int inc_button = 8;
int dec_button = 7;
int count = 0;

void setup() {
  pinMode(inc_button,INPUT);
  pinMode(dec_button,INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(inc_button) == HIGH){
    count++;
  }
  else if(digitalRead(dec_button) == HIGH){
    count--;
  }
  Serial.println(count);
  delay(250);
}
