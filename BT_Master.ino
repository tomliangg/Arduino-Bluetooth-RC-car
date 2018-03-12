#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);    //Pin 10 -> TX on BT, Pin 11 -> RX on BT

int state = 0;
const byte button1 = 9;  //the pin your button is connected to pin 9 on Arduino
const byte button2 = 8;  //if this button pressed, go forward
const byte button3 = 7;  //if pressed, go forward right
const byte button4 = 4;  //if pressed, go backward left
const byte button5 = 3;  //if pressed, go backward
const byte button6 = 2;  //if pressed, go backward right


byte button1State = 0;
byte button2State = 0;
byte button3State = 0;
byte button4State = 0;
byte button5State = 0;
byte button6State = 0;

void setup() {

  Serial.begin(9600);
  BTserial.begin(38400);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);

}

void loop() {

  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  button4State = digitalRead(button4);
  button5State = digitalRead(button5);
  button6State = digitalRead(button6);

  
  if (button1State == HIGH) {
    BTserial.write('Q');  //sends a 1 through the bluetooth serial link
    delay (20);
  }

  else if (button2State == HIGH){
    BTserial.write('W');
    delay(20);
  }

  else if (button3State == HIGH){
    BTserial.write('E');
    delay(20);
  }

  else if (button4State == HIGH){
    BTserial.write('A');
    delay(20);
  }

  else if (button5State == HIGH){
    BTserial.write('S');
    delay(20);
  }

  else if (button6State == HIGH){
    BTserial.write('D');
    delay(20);
  }

  else {
    BTserial.write('P');
    delay(20);
  }
  
}
