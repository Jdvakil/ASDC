#include <Servo.h>
Servo myservo;

int trig = 13;
int echo = 12;
int distance, duration;
int stby = 3;
int pwma = 5;
int pwmb = 6;
int aina = 7;
int ainb = 8;
int speed = 255;
int read, l, r;
int main()
{

  init();

  myservo.attach(10);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(stby, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(aina, OUTPUT);
  pinMode(ainb, OUTPUT);
  Serial.begin(9600);
  servo_move('s');
  for(;;){
      digitalWrite(stby, HIGH);
      digitalWrite(aina, HIGH);
      digitalWrite(ainb, HIGH);
      analogWrite(pwma, speed);
      analogWrite(pwmb, speed);
      read = read_dist();
      if (read<=30 || read >=1700){
        analogWrite(pwma, 0);
        analogWrite(pwmb, 0);
        digitalWrite(stby, LOW);
        delay(1000);
        move('r', 1, 100);
        delay(1000);
        servo_move('r');
        delay(500);
        r = read_dist();
        
        servo_move('l');
        l = read_dist();
        delay(500);

        if(r > l){
          turn('r');
          delay(1000);
        }
        else if(l > r){
          turn('l');
          delay(1000);
        }
        servo_move('s');
      }
  }

}

void servo_move(char dir)
{
  switch (dir)
  {
  case 'r':
    myservo.write(0);
    delay(1000);
    break;
  case 'l':
    myservo.write(120);
    delay(1000);
    break;
  case 's':
    myservo.write(50);
    delay(1000);
    break;
  }
}

int read_dist()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH) / 58;
  distance = duration;
  Serial.println(distance);
  return (distance);
}
void move(char direction, int time, int speed)
{
  time *= 1000;
  if (speed >= 0 && speed <= 255)
  {
    switch (direction)
    {
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

void turn(char direction)
{
  switch (direction)
  {
  case 'r':
    digitalWrite(stby, HIGH);
    digitalWrite(ainb, HIGH);
    analogWrite(pwmb, 100);
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