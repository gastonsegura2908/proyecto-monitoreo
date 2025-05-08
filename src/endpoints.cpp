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
#include "endpoints.h"
#include "globals.h"

void handleMediciones() {
    float temperature = 0.0, humidity = 0.0, co2 = 0.0;
    #if defined(MODO_SIMULACION)
      // Datos simulados
      temperature = 22.5 + random(-100, 100) * 0.01;
      humidity = 50 + random(-500, 500) * 0.01;
      co2 = 400 + random(0, 200);
    #else
      if (scd30.dataReady() && scd30.read()) {
        temperature = scd30.temperature;
        humidity = scd30.relative_humidity;
        co2 = scd30.CO2;
      }
      if (!scd30.dataReady()) {
        server.send(503, "application/json", "{\"error\": \"Datos no disponibles aún\"}");
        return;
      }
    #endif  
  
    String json = "{";
    json += "\"temperatura\": " + String(temperature, 2) + ",";
    json += "\"humedad\": " + String(humidity, 2) + ",";
    json += "\"co2\": " + String(co2, 2);
    json += "}";
  
    server.send(200, "application/json", json);
  }
  
void handleConfiguracion() {
    File file = SPIFFS.open("/config.json", FILE_READ);
    if (!file || file.isDirectory()) {
    server.send(500, "application/json", "{\"error\": \"No se pudo abrir config.json\"}");
    return;
    }

    String json = file.readString();  // Leer el contenido completo
    file.close();

    server.send(200, "application/json", json);
}