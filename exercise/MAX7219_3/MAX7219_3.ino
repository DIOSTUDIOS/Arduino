#include <LedControl.h>
 
int DIN = 12;
int CSS = 10;
int CLK = 11;

LedControl DM = LedControl(DIN, CLK, CSS,4);
 
void setup()
{
  int devices = DM.getDeviceCount();

  for(int address=0; address<devices; address++)
  {
    DM.shutdown(address, false);       //启动时，MAX72XX处于省电模式
    DM.setIntensity(address, 1);       //将亮度设置为最大值
    DM.clearDisplay(address);         //清除显示
  }
}

byte row0[4] = {0x00, 0xC0, 0x00, 0x08};
byte row1[4] = {0xA2, 0x19, 0x20, 0x14};
byte row2[4] = {0x00, 0x48, 0x00, 0xA2};
byte row3[4] = {0x0A, 0x20, 0x34, 0x10};
byte row4[4] = {0x20, 0x04, 0x01, 0x0C};
byte row5[4] = {0x28, 0x80, 0x40, 0x24};
byte row6[4] = {0x02, 0x48, 0x88, 0x00};
byte row7[4] = {0x28, 0x00, 0x05, 0x42};

void loop()
{
  for(int address=3; address>-1; address--)
  {
    DM.setRow(address, 0, row0[abs(address-3)]);
    DM.setRow(address, 1, row1[abs(address-3)]);
    DM.setRow(address, 2, row2[abs(address-3)]);
    DM.setRow(address, 3, row3[abs(address-3)]);
    DM.setRow(address, 4, row4[abs(address-3)]);
    DM.setRow(address, 5, row5[abs(address-3)]);
    DM.setRow(address, 6, row6[abs(address-3)]);
    DM.setRow(address, 7, row7[abs(address-3)]);
  }
}
