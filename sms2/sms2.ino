

#define TINY_GSM_MODEM_SIM800
#define TINY_GSM_RX_BUFFER 512
//#define SerialAT Serial1
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TinyGsmClient.h>
OneWire dc(12);
DallasTemperature sen_1(&dc);
const char apn[]  = "internet.mts.ru";
const char user[] = "mts";
const char pass[] = "mts";
const char server[] = "narodmon.ru";

#include <StreamDebugger.h>
StreamDebugger debugger(Serial1, Serial);
TinyGsm modem(debugger);
TinyGsmClient client(modem);

int ch = 0;
String ts;
String val = "";

void setup() {
  delay(2000);  //время на инициализацию модуля
  sen_1.begin();
  
  Serial.begin(9600);  //скорость порта
  Serial.println("GSM tester v1.0");
  Serial1.begin(115200);
  delay(3000);
  Serial1.println("AT+CLIP=1");  //включаем АОН
  delay(100);
  Serial1.println("AT+CMGF=1");  //режим кодировки СМС - обычный (для англ.)
  delay(100);
  Serial1.println("AT+CSCS=\"GSM\"");  //режим кодировки текста
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

}
