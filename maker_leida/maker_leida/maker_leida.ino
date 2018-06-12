/*
创客教育DIY倒车雷达模拟
资料为郑州三松信息技术有限公司原创
不可用于商业用途
公司主页：https://pengwenzheng.coding.me/Maker_Education
  */
#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI 
#include <SPI.h>
#endif
#include "SR04.h"//超声波模块头文件
#include <Wire.h> //I2C头文件
//###################################################
//###################################################
#define TRIG_PIN 3//定义超声波模块TRIG引脚
#define ECHO_PIN 4//定义超声波模块ECHO引脚
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);//调用函数
float a; //浮点数a
//###################################################
int beeppin = 8;  // 定义蜂鸣器的引脚
//################################################### 
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/*SCL*/ 6, /*SDA*/ 7, /* reset=*/ U8X8_PIN_NONE);   //显示屏引脚定义D6、D7
void setup ()
{
  Serial.begin(9600);
   pinMode(beeppin,OUTPUT);//定义蜂鸣器为输出模式
   u8x8.begin();
   u8x8.setPowerSave(0); 
   u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
   u8x8.draw2x2String(3, 3, "Maker");
   u8x8.drawString(0, 7, "make by sansong");
   delay(1000);
   u8x8.clear();//显示屏清屏
}
  //################################################### 主循环
void loop()
{  
     u8x8.draw2x2String(0, 3, "Distance");//在上方显示“Distance”字样
     a=sr04.Distance();//用浮点数a表示超声波距离
     u8x8.setCursor(2,7);
     u8x8.print(a);
     Serial.println(a);
  if(a<20)            //当距离<20cm,红色R灯亮，蜂鸣器急促声。
   {
     buzzer1();//蜂鸣器急促声参数
   }
   else if (a<=40)    //当距离<40cm,蓝色B灯亮，蜂鸣器短促声。
   {
     buzzer2();//蜂鸣器短促声。
   }
   else if (a>41)//当距离大于41厘米（安全距离），蜂鸣器间隔短声。
   {
     buzzer3(); //蜂鸣器间隔短声。
   }
}
  
//################################################### 蜂鸣器函数
void buzzer1()
{
   tone(beeppin,900);
   delay(150);  //声音间隔，急促声
   noTone(beeppin);
}
void buzzer2()
{
   tone(beeppin,600);
   delay(500);  //声音间隔，短促声
   noTone(beeppin);
}
void buzzer3()  
{
   noTone(beeppin);//距离过远，关闭蜂鸣器
}
