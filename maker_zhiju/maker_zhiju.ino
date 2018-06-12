//******************//郑州三松信息技术有限公司//***********************//
//******************//智能家居系统模拟1.0//******************//
//arduino手册地址：http://www.ocrobot.com/doku.php?id=learning
//代码下载地址： https://coding.net/u/pengwenzheng/p/maker_zhiju
#include<Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);   // RX, TX，定义0端口是接收端，1端口是发射端
Servo myservo; 
char val='/';
int pos=0;
int Bee=2;//定义蜂鸣器对应单片机端口为2
int LED=3; //定义led对应单片机端口为3
int FAN=4; //定义风扇对应单片机端口为4
int DUOJI=5;//定义开门舵机对应单片机端口为5
void setup()  //开机运行的程序代码
{
  pinMode(2,OUTPUT); //设置2号IO口为输出模式
  pinMode(3,OUTPUT); //设置3号IO口为输出模式
  pinMode(4,OUTPUT); //设置4号IO口为输出模式
  digitalWrite(2,HIGH);//设置2号IO口为初始高电平状态
  digitalWrite(4,LOW);//设置4号IO口为初始低电平状态
  Serial.begin(9600);//设置串口波特率为9600
  myservo.attach(5);//设置舵机连接口为5号IO口
} 
void loop()                         // 循环执行的程序代码
{           
    val=Serial.read();              //接收数据
      switch (val){
      case '1': ledopen();  break;
      case '2': ledclose(); break;
      case '3': dooropen(); break;
      case '4': doorclose(); break;
      case '5': fanopen();  break;
      case '6': fanclose(); break;
      //以上数据对应手机APP控制代码
    }
}
////////////////////////////////////////////
void fanopen() // 定义开风扇函数
{
  bee();
  digitalWrite(4,HIGH);
  }
void fanclose() // 定义关风扇函数
{
  bee();
  digitalWrite(4,LOW);
  }
void dooropen() // 定义开门函数
{  
  bee();
for(pos = 0; pos <= 180; pos += 1) // 此处依靠for循环来实现舵机从0度旋转到180度的控制。 
{                                  
   myservo.write(pos);              
   delay(15);                      
} 
  }
void doorclose() //定义关门函数
{
 bee();
   for(pos = 180; pos>=0; pos-=1) // 此处依靠for循环来实现舵机从180度旋转到0度的控制。   
{                                
    myservo.write(pos);           
    delay(15);                       
}   
  }
void ledopen() // 定义LED开启函数
{
  bee();
  digitalWrite(3,HIGH); 
  }
 void ledclose() //定义LED关闭函数
  {
    bee();
    digitalWrite(3,LOW); 
   }
 void bee() //定义蜂鸣器函数
 {
  tone(2,500,500);//tone函数驱动蜂鸣器。
  delay(200);
  tone(2,800,500);
  }


