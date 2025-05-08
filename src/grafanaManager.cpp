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
#include "grafanaManager.h"

String createGrafanaMessage(float temperature, float humidity, float co2) {
    unsigned long long timestamp = time(nullptr) * 1000000000ULL;
    String message = "medicionesCO2,device=" + String(INICIALES) + 
                     " temp=" + String(temperature, 2) +
                     ",hum=" + String(humidity, 2) + 
                     ",co2=" + String(co2) + 
                     " " + String(timestamp);
  
    return message;
  }
  
void sendDataGrafana(float temperature, float humidity, float co2) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient localHttp;  

        localHttp.begin(client, URL);
        localHttp.setTimeout(5000); // Timeout de 5 segundos
        localHttp.addHeader("Content-Type", "text/plain");
        localHttp.addHeader("Authorization", "Basic " + String(TOKEN_GRAFANA));
        String data = createGrafanaMessage(temperature, humidity, co2);

        int httpResponseCode = localHttp.POST(data);

        if (httpResponseCode == 204) {
            Serial.println("Datos enviados correctamente");
        } else {
            Serial.printf("Error en el envío: %d\n", httpResponseCode);
            Serial.println(localHttp.getString());
        }

        localHttp.end();  
    } else {
        Serial.println("Error en la conexión WiFi");
    }
}