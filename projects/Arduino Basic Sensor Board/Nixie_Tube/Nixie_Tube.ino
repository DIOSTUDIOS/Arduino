#include <Wire.h>
#include <TM1650.h>

TM1650 tm1650;

void setup() 
{
  Wire.begin(); //Join the bus as master
  
  tm1650.init();
  tm1650.setBrightness(TM1650_MIN_BRIGHT);

  tm1650.displayOn();
  tm1650.clear();
}

void loop() 
{
  tm1650.displayString("01");
  delay(1000);

  tm1650.displayString("03");
  delay(1000);

  tm1650.displayString("05");
  delay(1000);

  tm1650.displayString("07");
  delay(1000);

  tm1650.displayString("09");
  delay(1000);

  tm1650.setDot(0, true);
  tm1650.setDot(1, true);
  delay(1000);

  tm1650.setDot(0, false);
  tm1650.setDot(1, false);
  delay(1000);
}
