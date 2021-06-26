
#include <WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200); 

    WiFiManager wifiManager;
    wifiManager.resetSettings();
    wifiManager.autoConnect("CIRCUIT DIGEST WiFi Manager");
    Serial.println("connected :)");
  
}
void loop() { 
  if (WiFi.status() == WL_CONNECTED)
        {
          while(WiFi.status() == WL_CONNECTED){           
            Serial.println("connected :)");   
          }              
        }
    
}
