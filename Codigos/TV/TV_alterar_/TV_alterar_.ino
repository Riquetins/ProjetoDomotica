//Esse primeiro código serve para capturar o código do controle e convertê-lo para um valor em hexadecimal.
/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
 
#include <IRremote.h>
 
int RECV_PIN = 2;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

//envia codigos protocolo nec

/*
Autor: Marlon Nardi Walendorff
Baseado no trabalho de: Ken Shirriff
*/
 
#include <IRremote.h>
 
IRsend irsend;
 
#define Power 4
#define VolUp 5
#define VolDown 6
#define Input 7
 
byte flag = 0;
byte flag2 = 0;
byte flag3 = 0;
byte flag4 = 0;
 
void setup()
{
pinMode(Power, INPUT_PULLUP);
pinMode(VolUp, INPUT_PULLUP);
pinMode(VolDown, INPUT_PULLUP);
pinMode(Input, INPUT_PULLUP);
}
 
void loop() {
 
if(!digitalRead(Power)) flag = 1;
 
if(digitalRead(Power) && flag == 1) irsend.sendNEC(0x20DF10EF, 32), flag = 0;
 
 
if(!digitalRead(VolUp)) flag2 = 1;
 
if(digitalRead(VolUp) && flag2 == 1) irsend.sendNEC(0x20DF40BF, 32), flag2 = 0;
 
 
 
if(!digitalRead(VolDown)) flag3 = 1;
 
if(digitalRead(VolDown) && flag3 == 1) irsend.sendNEC(0x20DFC03F, 32), flag3 = 0;
 
 
 
if(!digitalRead(Input)) flag4 = 1;
 
if(digitalRead(Input) && flag4 == 1) irsend.sendNEC(0x20DFD02F, 32), flag4 = 0;
 
}
