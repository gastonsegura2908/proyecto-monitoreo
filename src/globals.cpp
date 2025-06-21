#include <Arduino.h>
#include <WebServer.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <Adafruit_SCD30.h>
#include <WiFiManager.h>
#include "globals.h"

Adafruit_SCD30 scd30;
WiFiManager wifiManager;
WiFiClientSecure clientSecure;
WiFiClient client;
char deviceName[32] = "";
PubSubClient mqtt(client);
char mqttServer[50];
uint16_t mqttPort = 1883;
WiFiManagerParameter custom_mqtt_server("server", "MQTT Server", "", 40);
WiFiManagerParameter custom_mqtt_port("port", "MQTT Port", "", 6);
float temperature = 99, humidity = 100, co2 = 999999;