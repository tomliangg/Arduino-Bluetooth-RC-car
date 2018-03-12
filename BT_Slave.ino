#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);    //Pin 10 -> TX on BT, Pin 11 -> RX on BT

//L293 Connection   
  const int motorA1  = 3;  // Pin  2 of L293D
  const int motorA2  = 5;  // Pin  7 of L293D
  const int motorB1  = 6; // Pin 10 of L293D
  const int motorB2  = 9;  // Pin 15 of L293D

int state = 0;

void setup() {
  // initialize digital pin 8 as an output.

  Serial.begin(9600);
  BTserial.begin(38400);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

}

void loop() {

  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    state = BTserial.read(); // Reads the data from the serial port
  }
  
    /***********************Forward****************************/
  //If state is equal with letter 'W', car will go forward!
    if (state == 'W') {
      analogWrite(motorA1, 255); analogWrite(motorA2, 0);
      analogWrite(motorB1, 255); analogWrite(motorB2, 0); 
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'Q', car will go forward left
    else if (state == 'Q') {
      analogWrite(motorA1, 20); analogWrite(motorA2, 0);  
      analogWrite(motorB1, 200); analogWrite(motorB2, 0); 
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'E', car will go forward right
    else if (state == 'E') {
        analogWrite(motorA1, 200); analogWrite(motorA2, 0); 
        analogWrite(motorB1, 20);  analogWrite(motorB2, 0); 
    }
  /***********************Backward****************************/
  //If state is equal with letter 'S', car will go backward
    else if (state == 'S') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 255); 
      analogWrite(motorB1, 0);   analogWrite(motorB2, 255); 
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'A', car will go backward left
    else if (state == 'A') {
      analogWrite(motorA1, 0); analogWrite(motorA2, 20); 
      analogWrite(motorB1, 0); analogWrite(motorB2, 200); 
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'D', car will go backward right
    else if (state == 'D') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 200); 
      analogWrite(motorB1, 0);   analogWrite(motorB2, 20); 
    }

      /************************Stop/Pause*****************************/
  //If state is equal with letter 'P', pause/stop the car
    else if (state == 'P'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }

}
