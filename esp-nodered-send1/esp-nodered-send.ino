#include <Arduino.h>

#include <WiFiClient.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char *ssid = "Do Manh";//SSID wifi
const char *password = "manh2710";//password wifi
const char *mqtt_server = "192.168.1.6";//IPv4 address
const int mqtt_port = 1883;
const char *mqtt_id = "node2";
long lastMsg = 0;
const int ledPin = 19;

RTC_DATA_ATTR float temp = 0;
 int nguong1 =20;



//DS18B20 object on pin 
OneWire oneWire(4);
DallasTemperature DS18B20(&oneWire);

WiFiClient client;
PubSubClient mqtt_client(client);

void setup() {
Serial.begin(9600);
// Đèn D2 sáng trong thời gian thức
  Serial.printf("1");
  pinMode(2, OUTPUT);
  pinMode(0, INPUT_PULLUP);
  digitalWrite(2, HIGH);
  pinMode(ledPin, OUTPUT);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_0, 0);

  Serial.print("Connecting to Wifi... ");
  Serial.print(ssid);
  Serial.println();
  WiFi.begin(ssid, password);//ket noi wifi
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to Wifi ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  delay(10);

  mqtt_client.setServer(mqtt_server, mqtt_port);//ket noi server mqtt

  Serial.println("Connecting to mqtt... ");
  while (!mqtt_client.connect(mqtt_id))
  {
    delay(10);
  }
  Serial.println("Connected to mqtt ");
 DS18B20.begin();
 //do nhiet do
  DS18B20.requestTemperatures();
  temp = DS18B20.getTempCByIndex(0); 
  Serial.println("Nhiet do la:" + String(temp));



   if(temp<nguong1){
    digitalWrite(ledPin, LOW);//tat den
  }
  else {
    digitalWrite(ledPin, HIGH);//bat den
  }
    
  mqtt_client.loop();
  long now = millis();
  if (now - lastMsg > 500) {
    lastMsg = now;

    //chuyen doi gia tri nhiet do sang mang char
    char tempString[8];
    dtostrf(temp, 1, 2, tempString);
    //Serial.print("Temperature: ");
    //Serial.println(tempString);

    mqtt_client.publish("temp/node2", tempString);
    delay(1000);
      
  }
   esp_deep_sleep_start();
}


void loop() {


}
