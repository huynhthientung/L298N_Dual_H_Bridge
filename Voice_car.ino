String data;
int a1 = 3; // Chân PWM
int a2 = 5; // Chân PWM
int b1 = 10; // Chân PWM
int b2 = 11; // Chân PWM
int spd = 90; 
int dentruoc = 4;
int densau = 8;
void setup()
{
  Serial.begin(9600);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(dentruoc, OUTPUT);
  pinMode(densau, OUTPUT);
}
void motorA_Dung() {     // A stop !
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);
}
// Stop B
void motorB_Dung() {
      digitalWrite(b1, LOW);
      digitalWrite(b2, LOW);  
}
void motorA_Tien(int valspeed) {
      if (valspeed == 0)
      {
        digitalWrite(a1, LOW);
        digitalWrite(a2, LOW);
      } else 
      {
      analogWrite(a1, valspeed);
      digitalWrite(a2, LOW);
      }
}
void motorB_Tien(int valspeed) {
      if (valspeed == 0)
      {
        digitalWrite(b1, LOW);
        digitalWrite(b2, LOW);
      } else
      {
      analogWrite(b1, valspeed);
      digitalWrite(b2, LOW);
      }  
}
void motorA_Lui(int valspeed)   {
        if (valspeed == 0)
      {
        digitalWrite(a1, LOW);
        digitalWrite(a2, LOW);
      } else 
      {
      analogWrite(a2, valspeed);
      digitalWrite(a1, LOW);
      }
}
void motorB_Lui(int valspeed)   {
      if (valspeed == 0)
      {
        digitalWrite(b1, LOW);
        digitalWrite(b2, LOW);
      } else
      {
      analogWrite(b2, valspeed);
      digitalWrite(b1, LOW);
      }
}
void loop(){
      while (Serial.available())
      {  //Kiểm tra byte để đọc
      delay(30); //Delay để ổn định hơn 
      char c = Serial.read(); // tiến hành đọc
      if (c == '#') {break;} //Thoát khỏi vòng lặp khi phát hiện từ #
      data += c; // data = data + c
      } 
      ////////////////////////////////////////////////
  
      if (data.length() > 0) {
          Serial.println(data);  
//          if(data == "bật đèn trước" ||data == "Bật đèn Trước"||data == "Bật Đèn Trước")
//                {
//                    digitalWrite(dentruoc, HIGH);
//                }
//          else if(data == "tắt đèn trước"||data == "Tắt Đèn Trước"|| data == "Tắt đèn Trước" ||data == "Tắt Đèn trước") 
//                {
//                    digitalWrite(dentruoc, LOW);
//                }
//          if(data == "bật đèn sau" ||data == "Bật đèn Sau"||data == "Bật Đèn Sau")
//                {
//                    digitalWrite(densau, HIGH);
//                }
//          else if(data == "tắt đèn sau"||data == "Tắt Đèn Sau"|| data == "Tắt đèn Sau" ||data == "Tắt Đèn Sau") 
//                {
//                    digitalWrite(densau, LOW);
//                } 
          if (data == "Táº¯t Ä�Ã¨n" || data == "Tắt Đèn")
                {
                  digitalWrite(densau, LOW);
                  digitalWrite(dentruoc, LOW);
                }
          if (data == "bật đèn" || data == "báº­t Ä‘Ã¨")
                {
                  digitalWrite(densau, HIGH);
                  digitalWrite(dentruoc, HIGH);      
                }
          if (data == "tá»›i" || data == "tới")   
                {  
                
                  motorA_Tien(spd);
                  motorB_Tien(spd);
             
                }
          if (data == "l**" || data == "nuôi" || data == "lui" || data == "lôi" || data == "nôi")
                {
                  motorA_Lui(spd);
                  motorB_Lui(spd);
                }
           if (data == "dá»«ng láº¡i" || data == "dừng lại" || data == "Dừng lại")
           {
               motorA_Dung();
                  motorB_Dung();  
           }
           if (data == "trÃ¡i" || data == "trái")
                {
                  motorA_Lui(spd);
                  motorB_Tien(spd);
                }
           if (data == "pháº£i" || data == "phải" )
                {
                  motorA_Tien(spd);
                  motorB_Lui(spd);                          
                }
//            if (data == "tiến trái" || data == "Tiến Trái" || data == "Tiến trái" || data == "tiến Trái")
//                {
//                  motorB_Tien(spd);
//                  motorA_Tien(spd - 100);
//                }
//            if (data == "tiến phải" || data == "Tiến Phải" || data == "Tiến phải" || data == "tiến Phải")
//                {
//                  motorA_Tien(spd);
//                  motorB_Tien(spd - 100);
//                }          
    data=""; //Thiết lập lại các biến
      }
}
