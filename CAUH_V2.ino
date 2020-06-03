// Định ngĩa các chân điều khiển động cơ
//#define inA1 3 
//#define inA2 4 
#define inB1 5
#define inB2 6 
char blue; //khai báo biến nhận bluetooth
void setup() {
//pinMode(inA1, OUTPUT);
//pinMode(inA2, OUTPUT);
pinMode(inB1, OUTPUT);
pinMode(inB2, OUTPUT);
Serial.begin(9600); 
}
void loop() {
// Nếu nhận được giá trị
if (Serial.available() > 0) {
//đọc dữ liệu gửi về
blue = Serial.read();
}
          if (blue == '5') dithang(); //Tiến
          else 
          if (blue ==  '9') dunglai(); //Dừng 
          else 
          if (blue == '6') lui(); //Lùi
          //else 
          //if(blue == '7') quaytrai(); //Rẽ trái
          //else 
          //if (blue == '8') quayphai(); // Rẽ phải
}
// CTC
void dunglai(){          
           //analogWrite(inA1,LOW);
           //digitalWrite(inA2,LOW);
           digitalWrite(inB1,LOW);
           digitalWrite(inB2,LOW);
}
void dithang(){
          // analogWrite(inA1,50);
           //digitalWrite(inA2,LOW);
           analogWrite(inB1,100);
           digitalWrite(inB2,LOW);
   
}
void lui(){
           //analogWrite(inA1,50);
           //digitalWrite(inA2,HIGH);
           analogWrite(inB1,-100);
           digitalWrite(inB2,HIGH);
}
/*void quaytrai(){
           digitalWrite(inA1,HIGH);
           digitalWrite(inA2,LOW);
           digitalWrite(inB1,LOW);
           digitalWrite(inB2,HIGH);
}
void quayphai(){
           digitalWrite(inA1,LOW);
           digitalWrite(inA2,HIGH);
           digitalWrite(inB1,HIGH);
           digitalWrite(inB2,LOW);
} */
