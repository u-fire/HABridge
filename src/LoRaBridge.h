#pragma once
#include <cstring>
#include <string>
#include <SPI.h>
#include "LoRa.h"

class LoRaBridge: public LoRaClass
{
public:
    bool begin(int cs_pin = 18, int reset_pin = 14, int dio0_pin = 26, long frequency = 915000000);
    bool send(std::string line);
};