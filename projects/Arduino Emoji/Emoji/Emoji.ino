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
  
  byte park_2[8][4] = {
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, park_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, park_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, park_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, park_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, park_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, park_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, park_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, park_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, park_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, park_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, park_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, park_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, park_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, park_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, park_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, park_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void tree()
{
  byte tree_1[8][4] = {
    {0x10,0x10,0x08,0x08},
    {0x38,0x38,0x1C,0x1C},
    {0x7C,0x7C,0x3E,0x3E},
    {0x38,0x38,0x1C,0x1C},
    {0x7C,0x7C,0x3E,0x3E},
    {0xFE,0xFE,0x7F,0x7F},
    {0x10,0x10,0x08,0x08},
    {0x10,0x10,0x08,0x08},
  };
  
  byte tree_2[8][4] = {
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, tree_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, tree_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, tree_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, tree_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, tree_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, tree_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, tree_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, tree_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, tree_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, tree_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, tree_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, tree_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, tree_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, tree_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, tree_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, tree_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void thank()
{
  byte thank_1[8][4] = {
    {0x03,0xC0,0x03,0xC0},
    {0x04,0x20,0x04,0x20},
    {0x00,0x20,0x04,0x20},
    {0x03,0xE0,0x04,0x20},
    {0x00,0x20,0x04,0x20},
    {0x00,0x20,0x04,0xA0},
    {0x04,0x20,0x04,0x40},
    {0x03,0xC0,0x03,0xA0},
  };
  
  byte thank_2[8][4] = {
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, thank_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, thank_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, thank_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, thank_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, thank_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, thank_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, thank_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, thank_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, thank_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, thank_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, thank_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, thank_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, thank_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, thank_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, thank_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, thank_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void slow()
{
  byte slow_1[8][4] = {
    {0x3C,0x40,0x3C,0x42},
    {0x42,0x40,0x42,0x42},
    {0x40,0x40,0x42,0x42},
    {0x3C,0x40,0x42,0x42},
    {0x02,0x40,0x42,0x42},
    {0x02,0x40,0x42,0x5A},
    {0x42,0x40,0x42,0x66},
    {0x3C,0x7E,0x3C,0x42},
  };
  
  byte slow_2[8][4] = {
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, slow_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, slow_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, slow_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, slow_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, slow_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, slow_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, slow_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, slow_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, slow_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, slow_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, slow_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, slow_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, slow_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, slow_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, slow_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, slow_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void love()
{
  byte love_1[8][4] = {
    {0x40,0x3C,0x42,0x7E},
    {0x40,0x42,0x42,0x40},
    {0x40,0x42,0x42,0x40},
    {0x40,0x42,0x42,0x7E},
    {0x40,0x42,0x42,0x40},
    {0x40,0x42,0x42,0x40},
    {0x40,0x42,0x24,0x40},
    {0x7E,0x3C,0x18,0x7E},
  };
  
  byte love_2[8][4] = {
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, love_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, love_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, love_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, love_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, love_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, love_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, love_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, love_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, love_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, love_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, love_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, love_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, love_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, love_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, love_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, love_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void mark()
{
  byte mark_1[8][4] = {
    {0x00,0x80,0x01,0x00},
    {0x01,0xC0,0x03,0x80},
    {0x01,0xC0,0x03,0x80},
    {0x01,0xC0,0x03,0x80},
    {0x01,0xC0,0x03,0x80},
    {0x00,0x80,0x01,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x80,0x01,0x00},
  };
  
  byte mark_2[8][4] = {
    {0x01,0xC0,0x03,0x80},
    {0x02,0x20,0x04,0x40},
    {0x02,0x20,0x04,0x40},
    {0x00,0x40,0x00,0x80},
    {0x00,0x80,0x01,0x00},
    {0x00,0x80,0x01,0x00},
    {0x00,0x00,0x00,0x00},
    {0x00,0x80,0x01,0x00},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, mark_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, mark_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, mark_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, mark_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, mark_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, mark_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, mark_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, mark_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, mark_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, mark_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, mark_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, mark_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, mark_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, mark_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, mark_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, mark_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void angry()
{
  byte angry_1[8][4] = {
    {0x24,0x00,0x00,0x24},
    {0x72,0x00,0x00,0x4E},
    {0x71,0x00,0x00,0x8E},
    {0x74,0x80,0x01,0x2E},
    {0x76,0x60,0x06,0x6E},
    {0x73,0x00,0x00,0xCE},
    {0x73,0x83,0xC1,0xCE},
    {0x3F,0xC6,0x63,0xFC},
  };

  byte angry_2[8][4] = {
    {0x24,0x00,0x00,0x24},
    {0x72,0x00,0x00,0x4E},
    {0x79,0x00,0x00,0x9E},
    {0x7C,0x80,0x01,0x3E},
    {0x7E,0x60,0x06,0x7E},
    {0x7F,0x00,0x00,0xFE},
    {0x7F,0x83,0xC1,0xFE},
    {0x3F,0xC6,0x63,0xFC},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, angry_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, angry_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, angry_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, angry_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, angry_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, angry_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, angry_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, angry_1[7][abs(DM-3)]);
  }

  delay(200);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, angry_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, angry_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, angry_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, angry_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, angry_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, angry_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, angry_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, angry_2[7][abs(DM-3)]);
  }

  delay(200);
}

void heart()
{
  byte heart_1[8][4] = {
    {0x00,0x06,0x60,0x00},
    {0x00,0x0F,0xF0,0x00},
    {0x24,0x0F,0xF0,0x24},
    {0x7E,0x0F,0xF0,0x7E},
    {0x7E,0x07,0xE0,0x7E},
    {0x3C,0x03,0xC0,0x3C},
    {0x18,0x01,0x80,0x18},
    {0x00,0x00,0x00,0x00},
  };
  
  byte heart_2[8][4] = {
    {0x00,0x00,0x00,0x00},
    {0x66,0x02,0x40,0x66},
    {0xFF,0x07,0xE0,0xFF},
    {0xFF,0x07,0xE0,0xFF},
    {0xFF,0x03,0xC0,0xFF},
    {0x7E,0x01,0x80,0x7E},
    {0x3C,0x00,0x00,0x3C},
    {0x18,0x00,0x00,0x18},
  };
  
  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, heart_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, heart_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, heart_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, heart_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, heart_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, heart_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, heart_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, heart_1[7][abs(DM-3)]);
  }

  delay(500);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, heart_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, heart_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, heart_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, heart_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, heart_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, heart_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, heart_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, heart_2[7][abs(DM-3)]);
  }

  delay(500);
}

void eyes()
{
  byte eyes_1[8][4] = {
    {0x0F,0x00,0x00,0xF0},
    {0x1F,0x80,0x01,0xF8},
    {0x31,0xC0,0x03,0x1C},
    {0x31,0xC0,0x03,0x1C},
    {0x31,0xC0,0x03,0x1C},
    {0x3F,0xC0,0x03,0xFC},
    {0x1F,0x82,0x41,0xF8},
    {0x0F,0x01,0x80,0xF0},
  };
  
  byte eyes_2[8][4] = {
    {0x0F,0x00,0x00,0xF0},
    {0x1F,0x80,0x01,0xF8},
    {0x38,0xC0,0x03,0x8C},
    {0x38,0xC0,0x03,0x8C},
    {0x38,0xC0,0x03,0x8C},
    {0x3F,0xC0,0x03,0xFC},
    {0x1F,0x82,0x41,0xF8},
    {0x0F,0x01,0x80,0xF0},
  };

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, eyes_1[0][abs(DM-3)]);
    DMS.setRow(DM, 1, eyes_1[1][abs(DM-3)]);
    DMS.setRow(DM, 2, eyes_1[2][abs(DM-3)]);
    DMS.setRow(DM, 3, eyes_1[3][abs(DM-3)]);
    DMS.setRow(DM, 4, eyes_1[4][abs(DM-3)]);
    DMS.setRow(DM, 5, eyes_1[5][abs(DM-3)]);
    DMS.setRow(DM, 6, eyes_1[6][abs(DM-3)]);
    DMS.setRow(DM, 7, eyes_1[7][abs(DM-3)]);
  }

  delay(1000);

  for(int DM=3; DM>=0; DM--)
  {
    DMS.setRow(DM, 0, eyes_2[0][abs(DM-3)]);
    DMS.setRow(DM, 1, eyes_2[1][abs(DM-3)]);
    DMS.setRow(DM, 2, eyes_2[2][abs(DM-3)]);
    DMS.setRow(DM, 3, eyes_2[3][abs(DM-3)]);
    DMS.setRow(DM, 4, eyes_2[4][abs(DM-3)]);
    DMS.setRow(DM, 5, eyes_2[5][abs(DM-3)]);
    DMS.setRow(DM, 6, eyes_2[6][abs(DM-3)]);
    DMS.setRow(DM, 7, eyes_2[7][abs(DM-3)]);
  }

  delay(1000);
}

void(* resetFunc)(void) = 0;

void loop()
{
  if(millis() > (30*1000))
    resetFunc();

  if(number == 0)
    park();

  if(number == 1)
    tree();

  if(number == 2)
    thank();

  if(number == 3)
    slow();

  if(number == 4)
    love();

  if(number == 5)
    mark();

  if(number == 6)
    angry();

  if(number == 7)
    heart();

  if(number == 8)
    eyes();
}
