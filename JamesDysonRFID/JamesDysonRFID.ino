/*
 * 
 * All the resources for this project: https://www.hackster.io/Aritro
 * Modified by Aritro Mukherjee
 * 
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
#include <ezBuzzer.h> // ezBuzzer library
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
const int BUZZER_PIN = 7;
int lastButtonState = HIGH;
ezBuzzer buzzer(BUZZER_PIN);

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

  

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "B3 A4 04 97" || content.substring(1) == "93 4B 79 0A") //change here the UID of the card/cards that you want to give access  93 4B 79 0A

  {
    Serial.println("Authorized access");
    Serial.println();
   // pinMode(7, OUTPUT);
    //digitalWrite(7,HIGH);
    
    delay(3000);


    buzzer.loop(); // MUST call the buzzer.loop() function in loop()

 

  if (lastButtonState == HIGH && currentState == LOW) {
    Serial.println("The button is pressed");
    buzzer.beep(100); // generates a 100ms beep
  }


 //   digitalWrite(7,LOW);
    
  }

  
 
 else   {
    Serial.println(" Access denied");
    delay(3000);
  }
} 
