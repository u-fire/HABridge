#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#define BOARD "esp32dev"
#define VERSION "HAB-0.0.1"
class HABridge
{
public:
    enum SensorClass
    {
        APPARENT_POWER,
        AQI,
        ATMOSPHERIC_PRESSURE,
        BATTERY,
        CO2,
        CO,
        CURRENT,
        DATA_RATE,
        DATA_SIZE,
        DATE,
        DISTANCE,
        DURATION,
        ENERGY,
        ENERGY_STORAGE,
        ENUM,
        FREQUENCY,
        GAS,
        HUMIDITY,
        ILLUMINANCE,
        IRRADIANCE,
        MOISTURE,
        MONETARY,
        NITROGEN_DIOXIDE,
        NITROGEN_MONOXIDE,
        NITROUS_OXIDE,
        OZONE,
        PH,
        PM1,
        PM25,
        PM10,
        POWER,
        POWER_FACTOR,
        PRECIPITATION,
        PRECIPITATION_INTENSITY,
        PRESSURE,
        REACTIVE_POWER,
        SIGNAL_STRENGTH,
        SOUND_PRESSURE,
        SPEED,
        SULPHUR_DIOXIDE,
        TEMPERATURE,
        TIMESTAMP,
        VOLATILE_ORGANIC_COMPOUNDS,
        VOLATILE_ORGANIC_COMPOUNDS_PARTS,
        VOLTAGE,
        VOLUME,
        VOLUME_STORAGE,
        WATER,
        WEIGHT,
        WIND_SPEED
    };
    enum SensorState
    {
        MEASUREMENT,
        TOTAL,
        TOTAL_INCREASING
    };

protected:
    std::string _device_name;
    SensorClass _sensor_class;
    SensorState _sensor_state;
    std::string _measurement_name;
    std::string _unit;
    std::string _icon;
    std::string _version;
    std::string _board;

    std::string _SensorClassToString(SensorClass sensor_class);
    std::string _SensorStateToString(SensorState sensor_state);
    std::string _to_string_with_precision(const float a_value, const int n);
};

class HABridgeSensor : public HABridge
{
public:
    HABridgeSensor(std::string device_name,  std::string measurement_name, SensorClass sensor_class, SensorState sensor_state, std::string unit, std::string icon = "", std::string board = BOARD, std::string version = VERSION);
    std::string line(float state, uint8_t accuracy);
};

class HABridgeBinary : public HABridge
{
public:
    HABridgeBinary(std::string device_name, std::string measurement_name, std::string icon = "", std::string board = BOARD, std::string version = VERSION);
    std::string line(bool state);
};

class HABridgeText : public HABridge
{
public:
    HABridgeText(std::string device_name, std::string measurement_name, std::string icon = "", std::string board = BOARD, std::string version = VERSION);
    std::string line(std::string state);
};