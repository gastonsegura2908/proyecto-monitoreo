#include "createGrafanaMessage.h"
#include <cstdio>

void createGrafanaMessage(char* buffer, size_t bufferSize, float temperature, float humidity, float co2) {
    snprintf(buffer, bufferSize, "temp=%.2f,hum=%.2f,co2=%.2f", temperature, humidity, co2);
}
