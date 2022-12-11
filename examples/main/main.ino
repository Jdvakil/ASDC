#include <Servo.h>
Servo myservo;
int servo = 10;
int speed = 10;


int main(){

    init();
    myservo.attach(servo);

    for(;;){
        servo_move();
    }
}

void servo_move(){
    for (int pos = 0; pos <= 100; pos += 1) { 
        myservo.write(pos);             
        delay(speed);                       
    }
   for (int pos = 100; pos >= 0; pos -= 1) { 
        myservo.write(pos);         
        delay(speed);  
   }
}

int read_dist(){
  
}