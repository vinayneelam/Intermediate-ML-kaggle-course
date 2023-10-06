#define FIREBASE_HOST "https://miniproject-1818-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "StFOCtFyegEFadIJj3YSJtkcZk6gXLTMriFg9Hyq"
#define WIFI_SSID "ZTE_2.4G_KqG7Tf"
#define WIFI_PASSWORD "eF4HQD6R"
#include <Wire.h>
#include "SSD1306.h" 
#include "FirebaseESP32.h"
FirebaseData firebaseData;
SSD1306  display(0x3c, 21, 22);
