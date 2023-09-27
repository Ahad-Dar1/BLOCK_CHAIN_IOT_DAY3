/**
 * @file config.h
 * @brief Configuration constants for the project.
 * 
 * This header defines the constants used throughout the project, such as WiFi credentials
 * and server endpoints.
 */

#ifndef CONFIG_H
#define CONFIG_H

// WiFi Configuration
/** 
 * @brief SSID of the Access Point.
 */
#define AP_SSID             "SiiconNxusStorm"

/** 
 * @brief Password for the WiFi.
 */
#define WIFI_PASS           "embedded123S"

/** 
 * @brief Timer Tick for connection to establish.
 */
#define Wifi_Timer_Count 5

// Checkers

/** 
 * @brief Timer Tick for connection to establish.
 */
#define FALSE 0

/** 
 * @brief Timer Tick for connection to establish.
 */
#define TRUE 1

// Server Configuration
/** 
 * @brief URL of the server endpoint.
 * 
 * This is the primary endpoint used for communication with the server.
 */
#define SERVER_URL          "http://192.168.18.118:8002/GetDeviceHDD1"

#endif // CONFIG_H
