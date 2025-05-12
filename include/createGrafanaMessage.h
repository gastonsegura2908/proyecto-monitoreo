#ifndef CREATE_GRAFANA_MESSAGE_H
#define CREATE_GRAFANA_MESSAGE_H

//#include <Arduino.h>
#include <string>

std::string createGrafanaMessage(float temperature, float humidity, float co2);

#endif // CREATE_GRAFANA_MESSAGE_H