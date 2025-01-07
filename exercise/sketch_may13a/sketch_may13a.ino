#include <LedControl.h>
 
int DIN = 12;
int CSS = 10;
int CLK = 11;

int number = 0;

LedControl DMS = LedControl(DIN, CLK, CSS, 4);
 
void setup()
{
  for(int DM=0; DM<4; DM++)
  {
    DMS.shutdown(DM, false);       //启动时，MAX72XX处于省电模式
    DMS.setIntensity(DM, 8);       //将亮度设置为最大值
    DMS.clearDisplay(DM);          //清除显示
  }

  randomSeed(analogRead(0));
  number = random(9);
}

void park()
{
  byte park_1[8][4] = {
    {0x7C,0x18,0x7C,0x44},
    {0x42,0x24,0x42,0x48},
    {0x42,0x42,0x42,0x50},
    {0x7C,0x42,0x7C,0x60},
    {0x40,0x7E,0x50,0x50},
    {0x40,0x42,0x48,0x48},
    {0x40,0x42,0x44,0x44},
    {0x40,0x42,0x42,0x42},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setColumn(DM, 0, park_1[0][abs(DM-3)]);
    DMS.setColumn(DM, 1, park_1[1][abs(DM-3)]);
    DMS.setColumn(DM, 2, park_1[2][abs(DM-3)]);
    DMS.setColumn(DM, 3, park_1[3][abs(DM-3)]);
    DMS.setColumn(DM, 4, park_1[4][abs(DM-3)]);
    DMS.setColumn(DM, 5, park_1[5][abs(DM-3)]);
    DMS.setColumn(DM, 6, park_1[6][abs(DM-3)]);
    DMS.setColumn(DM, 7, park_1[7][abs(DM-3)]);
  }
}

void loop()
{
  park();
}
