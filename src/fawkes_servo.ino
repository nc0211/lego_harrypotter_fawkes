/*
   Specify which protocol(s) should be used for decoding.
   If no protocol is defined, all protocols are active.
*/

//#define DECODE_NEC 1

#include <Wire.h>
#include <IRremote.h>
#include <Servo.h>

#define IR_RECEIVE_PIN    3

Servo myservo;
int pos = 90;


void setup() {
  Serial.begin(115200);
  myservo.attach(2);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN);
}

void loop() {

  if (IrReceiver.decode()) {

    // Print a short summary of received data
//    IrReceiver.printIRResultShort(&Serial);
//    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
//      // We have an unknown protocol here, print more info
//      IrReceiver.printIRResultRawFormatted(&Serial, true);
//    }
//    Serial.println();

    /*
       !!!Important!!! Enable receiving of the next value,
       since receiving has stopped after the end of the current received data packet.
    */
    IrReceiver.resume(); // Enable receiving of the next value

    //1 > 0x4 / 2 > 0x5 / 3 > 0x6 / 4 > 0x7 / 5 > 0x8 / 6 > 0x9 / 7 > 0xA / 8 > 0x1B / 9 > 0x1F
    
    if (IrReceiver.decodedIRData.command == 0x4) {
      // do something
      Serial.println("no:1");
      pos = 10;
    }
    else if (IrReceiver.decodedIRData.command == 0x5) {
      // do something else
      Serial.println("no:2");
      pos = 90;
    }
 
