HABridge
======

> Create a Home Assistant sensor from any hardware and send measurements with ESPNow or LoRa.

#### Summary ℹ️

This is a great solution for a send-only battery-operated Home Assistant device. 

This library works in conjuction with the MQTT-Bridge project described [here](https://microfire.co/articles/lora-with-espnow) and [here](https://microfire.co/articles/espnow-with-esphome). An ESP32 device is programmed to receive ESPNow or LoRa messages, processes them and then creates an MQTT-based sensor for display in Home Assistant. 

An ESP32 can be used for ESPNow messages, or any device with a LoRa radio can be used to send LoRa messages. 

Only one-way messaging works, sensor-device to Home Assistant. The following types are supported.

| Home Assistant  |  |
| ------------------- | :--------: |
| Sensor       |     ✅     |
| Binary Sensor              |     ✅     |
| Text Sensor              |     ✅     |

* * *

### Use
1. Read about the Bridge portion of this from the links above
2. Create your bridge device
3. Use this library to create a sensor device
* * *

### Ask a question 🤙

*   [Discord](https://discord.gg/rAnZPdW)
*   [questions@microfire.co](mailto:questions@microfire.co)

* * *

### Website
[microfire.co](https://microfire.co)
