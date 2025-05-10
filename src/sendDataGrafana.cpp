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
#include "sendDataGrafana.h"
#include "createGrafanaMessage.h"

void sendDataGrafana(float temperature, float humidity, float co2, const String& wifiStatus, const String& rotation, const String& errors) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient localHttp;  

        localHttp.begin(client, URL);
        localHttp.setTimeout(5000); // Timeout de 5 segundos
        localHttp.addHeader("Content-Type", "text/plain");
        localHttp.addHeader("Authorization", "Basic " + String(TOKEN_GRAFANA));
        String data = createGrafanaMessage(temperature, humidity, co2, wifiStatus, rotation, errors);

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