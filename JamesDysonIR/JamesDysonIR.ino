#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}



void blink(int num){
  pinMode(8,OUTPUT);                                ////// function to blink num number of times. num is selected by you eg 1,2,3,4,5...
  for(int i =0; i<num;i++){
  digitalWrite(8,HIGH);
  delay(300);
  digitalWrite(8,LOW);
  delay(300);
  }
  }

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0xFFA25D:
          Serial.println("CH-");
          break;
          case 0xFF629D:
          Serial.println("CH");
          break;
          case 0xFFE21D:
          Serial.println("CH+");
          break;
          case 0xFF22DD:
          Serial.println("|<<");
          break;
          case 0xFF02FD:
          Serial.println(">>|");
          break ;  
          case 0xFFC23D:
          Serial.println(">|");
          break ;               
          case 0xFFE01F:
          Serial.println("-");
          break ;  
          case 0xFFA857:
          Serial.println("+");
          break ;  
          case 0xFF906F:
          Serial.println("EQ");
          break ;  
          case 0xFF6897:
          Serial.println("0");
          break ;  
          case 0xFF9867:
          Serial.println("100+");
           pinMode(8,OUTPUT);
            for(int i =0; i<100;i++){
            digitalWrite(8,HIGH);
            delay(50);                        ///// same as blink function but with smaller delay of 50ms so it blinks faster
            digitalWrite(8,LOW);
            delay(50);
            }
          break ;
          case 0xFFB04F:
          Serial.println("200+");
          pinMode(8,OUTPUT);
            for(int i =0; i<200;i++){
            digitalWrite(8,HIGH);
            delay(30);                        ///// same as blink function but with smaller delay of 30ms so it blinks faster
            digitalWrite(8,LOW);
            delay(30);
            }
          break ;
          case 0xFF30CF:
          Serial.println("1");
           blink(1);
          break ;
          case 0xFF18E7:
          Serial.println("2");
           blink(2);
          break ;
          case 0xFF7A85:
          Serial.println("3");
           blink(3);
          break ;
          case 0xFF10EF:
          Serial.println("4");
           blink(4);
          break ;
          case 0xFF38C7:
          Serial.println("5");
          blink(5);
          break ;
          case 0xFF5AA5:
          Serial.println("6");
           blink(6);
          break ;
          case 0xFF42BD:
          Serial.println("7");
           blink(7);
          break ;
          case 0xFF4AB5:
          Serial.println("8");
           blink(8);
          break ;
          case 0xFF52AD:
          Serial.println("9");
           blink(9);
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
