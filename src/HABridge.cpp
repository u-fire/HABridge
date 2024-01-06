#include <Arduino.h>
#include <HABridge.h>

HABridgeSensor::HABridgeSensor(std::string device_name, std::string measurement_name, SensorClass sensor_class, SensorState sensor_state, std::string unit, std::string icon, std::string board, std::string version)
{
    _device_name = device_name;
    _sensor_class = sensor_class;
    _sensor_state = sensor_state;
    _measurement_name = measurement_name;
    _unit = unit;
    _icon = icon;
    _version = version;
    _board = board;
}

std::string HABridgeSensor::line(float state, uint8_t accuracy)
{
    std::string line;

    line = _device_name;
    line += ":";
    line += _SensorClassToString(_sensor_class);
    line += ":";
    line += _SensorStateToString(_sensor_state);
    line += ":";
    line += _measurement_name;
    line += ":";
    line += _unit;
    line += ":";
    line += _to_string_with_precision(state, accuracy);
    line += ":";
    if (_icon.length() != 0)
    {
        line += _icon;
    }
    else
    {
        line += ":";
    }
    line += ":";
    line += _version;
    line += ":";
    line += _board;
    line += ":sensor:";
    return line;
}

HABridgeBinary::HABridgeBinary(std::string device_name, std::string measurement_name, std::string icon, std::string board, std::string version)
{
    _device_name = device_name;
    _measurement_name = measurement_name;
    _icon = icon;
    _version = version;
    _board = board;
}

std::string HABridgeBinary::line(bool state)
{
    std::string line;
    const char *state_s = state ? "ON" : "OFF";

    line = _device_name;
    line += ":";
    line += ":";
    line += "binary_sensor";
    line += ":";
    line += _measurement_name;
    line += ":";
    line += ":";
    line += state_s;
    line += ":";
    if (_icon.length() != 0)
    {
        line += _icon;
    }
    else
    {
        line += ":";
    }
    line += ":";
    line += _version;
    line += ":";
    line += _board;
    line += "::";
    return line;
}

HABridgeText::HABridgeText(std::string device_name, std::string measurement_name, std::string icon, std::string board, std::string version)
{
    _device_name = device_name;
    _measurement_name = measurement_name;
    _icon = icon;
    _version = version;
    _board = board;
}

std::string HABridgeText::line(std::string state)
{
    std::string line;

    line = _device_name;
    line += ":";
    line += ":";
    line += ":";
    line += _measurement_name;
    line += ":";
    line += ":";
    line += state;
    line += ":";
    if (_icon.length() != 0)
    {
        line += _icon;
    }
    else
    {
        line += ":";
    }
    line += ":";
    line += _version;
    line += ":";
    line += _board;
    line += "::";
    return line;
}

std::string HABridge::_SensorClassToString(SensorClass sensor_class)
{
    switch (sensor_class)
    {
    case SensorClass::TEMPERATURE:
        return "temperature";
    case SensorClass::HUMIDITY:
        return "humidity";
    default:
        return "";
    }
}

std::string HABridge::_SensorStateToString(SensorState sensor_state)
{
    switch (sensor_state)
    {
    case SensorState::MEASUREMENT:
        return "measurement";
    case SensorState::TOTAL:
        return "total";
    default:
        return "";
    }
}

std::string HABridge::_to_string_with_precision(float a_value, const int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return std::move(out).str();
}