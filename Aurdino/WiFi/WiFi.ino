#include <WiFi.h>
#define WIFI_SSID "ZTE_2.4G_KqG7Tf"
#define WIFI_PASSWORD "eF4HQD6R"

void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(115200);
  WiFiInit();
 }

void loop() {
 
}

void WiFiInit(){
//Connecting to Wi-Fi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    digitalWrite(2,!digitalRead(2));
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  
}
