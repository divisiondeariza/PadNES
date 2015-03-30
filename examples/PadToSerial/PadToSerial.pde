#include <PadNES.h>

/*
Global Variables

*/

static int CLOCK = 8;
static int LATCH = 10;
static int DATA = 7;

PadNES padNES(CLOCK, LATCH, DATA);
int anterior=0;
String sBotones;
int b;

/*
Set up serial port and NES pad. 

*/

void setup() {                

  Serial.begin(9600); 
  padNES.inipad();

}

void loop() {
  
  padNES.SchelduledReadNES(10);

  byte button= padNES.getButtons();
  b= button;
  
  if(b!=anterior&&b!=0){
  
    sBotones=padNES.translateButtons(button, " ");
    
    Serial.println(sBotones);

  }
  anterior=b;
}

