#ifndef SEND_DATA_GRAFANA_H
#define SEND_DATA_GRAFANA_H

#include <Arduino.h>

void sendDataGrafana(float temperature, float humidity, float co2, const String& wifiStatus, const String& rotation, const String& errors);

#endif // SEND_DATA_GRAFANA_H