#include <Servo.h>
Servo  myservo;
int spd;
char blue;
boolean auto_car;
void setup() {
  Serial.begin(9600);
  myservo.attach(47); // Đặt chân D9 là chân tín hiệu ra Servo
  
  myservo.write(90); 
}
//void motorA_Dung() {     // A stop !
//      digitalWrite(a1, LOW);
//      digitalWrite(a2, LOW);
//}
//// Stop B
//void motorB_Dung() {
//      digitalWrite(b1, LOW);
//      digitalWrite(b2, LOW);  
//}
//void motorA_Tien(int valspeed) {
//      if (valspeed == 0)
//      {
//        digitalWrite(a1, LOW);
//        digitalWrite(a2, LOW);
//      } else 
//      {
//      analogWrite(a1, valspeed);
//      digitalWrite(a2, LOW);
//      }
//}
//void motorB_Tien(int valspeed) {
//      if (valspeed == 0)
//      {
//        digitalWrite(b1, LOW);
//        digitalWrite(b2, LOW);
//      } else
//      {
//      analogWrite(b1, valspeed);
//      digitalWrite(b2, LOW);
//      }  
//}
//void motorA_Lui(int valspeed)   {
//        if (valspeed == 0)
//      {
//        digitalWrite(a1, LOW);
//        digitalWrite(a2, LOW);
//      } else 
//      {
//      analogWrite(a2, valspeed);
//      digitalWrite(a1, LOW);
//      }
//}
//void motorB_Lui(int valspeed)   {
//      if (valspeed == 0)
//      {
//        digitalWrite(b1, LOW);
//        digitalWrite(b2, LOW);
//      } else
//      {
//      analogWrite(b2, valspeed);
//      digitalWrite(b1, LOW);
//      }
//}
void loop() {

      
        if (Serial.available() > 0)
        {
          blue = Serial.read(); // Đọc Bluetooth
        }
//**********************************************************
        switch(blue)
        { 
          case '0': //Speed 0%
                    myservo.write(50);
                                       
               break;
          case '1': // Speed 10%
                      myservo.write(30);
                    break;
          case '2': // Speed 20%
                    spd = 50;
               break;
          case '3': // Speed 30%
                    spd = 72;
               break;
          case '4': // Speed 40%
                    spd = 103;
               break;
          case '5': // Speed 50%
                    spd = 130;
               break;
          case '6': // Speed 60%
                     spd = 158;
               break;
          case '7': // Speed 70%
                      spd = 181;
               break;
          case '8': // Speed 80%
                     spd = 207;
               break;
          case '9': // Speed 90%
                      spd = 230;
               break;       
          case 'q': // Speed 100%
                      spd = 255;
               break;
////********              
          default:
          break;
        }
        // Choose Mode Auto Run          
        
}
