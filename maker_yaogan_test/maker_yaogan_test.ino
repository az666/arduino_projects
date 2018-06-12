int X=A0;
int Y=A1;
int BUTTON=7;
void setup(void)
{
  Serial.begin(9600);//设置串口通信9600波特率
  pinMode(BUTTON,INPUT_PULLUP);
}

void loop(void)
{
  Serial.print("X=");
  Serial.print(analogRead(X));//读取摇杆X轴的值，串口显示
  Serial.print(",");

  Serial.print("Y=");
  Serial.print(analogRead(Y));//读取摇杆Y轴的值，串口显示
  Serial.print(",");

  Serial.print("BUTTON state = ");
  Serial.println(digitalRead(BUTTON));//读按键值，串口显示

  delay(100);   //100ms刷新一次
}
