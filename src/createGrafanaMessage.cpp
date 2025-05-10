#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_SCD30.h>
#include <time.h>
#include <WiFiManager.h> 
#include <HTTPUpdate.h>  
#include <WiFiClientSecure.h>  
#include <esp_ota_ops.h>
#include "version.h"
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include "constants.h"
#include "globals.h"
#include "createGrafanaMessage.h"

String createGrafanaMessage(float temperature, float humidity, float co2, const String& wifiStatus, const String& rotation, const String& errors) {
    unsigned long long timestamp = time(nullptr) * 1000000000ULL;
    String message = "medicionesCO2,device=" + String(INICIALES) + 
            ",wifi=" + wifiStatus + 
            ",rotation=" + rotation +
            " temp=" + String(temperature, 2) +
            ",hum=" + String(humidity, 2) + 
            ",co2=" + String(co2) +
            ",errors=\"" + errors + "\"" + 
            " " + String(timestamp);
  
    return message;
  }
