#include <Arduino.h>
#include <HABridge.h>
#include <LoRaBridge.h>
#define DEVICE_NAME "test_device"

// This library is intended to work in conjuction with the ESPNow-MQTT Bridge project
// as described here: https://microfire.co/articles/lora-with-espnow

// HABridgeSensor sends a measurement associated with a unit, like temperature in Celsius
// the parameters are:
// device name: a string that represents the device name (outside_temperature_box, livingroom_presence)
// sensor name: the name of the sensor (outside_temp_f)
// SensorClass: available SensorClass values are listed here: https://developers.home-assistant.io/docs/core/entity/sensor/#available-device-classes
// SensorState: available SensorState values are here: https://developers.home-assistant.io/docs/core/entity/sensor/#available-state-classes
// unit of measurement: a string that represents the unit being measured, (C, F) for display in Home Assistant
// (optional) HA icon: an explanation of icons can be found here: https://www.home-assistant.io/docs/frontend/icons/
// (optional) hardware board name for display within Home Assistant
// (optional) board version for display in Home Assistant
HABridgeSensor sensor(DEVICE_NAME, "temperature_sensor", HABridge::SensorClass::TEMPERATURE, HABridge::SensorState::MEASUREMENT, "C", "mdi:temperature-celsius");

// HABridgeBinary sends a binary state, 1/0
// the parameters are: device name, sensor name, (optional) icon, (optional) hardware board name, (optional) board version
HABridgeBinary binary(DEVICE_NAME, "binary_sensor");

// HABridgeText sends a text state, battery_charging, battery_hot, battery_discharging
// the parameters are: device name, sensor name, (optional) icon, (optional) hardware board name, (optional) board version
HABridgeText text(DEVICE_NAME, "text_sensor", "mdi:text");

// this is just a very thin wrapper of https://github.com/sandeepmistry/arduino-LoRa, all methods are exposed through LoRaBridge::
LoRaBridge lora;

void setup()
{
    // start SPI
    SPI.begin(/*SCK*/ 5, /*MISO*/19,  /*MOSI*/27,  /*SS*/18);

    // start the LoRa library with the additional pins to use the radio
    lora.begin(/*SS*/18, /*LoRa RESET*/14, /*LoRa DIO0*/35);

    // If you want to change any of these settings, be sure to read the datasheet for your radio module
    // not all combinations work and it is hardware dependent
    // additionally, some settings may not be permitted in your location
    // lora.setSyncWord(0xF3);
    // lora.setSpreadingFactor(12);
    // lora.setCodingRate4(5);
    // lora.setSignalBandwidth(250E3);
}

void loop()
{
    // After getting your sensor measurement (this demo just uses rand numbers) call HABridgeSensor::line(float, precision)
    // ::send it to the bridge device
    lora.send(sensor.line(rand() % 20, 2));

    // HABridgeBinary::line(bool)
    lora.send(binary.line(rand() % 2));

    // HABridgeText::line(std::string)
    lora.send(text.line(rand() % 2 ? "charging" : "discharging"));

    delay(5000);
}
