#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>  
#include "constants.h"
#include "globals.h"
#include "sendDataGrafana.h"
#include "createGrafanaMessage.h"

 

void sendDataGrafana(float temperature, float humidity, float co2) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient localHttp;  // diferente (no esta)
        char device_name[64]; // nuevo

        localHttp.begin(client, URL);
        localHttp.setTimeout(5000); // Timeout de 5 segundos
        localHttp.addHeader("Content-Type", "text/plain");
        localHttp.addHeader("Authorization", "Basic " + String(TOKEN_GRAFANA));

        String mac = WiFi.macAddress(); // diferente(no esta). nuevo
        mac.replace(":", "");            // diferente(no esta). nuevo
        snprintf(device_name, sizeof(device_name), "moni-%s", mac.c_str()); // diferente(no esta). nuevo

        char message[128];
        unsigned long long timestamp = (unsigned long long)time(nullptr) * 1000000000ULL;
        createGrafanaMessage(message, sizeof(message), device_name, temperature, humidity, co2, timestamp); // diferente
        String data = String(message);

        int httpResponseCode = localHttp.POST(data);

        if (httpResponseCode == 204) {
            Serial.println("Datos enviados correctamente");
        } else {
            Serial.printf("Error en el envío: %d\n", httpResponseCode);
            Serial.println(localHttp.getString());
        }

        localHttp.end();  // diferente (no va localhttp sino el glpbal)
    } else {
        Serial.println("Error en la conexión WiFi");
    }
}