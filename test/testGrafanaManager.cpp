#include <unity.h>
//#include <Arduino.h>
#include "createGrafanaMessage.h"

void testSendDataGrafana() {
     //= sendDataGrafana(float temperature, float humidity, float co2);
     TEST_ASSERT_TRUE(true);

}

void testCreateGrafanaMessage() {
    char buffer[64];
    createGrafanaMessage(buffer, sizeof(buffer), 23.45f, 55.67f, 789.0f);

    const char* expected = "temp=23.45,hum=55.67,co2=789.00";
    TEST_ASSERT_EQUAL_STRING(expected, buffer);
}
