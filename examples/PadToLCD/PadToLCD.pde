#include <PadNES.h>
#include <LiquidCrystal.h>


PadNES padNES(8, 10, 7);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  
int anterior=0;


void setup() {                

  lcd.begin(16, 2);
  lcd.clear();
  padNES.inipad();


}

void loop() {

  lcd.setCursor(0,0);   
  lcd.print("NES Pad");
  
  padNES.SchelduledReadNES(10);

  byte button= padNES.getButtons();

  int b= button;
  if(b!=anterior&&b!=0){
    String sBotones=padNES.translateButtons(button, " ");
    lcd.clear();
    lcd.setCursor(0,1); 
    lcd.print(sBotones);
  }
  anterior=b;
}

