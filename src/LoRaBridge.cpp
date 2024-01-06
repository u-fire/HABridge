#include <LoRaBridge.h>

bool LoRaBridge::begin(int cs_pin, int reset_pin, int dio0_pin, long frequency)
{
    LoRa.enableCrc();
    LoRa.setPins(cs_pin, reset_pin, dio0_pin);
    if (!LoRa.begin(frequency))
    {
        return false;
    }

    return true;
}

bool LoRaBridge::send(std::string line)
{
    LoRa.beginPacket();
    LoRa.print(line.c_str());
    LoRa.endPacket();

    return true;
}