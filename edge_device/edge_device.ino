#include "spiffs_utils.h"
#include "wifi_utils.h"
#include "http_utils.h"
#include <esp_system.h>
#include <cstdlib> // Include the cstdlib library for exit()

//Device name 1,2,3,..etc
int Device_name_int=2;

// The setup function runs once when the device starts/restarts.
void setup() {

    Serial.begin(115200);

    // Initialize SPIFFS
    initSPIFFS();

    // Wait for a second before proceeding.
    delay(1000);
    
    //Initialize Buffer to store Device name as character string
    const char* Device_name_char = String(Device_name_int).c_str();
    
    // Check or generate hash key
    checkOrGenerateHashKey(Device_name_char);

    // Start the process of connecting to a WiFi network.
    Serial.println("Connecting to WiFi...");

    // Connect to WiFi
    uint8_t WIFI_STATUS=connectToWiFi();
    if (WIFI_STATUS) {
      Serial.println("Connection Established");
      }
    else{
      Serial.println("Connection Failed");
     } 
}

// The loop function runs continuously after the setup function completes.
void loop() {

    sendDataToServer();
    delay(10000);  // Delay for 10 seconds before next loop
}
