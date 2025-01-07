#include <Wire.h>
#include <PS2X_lib.h>
#include <AFMotor.h>
//创建电机实例
AF_DCMotor LF_Motor(1);
AF_DCMotor LB_Motor(2);
AF_DCMotor RF_Motor(3);
AF_DCMotor RB_Motor(4);
//定义手柄接口
#define DAT       14    
#define CMD       15
#define SEL       16
#define CLK       17
#define pressures false
#define rumble    false

int   error   = 0;
byte  type    = 0;
byte  vibrate = 0;
//创建手柄实例
PS2X handle;

void setup()
{
  //灯光
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  //喇叭
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  
  LF_Motor.setSpeed(0);
  LB_Motor.setSpeed(0);
  RF_Motor.setSpeed(0);
  RB_Motor.setSpeed(0);
  
//  LF_Motor.run(RELEASE);
//  LB_Motor.run(RELEASE);
//  RF_Motor.run(RELEASE);
//  RB_Motor.run(RELEASE);

  Serial.begin(57600);
  
  error = handle.config_gamepad(CLK, CMD, SEL, DAT, pressures, rumble);

  if(error == 0)
  {
    Serial.println("手柄连接且配置成功！");

    if(pressures)
      Serial.println("pressures = " + pressures);

    if(rumble)
      Serial.println("rumble    = " + rumble);
  }
  else if(error == 1)
    Serial.println("手柄连接错误！！！");
  else if(error == 2)
    Serial.println("手柄连接成功，但无法接收命令！！！");
  else if(error == 3)
    Serial.println("此手柄不支持震动模式！");

  type = handle.readType();

  switch(type)
  {
    case 0:
      Serial.println("未知设备");
      break;
    case 1:
      Serial.println("DualShock 类型");
      break;
    case 2:
      Serial.println("GuitarHero 类型");
      break;
    case 3:
      Serial.println("无线 DualShock 类型");
      break;
    default:
      break;
  }

  delay(3000);
}

void loop()
{
  if(error == 1)
    return;

  if(type == 2)
    return;
  else
  {
    //获取手柄命令
    handle.read_gamepad(false, vibrate);
    
    if(handle.Button(PSB_PAD_UP))
    {
      move_forward();
      Serial.println("Move Forward");
    }
    else if(handle.Button(PSB_PAD_DOWN))
    {
      move_backward();
      Serial.println("Move Backward");
    }
    else if(handle.Button(PSB_PAD_LEFT))
    {
      turn_left();
      Serial.println("Turn Left");
    }
    else if(handle.Button(PSB_PAD_RIGHT))
    {
      turn_right();
      Serial.println("Turn Right");
    }
    else if(handle.Button(PSB_L1))
    {
      move_LF();
      Serial.println("Move to Left Forward");
    }
    else if(handle.Button(PSB_L2))
    {
      move_LB();
      Serial.println("Move to Left Backward");
    }
    else if(handle.Button(PSB_R1))
    {
      move_RF();
      Serial.println("Monve to Right Forward");
    }
    else if(handle.Button(PSB_R2))
    {
      move_RB();
      Serial.println("Move to Right Backward");
    }
    else
    {
      LF_Motor.setSpeed(0);
      LB_Motor.setSpeed(0);
      RF_Motor.setSpeed(0);
      RB_Motor.setSpeed(0);
    
  //    LF_Motor.run(RELEASE);
  //    LB_Motor.run(RELEASE);
  //    RF_Motor.run(RELEASE);
  //    RB_Motor.run(RELEASE);
    }

    if(handle.ButtonPressed(PSB_SQUARE))
      digitalWrite(9, HIGH);

    if(handle.ButtonPressed(PSB_CROSS))
      digitalWrite(9, LOW);

    if(handle.ButtonPressed(PSB_TRIANGLE))
      digitalWrite(10, LOW);

    if(handle.ButtonPressed(PSB_CIRCLE))
      digitalWrite(10, HIGH);
  }

  delay(100);
}
//前进
void move_forward()
{
  LF_Motor.setSpeed(200);
  LB_Motor.setSpeed(200);
  RF_Motor.setSpeed(200);
  RB_Motor.setSpeed(200);
  
  LF_Motor.run(FORWARD);
  LB_Motor.run(FORWARD);
  RF_Motor.run(FORWARD);
  RB_Motor.run(FORWARD);
}
//后退
void move_backward()
{
  LF_Motor.setSpeed(200);
  LB_Motor.setSpeed(200);
  RF_Motor.setSpeed(200);
  RB_Motor.setSpeed(200);
  
  LF_Motor.run(BACKWARD);
  LB_Motor.run(BACKWARD);
  RF_Motor.run(BACKWARD);
  RB_Motor.run(BACKWARD);
}
//向左转
void turn_left()
{
  LF_Motor.setSpeed(200);
  LB_Motor.setSpeed(200);
  RF_Motor.setSpeed(200);
  RB_Motor.setSpeed(200);
  
  LF_Motor.run(BACKWARD);
  LB_Motor.run(BACKWARD);
  RF_Motor.run(FORWARD);
  RB_Motor.run(FORWARD);
}
//向右转
void turn_right()
{
  LF_Motor.setSpeed(200);
  LB_Motor.setSpeed(200);
  RF_Motor.setSpeed(200);
  RB_Motor.setSpeed(200);
  
  LF_Motor.run(FORWARD);
  LB_Motor.run(FORWARD);
  RF_Motor.run(BACKWARD);
  RB_Motor.run(BACKWARD);
}
//向左前方移动
void move_LF()
{
  LF_Motor.setSpeed(100);
  LB_Motor.setSpeed(100);
  RF_Motor.setSpeed(255);
  RB_Motor.setSpeed(255);

  LF_Motor.run(FORWARD);
  LB_Motor.run(FORWARD);
  RF_Motor.run(FORWARD);
  RB_Motor.run(FORWARD);
}
//向左后方移动
void move_LB()
{
  LF_Motor.setSpeed(100);
  LB_Motor.setSpeed(100);
  RF_Motor.setSpeed(255);
  RB_Motor.setSpeed(255);

  LF_Motor.run(BACKWARD);
  LB_Motor.run(BACKWARD);
  RF_Motor.run(BACKWARD);
  RB_Motor.run(BACKWARD);
}
//向右前方移动
void move_RF()
{
  LF_Motor.setSpeed(255);
  LB_Motor.setSpeed(255);
  RF_Motor.setSpeed(100);
  RB_Motor.setSpeed(100);

  LF_Motor.run(FORWARD);
  LB_Motor.run(FORWARD);
  RF_Motor.run(FORWARD);
  RB_Motor.run(FORWARD);
}
//向右后方移动
void move_RB()
{
  LF_Motor.setSpeed(255);
  LB_Motor.setSpeed(255);
  RF_Motor.setSpeed(100);
  RB_Motor.setSpeed(100);

  LF_Motor.run(BACKWARD);
  LB_Motor.run(BACKWARD);
  RF_Motor.run(BACKWARD);
  RB_Motor.run(BACKWARD);
}
