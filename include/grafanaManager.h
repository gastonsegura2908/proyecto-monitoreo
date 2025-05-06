#ifndef GRAFANA_MANAGER_H
#define GRAFANA_MANAGER_H

#include <Arduino.h>

String createGrafanaMessage(float temperature, float humidity, float co2);
void sendDataGrafana(float temperature, float humidity, float co2);

#endif // GRAFANA_MANAGER_H