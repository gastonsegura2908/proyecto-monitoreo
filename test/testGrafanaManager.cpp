#include <unity.h>
//#include <Arduino.h>
#include "createGrafanaMessage.h"

void testSendDataGrafana() {
     //= sendDataGrafana(float temperature, float humidity, float co2);
     TEST_ASSERT_TRUE(true);

}

void testCreateGrafanaMessage() {
    std::string result = createGrafanaMessage(23.45, 55.67, 789.0);

    std::string expected = "temp=23.45,hum=55.67,co2=789.00";

    TEST_ASSERT_EQUAL_STRING(expected.c_str(), result.c_str()); 

}
