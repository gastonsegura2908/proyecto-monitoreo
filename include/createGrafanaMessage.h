#ifndef CREATE_GRAFANA_MESSAGE_H
#define CREATE_GRAFANA_MESSAGE_H

#include <Arduino.h>

String createGrafanaMessage(float temperature, float humidity, float co2, const String& wifiStatus, const String& rotation, const String& errors);

#endif // CREATE_GRAFANA_MESSAGE_H