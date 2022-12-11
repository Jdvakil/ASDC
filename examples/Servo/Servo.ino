#include <Servo.h>
Servo myservo;  

int main(){
  init();
  Serial.begin(9600);
  myservo.attach(10);
  Serial.println(myservo.read());
  for (int pos = 0; pos <= 100; pos += 1) { // goes from 180 degrees to 0 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(5);                       // waits 15ms for the servo to reach the position

  }
   for (int pos = 100; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(5);  
}
}