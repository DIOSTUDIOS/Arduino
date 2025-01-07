#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int S_PIN = 4;

IRrecv irrecv(S_PIN);

decode_results resultCode;

void setup()
{
  Serial.begin(9600);
  
  irrecv.enableIRIn();
}

void loop()
{
  if(irrecv.decode(&resultCode))
  {
//    Serial.println(resultCode.value);
    if(resultCode.value != 4294967295)
    {
      if(resultCode.value == 16753245)
      {
        Serial.println("开");  
      }
      
      if(resultCode.value == 16769565)
      {
        Serial.println("关");
      }
      
      if(resultCode.value == 16738455)
      {
        Serial.println("0");
      }
      
      if(resultCode.value == 16724175)
      {
        Serial.println("1");
      }
      
      if(resultCode.value == 16718055)
      {
        Serial.println("2");
      }
      
      if(resultCode.value == 16743045)
      {
        Serial.println("3");
      }
      
      if(resultCode.value == 16716015)
      {
        Serial.println("4");
      }
      
      if(resultCode.value == 16726215)
      {
        Serial.println("5");
      }
      
      if(resultCode.value == 16734885)
      {
        Serial.println("6");
      }
      
      if(resultCode.value == 16728765)
      {
        Serial.println("7");
      }
      
      if(resultCode.value == 16730805)
      {
        Serial.println("8");
      }
      
      if(resultCode.value == 16732845)
      {
        Serial.println("9");
      }
    }
    else
    {
      Serial.println("What do you want to do ?");
    }
    
    irrecv.resume();
  }
  
  delay(500);
}
