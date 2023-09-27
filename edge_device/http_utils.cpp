#include "http_utils.h"

void sendDataToServer() {

    // Create a JSON object to store device data.
    StaticJsonDocument<200> jsonDocument;
    jsonDocument["DeviceName"] = "Silicon ___a";

    // Convert (serialize) the JSON object to a String format.
    String jsonData;
    serializeJson(jsonDocument, jsonData);

    // Initialize an HTTP client to send data to a server.
    HTTPClient httpClient;
    httpClient.begin(SERVER_URL);

    // Set the content type of the HTTP request to JSON.
    httpClient.addHeader("Content-Type", "application/json");

    // Send a POST request with the JSON data to the server.
    int httpResponseCode = httpClient.POST(jsonData);

    // If the server responded with a positive response code
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // Check the server's response code.
    if (httpResponseCode > 0) {
        // Get the server's response message and print it to the serial port.
        String serverResponse = httpClient.getString();
        Serial.println(serverResponse);
    } else {
        // If the HTTP request failed, print an error message to the serial port.
        Serial.println("HTTP request failed");
    }
}