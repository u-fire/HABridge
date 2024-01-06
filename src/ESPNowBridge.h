#pragma once
#include <cstring>
#include <string>

#include <esp_now.h>
#include <esp_wifi.h>

class ESPNowBridge
{
public:
    bool begin(uint8_t channel = 1);
    bool send(std::string line);
};