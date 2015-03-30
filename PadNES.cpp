
#include "PadNES.h"

PadNES::PadNES(int clock, int latch, int data){

CLOCK=clock;
LATCH=latch;
DATA=data;
nextTimeRead=0;
buttons=0;
RIGHT=B00000001;
LEFT=B00000010;
DOWN=B00000100;
UP=B00001000;
START=B00010000;
SELECT=B00100000;
B=B01000000;
A=B10000000;

}


byte PadNES::readNES(){

  byte nButtons=0;


  digitalWrite(LATCH, HIGH);  

  digitalWrite(LATCH, LOW);   

  nButtons=(nButtons<<1)+(!digitalRead(DATA));

  for (int i=0; i < 7; i++){

    digitalWrite(CLOCK, HIGH);   

    nButtons=(nButtons<<1)+(!digitalRead(DATA));

    digitalWrite(CLOCK, LOW);    
  }

  return nButtons;

}

//-----------------------------------------------------------------

String PadNES::translateButtons(byte buttons, String separator){
  String stringNES="";

  if(bitRead(buttons, 7)){
    stringNES=stringNES+"A" + separator;
  }

  if(bitRead(buttons, 6)){
    stringNES=stringNES+"B" + separator;
  }

  if(bitRead(buttons, 5)){
    stringNES=stringNES+"select" + separator;
  }

  if(bitRead(buttons, 4)){
    stringNES=stringNES+"start" + separator;
  }

  if(bitRead(buttons, 3)){
    stringNES=stringNES+"up" + separator;
  }

  if(bitRead(buttons, 2)){
    stringNES=stringNES+"down" + separator;
  }

  if(bitRead(buttons, 1)){
    stringNES=stringNES+"left" + separator;
  }

  if(bitRead(buttons, 0)){
    stringNES=stringNES+"right" + separator;
  }
  return stringNES;

}

//-----------------------------------------------------------------

void PadNES::SchelduledReadNES(int tInterval){
  int currentTime= int(millis());
  if(nextTimeRead<=currentTime){
    nextTimeRead=nextTimeRead+tInterval;
    buttons= readNES();
  }

}

byte PadNES::getButtons(){
 return buttons; 
}


void PadNES::inipad(){
  pinMode(CLOCK, OUTPUT);     
  pinMode(LATCH, OUTPUT);
  pinMode(DATA, INPUT);

}
