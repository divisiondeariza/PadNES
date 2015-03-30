#ifndef PAdNES_h
#define PadNES_h
#include <WString.h>
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
class PadNES
{
  public:
    PadNES(int clock, int latch, int data);
    byte readNES();
    String translateButtons(byte buttons, String separator);
    void SchelduledReadNES(int tinterval);
    byte getButtons();
void inipad();

byte RIGHT;
byte LEFT;
byte DOWN;
byte UP;
byte START;
byte SELECT;
byte B;
byte A;


private:

int CLOCK;
int LATCH;
int DATA;
int nextTimeRead;
byte buttons;

};
  #endif
