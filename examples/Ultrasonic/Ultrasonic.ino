int trig = 13;
int echo = 12;
int ss = 340; //speed of sound 340 m/s
int duration = 0;
int distance = 0;
int main(){
  init();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  
  for(;;){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH)/58;
    distance = duration;
    Serial.println(distance);
  }
  
}

