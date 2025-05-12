#include <string>
#include <sstream>
#include <iomanip>

std::string createGrafanaMessage(float temperature, float humidity, float co2) {
    std::ostringstream message;
    message << "temp=" << std::fixed << std::setprecision(2) << temperature
            << ",hum=" << std::fixed << std::setprecision(2) << humidity
            << ",co2=" << std::fixed << std::setprecision(2) << co2;

    return message.str();
}
