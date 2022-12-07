int stby = 3;
int pwma = 5;
int pwmb = 6;
int aina = 7;
int ainb = 8;
int speed = 255;

void setup(){
  pinMode(stby, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(aina, OUTPUT);
  pinMode(ainb, OUTPUT);
}

void loop(){
  for (int i=255; i>=0; i = i - 40){
    digitalWrite(stby, HIGH);
    digitalWrite(aina, LOW);
    digitalWrite(ainb, LOW);
    analogWrite(pwmb, i);
    analogWrite(pwma, i);
    delay(2000);
    if (i == 1){
      digitalWrite(stby, LOW);
      break;
    }
  }
  
}