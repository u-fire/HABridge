#include <Arduino.h>
#include <HABridge.h>
#include <ESPNowBridge.h>
#define DEVICE_NAME "test_device"

// This library is intended to work in conjuction with the ESPNow-MQTT Bridge project
// as described here: https://microfire.co/articles/espnow-with-esphome

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

ESPNowBridge now;

void setup()
{
    // start the ESPNow library
    now.begin();
}

void loop()
{
    // After getting your sensor measurement (this demo just uses rand numbers) call HABridgeSensor::line(float, precision)
    // ::send it to the bridge device
    now.send(sensor.line(rand() % 20, 2));

    // HABridgeBinary::line(bool)
    now.send(binary.line(rand() % 2));

    // HABridgeText::line(std::string)
    now.send(text.line(rand() % 2 ? "charging" : "discharging"));

    delay(5000);
}
