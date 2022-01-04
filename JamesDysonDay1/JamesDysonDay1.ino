
int led = 13;
int time =100;
void setup() {
  
  pinMode(led, OUTPUT);    // sets the digital pin 13 as output
  
}


void loop() {
  
  digitalWrite(led, HIGH); // sets the digital pin 13 on
  delay(time);            // waits for a second
  digitalWrite(led, LOW);  // sets the digital pin 13 off
  delay(time);            // waits for a second

}
