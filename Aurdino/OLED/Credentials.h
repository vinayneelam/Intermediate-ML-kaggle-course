#define FIREBASE_HOST "iot-83258-default-rtdb.firebaseio.com/" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "8AJ6uaMYXbQoGWED2b2kfLHDilxdY8OR5nX2rm4x"
#define WIFI_SSID "ZTE_2.4G_KqG7Tf"
#define WIFI_PASSWORD "eF4HQD6R"
#include <Wire.h>
#include "SSD1306.h" 
#include "FirebaseESP32.h"
FirebaseData firebaseData;
SSD1306  display(0x3c, 21, 22);
