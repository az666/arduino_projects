#include <ESP8266WiFi.h>
#define LED 2
 
void smartConfig()
{
  WiFi.mode(WIFI_STA);
  Serial.println("\r\nWait for Smartconfig");
  WiFi.beginSmartConfig();
  while (1)
  {
    Serial.print(".");
    digitalWrite(LED, 0);
    delay(500);
    digitalWrite(LED, 1);
    delay(500);
    if (WiFi.smartConfigDone())
    {
      Serial.println("SmartConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      break;
    }
  }
}
 
void setup()
{
  Serial.begin(115200);
  Serial.println("Start module");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 0);
  smartConfig();
}
 
void loop()
{
  delay(100);
  Serial.println("Start module");
}
