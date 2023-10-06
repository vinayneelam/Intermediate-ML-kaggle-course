/* Soil Moisture sensor pin   : GPIO34
 * Relay pin                  : GPIO13
 *
  */
#define FIREBASE_HOST "https://miniproject-1818-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "StFOCtFyegEFadIJj3YSJtkcZk6gXLTMriFg9Hyq"
#define WIFI_SSID "GLWC-1_2.4G"
#define WIFI_PASSWORD "griet@66788"
#include <Wire.h>
#include "SSD1306.h" 
#include "FirebaseESP32.h"
FirebaseData firebaseData;
SSD1306  display(0x3c, 21, 22);

#define smPin 34
#define relayPin 13
int smValue;
int smLimit = 1500;
int delayTime = 2000;
String motorStatus = "OFF";
void OLEDInit();
void OLEDUpdate();
void WiFiInit();
void FirebaseInit();
void FirebaseWrite();
void FirebaseRead();

String tag1 = "IOTLAB/Smart_Garden/Soil_Moisture";
String tag2 = "IOTLAB/Smart_Garden/Motor_Status";


void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin,OUTPUT);
  Serial.begin(115200);
  OLEDInit();
  WiFiInit();
  FirebaseInit();
  }

void loop() {
  // put your main code here, to run repeatedly:

FirebaseRead();  
smValue = 4095 - analogRead(smPin);
Serial.print("Soil Moisture = ");
Serial.println(smValue);

if (smValue < smLimit){
digitalWrite(relayPin,HIGH);
Serial.println("Motor turned ON");
motorStatus = "ON";
}
else{
digitalWrite(relayPin,LOW);
Serial.println("Motor turned OFF");
motorStatus = "OFF";
}

OLEDUpdate();
FirebaseWrite();
delay(delayTime);
}

void OLEDInit(){
  display.init();
  display.setFont(ArialMT_Plain_24);
}

void OLEDUpdate(){
  
 
  display.clear();
  display.drawString(30,0,String(smValue));
  display.drawString(30,30,String(motorStatus));
  display.display();
}

void WiFiInit(){
  pinMode(2,OUTPUT);
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
void FirebaseInit(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}
void FirebaseWrite(){
  Firebase.setInt(firebaseData,tag1,smValue);
  Firebase.setString(firebaseData,tag2,motorStatus);
  
}

void FirebaseRead(){
String smCloudFull;
String smCloud;
if(Firebase.getString(firebaseData,"IOTLAB/Smart_Garden/SM_Threshold",smCloudFull)){
smCloud = smCloudFull.substring(2,smCloudFull.length()-2);
smLimit = smCloud.toInt();
Serial.println(smLimit);
}
}
  
