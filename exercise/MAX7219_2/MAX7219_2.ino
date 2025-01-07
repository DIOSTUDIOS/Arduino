#include "LedControl.h"

int DIN = 12;
int CSS = 10;
int CLK = 11;

LedControl lc = LedControl(DIN, CLK ,CSS, 2);

void setup()
{
  int devices = lc.getDeviceCount();
  
  for(int address=0; address<devices; address++)
  {
    lc.shutdown(address,false);
    lc.setIntensity(address,8);
    lc.clearDisplay(address);
  }

  Serial.begin(9600);
  Serial.println(devices);
}

void loop()
{ 
  //read the number cascaded devices
  int devices = lc.getDeviceCount();
  
  //we have to init all devices in a loop
  for(int row=0; row<8; row++)
  {
    for(int col=0; col<8; col++)
    {
      for(int address=0; address<devices; address++)
      {
//        delay(delaytime);
        lc.setLed(address,row,col,true);
        delay(100);
//        lc.setLed(address,row,col,false);
      }
    }
  }
}
