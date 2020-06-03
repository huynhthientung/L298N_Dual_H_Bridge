#define IN1  7
#define IN2 6   
#define IN3 5
#define IN4 4
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
//khai báo 4 thằng trên là hằng số
int led1 = 8;
int led2 = 9;
char value; //biến đọc giá trị từ bluetooth
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600); //Kết nối Bluetooth với speed 9600
}
void motor_1_Dung() { //Chương trình con
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void motor_2_Dung() { //Chương trình con
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor_1_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, HIGH);// chân này không có PWM
  analogWrite(IN2, 255 - speed);
}
 
void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN3, speed);
  digitalWrite(IN4, HIGH);// chân này không có PWM
}
 
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN4, 255 - speed);
  digitalWrite(IN3, LOW);// chân này không có PWM
}
void loop()
{
   if(Serial.available() > 0)
   {
   value = Serial.read();
   }
   // câu lệnh nhiều chọn lựa... Giống Pascal Case ...of
   switch (value) 
   {
  case '1':
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
    break;
  case '2':
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
    break;
  case '3':
      digitalWrite(12,HIGH);
    break;
  case '4':
     digitalWrite(12,LOW);    
    break;
  case '5':
    motor_1_Tien(MAX_SPEED);
    motor_2_Tien(MAX_SPEED);  
  break;
  case '6':
   motor_1_Lui(MAX_SPEED);
   motor_2_Lui(MAX_SPEED);  
  break;
  case '7':
    motor_1_Lui(MAX_SPEED);
    motor_2_Tien(MAX_SPEED);
  break;
  case '8':
    motor_2_Lui(MAX_SPEED);
    motor_1_Tien(MAX_SPEED);
  break;
  case '9': 
    motor_1_Dung();
    motor_2_Dung();
  default: 
   break;
   }
   delay(5);
}

