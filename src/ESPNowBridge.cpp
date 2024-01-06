#include <ESPNowBridge.h>

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

bool ESPNowBridge::begin(uint8_t channel)
{
    esp_now_peer_info_t peerInfo = {};

    esp_netif_init();
    esp_event_loop_create_default();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();

    if (esp_now_init() != ESP_OK)
    {
        return false;
    }

    esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_LR);
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = channel;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        return false;
    }

    return true;
}

bool ESPNowBridge::send(std::string line)
{
    esp_now_send(broadcastAddress, reinterpret_cast<const uint8_t *>(&line[0]), line.size());
    return true;
}