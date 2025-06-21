#ifndef GLOBALS_H
#define GLOBALS_H

#include <WebServer.h>
#include <Adafruit_SCD30.h>
#include <WiFiManager.h>
#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <PubSubClient.h>

extern Adafruit_SCD30 scd30;
extern WiFiManager wifiManager;
extern WiFiClientSecure clientSecure;
extern WiFiClient client;
extern char deviceName[32];
extern PubSubClient mqtt;
extern char mqttServer[50];
extern uint16_t mqttPort;
extern WiFiManagerParameter custom_mqtt_server;
extern WiFiManagerParameter custom_mqtt_port;
extern float temperature, humidity, co2;

#endif // GLOBALS_H