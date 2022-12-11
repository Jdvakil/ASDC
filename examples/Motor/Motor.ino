int stby = 3;
int pwma = 5;
int pwmb = 6;
int aina = 7;
int ainb = 8;
int speed = 255;

int main()
{
  init(); // this is needed
  Serial.begin(9600);
  pinMode(stby, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(aina, OUTPUT);
  pinMode(ainb, OUTPUT);

  move('f',5, 80);
  turn('r');
}
  
void move(char direction, int time, int speed){
  time *= 1000;
  if (speed >= 0 && speed <= 255){
    switch (direction){
      case 'f':
        digitalWrite(stby, HIGH);
        digitalWrite(aina, HIGH);
        digitalWrite(ainb, HIGH);
        analogWrite(pwma, speed);
        analogWrite(pwmb, speed);
        delay(time);
        analogWrite(pwma, 0);
        analogWrite(pwmb, 0);
        digitalWrite(stby, LOW);
        break;
      case 'r':
        digitalWrite(stby, HIGH);
        digitalWrite(aina, LOW);
        digitalWrite(ainb, LOW);
        analogWrite(pwma, speed);
        analogWrite(pwmb, speed);
        delay(time);
        analogWrite(pwma, 0);
        analogWrite(pwmb, 0);
        digitalWrite(stby, LOW);
        break;
      default:
        digitalWrite(stby, LOW);
        analogWrite(pwma, 0);
        analogWrite(pwmb, 0);
        break;
    }
  }
}  

void turn(char direction){
  switch(direction){
    case 'r':
      digitalWrite(stby, HIGH);
      digitalWrite(ainb, HIGH);
      analogWrite(pwmb, 75);
      delay(1000);
      analogWrite(pwmb, 0);
      digitalWrite(stby, LOW);
      break;
    case 'l':
      digitalWrite(stby, HIGH);
      digitalWrite(aina, HIGH);
      analogWrite(pwma, 75);
      delay(1000);
      digitalWrite(stby, LOW);
      break;
    default:
      digitalWrite(stby, LOW);
      analogWrite(pwma, 0);
      analogWrite(pwmb, 0);
      break;
  }
}