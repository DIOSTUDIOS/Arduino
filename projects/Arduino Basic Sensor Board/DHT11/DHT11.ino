#include <Wire.h>
#include <TM1650.h>
#include <EduIntro.h>

DHT11 dht11(D8);
TM1650 tm1650(2);

void setup()
{
  Wire.begin();

  tm1650.init();
  tm1650.displayOn();
  tm1650.clear();
}

char C[2] = "00";
char H[2] = "00";

int c = 0;
int h = 0;

void loop()
{
  dht11.update();

  c = dht11.readCelsius();
  itoa(c, C, 10);
  
  tm1650.displayString("C ");
  delay(1000);
  tm1650.displayString(C);

  delay(3000);

  h = dht11.readHumidity();
  itoa(h, H, 10);

  tm1650.displayString("H ");
  delay(1000);
  tm1650.displayString(H);

  delay(3000);
}
