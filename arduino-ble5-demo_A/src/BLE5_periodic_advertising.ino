/*
   Simple BLE5 multi advertising example on esp32 C3/S3
   only ESP_BLE_GAP_SET_EXT_ADV_PROP_NONCONN_NONSCANNABLE_UNDIRECTED can be used for periodic advertising

   author: chegewara
*/

#include <BLEDevice.h>
#include <BLEAdvertising.h>
#include <Arduino.h> // to get Serial defn

// WARNING ADD THIS TO PLATFORM.INI WHEN USING PLATFORMIO. Arduino, do different way.
//   lib_deps = adafruit/Adafruit NeoPixel

#include <Adafruit_NeoPixel.h> 
#define LED_PIN 48

// #define LED_PIN 2   // onboard LED on most ESP32-S3 dev boards

esp_ble_gap_ext_adv_params_t ext_adv_params_2M = {
    .type = ESP_BLE_GAP_SET_EXT_ADV_PROP_NONCONN_NONSCANNABLE_UNDIRECTED,
    .interval_min = 0x40,
    .interval_max = 0x40,
    .channel_map = ADV_CHNL_ALL,
    .own_addr_type = BLE_ADDR_TYPE_RANDOM,
    .filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
    .primary_phy = ESP_BLE_GAP_PHY_1M,
    .max_skip = 0,
    .secondary_phy = ESP_BLE_GAP_PHY_2M,
    .sid = 1,
    .scan_req_notif = false,
};

// copilot!!
static uint8_t raw_scan_rsp_data_2m[] = {
    0x02, 0x01, 0x06,          // Flags
    0x02, 0x0A, 0xEB,          // TX power
    0x1B, 0x09,                // Length (27), Type = Complete Local Name
    'Z','_','w','o','r','k',' ',
    'a','r','d','u','i','n','o','-',
    'b','l','e','5','-','d','e','m','o','_','A',
    0x00                       // optional terminator
};

// static uint8_t raw_scan_rsp_data_2m[] = {
//         0x02, 0x01, 0x06,
//         0x02, 0x0a, 0xeb,
//         0x12, 0x09, 'Z', 'S', 'P', '_', 'M', 'U', 'L', 'T', 'I', '_', 'A',
//         'D', 'V', '_', '2', 'M', 0X0
// };

static esp_ble_gap_periodic_adv_params_t periodic_adv_params = {
    .interval_min = 0x320, // 1000 ms interval
    .interval_max = 0x640,
    .properties = 0, // Do not include TX power
};
static uint8_t periodic_adv_raw_data[] = {
    0x02, 0x01, 0x06,
    0x02, 0x0A, 0xEB,
    0x03, 0x03, 0xAB, 0xCD,
    0x14, 0x09,                      // length=20, type=Complete Local Name
    'l','e','d',' ','d','o','u','b','l','e',' ',
    'f','l','a','s','h',' ','b','t',
    0x00                             // optional terminator
};

// static uint8_t periodic_adv_raw_data[] = {
//         0x02, 0x01, 0x06,
//         0x02, 0x0a, 0xeb,
//         0x03, 0x03, 0xab, 0xcd,
//         0x11, 0x09, 'E', 'S', 'P', '_', 'P', 'E', 'R', 'I', 'O', 'D', 'I',
//         'C', '_', 'A', 'D', 'V'
// };


uint8_t addr_2m[6] = {0xc0, 0xde, 0x52, 0x00, 0x00, 0x02};

BLEMultiAdvertising advert(1); // max number of advertisement data 
// setup global variable "pixel". this board uses NeoPixel by adafruit
Adafruit_NeoPixel pixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  Serial.println("lenovo Multi-Advertising...");

  //     neopixelWrite(48, 0, 0, 0); // turn off annoying bright white led
  //pinMode(LED_PIN, OUTPUT); // <--- add this
  // this board uses NeoPixel by adafruit
  Adafruit_NeoPixel pixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);
  pixel.begin();
  // pixel.setBrightness(5);   // optional
  pixel.show();              // turn off initially


  BLEDevice::init("");

  advert.setAdvertisingParams(0, &ext_adv_params_2M);
  advert.setAdvertisingData(0, sizeof(raw_scan_rsp_data_2m), &raw_scan_rsp_data_2m[0]);
  advert.setInstanceAddress(0, addr_2m);
  advert.setDuration(0, 0, 0);

  delay(100);
  advert.start();
  advert.setPeriodicAdvertisingParams(0, &periodic_adv_params);
  advert.setPeriodicAdvertisingData(0, sizeof(periodic_adv_raw_data), &periodic_adv_raw_data[0]);
  advert.startPeriodicAdvertising(0);
}

int ct = 0;
void loop() {
  Serial.printf("one loop %d\n", ct++);
  // First flash
  pixel.setPixelColor(0, pixel.Color(255, 0, 0));
  pixel.setBrightness(44);
  pixel.show();
  delay(22);

  // 300 ms gap
  pixel.setPixelColor(0, pixel.Color(0, 0, 0));
  pixel.show();
  delay(600);

  // Second flash
  pixel.setPixelColor(0, pixel.Color(0, 255, 0));
  pixel.show();
  delay(22);

  // 700 ms gap before repeating
  pixel.setPixelColor(0, pixel.Color(0, 0, 0));
  pixel.show();
  delay(700);
}

// void loop() {
//   delay(2000);
// }

// void loop() {
//   digitalWrite(LED_PIN, HIGH);   // LED ON
//   delay(500);                    // 0.5 sec

//   digitalWrite(LED_PIN, LOW);    // LED OFF
//   delay(1000);                   // 1 sec
// }

// void loop() {
//   pixel.setPixelColor(0, pixel.Color(255, 0, 0));  // red ON
//   pixel.setBrightness(5);
//   pixel.show();
//   delay(500);

//   pixel.setPixelColor(0, pixel.Color(0, 0, 0));    // OFF
//   pixel.show();
//   delay(1000);
// }
