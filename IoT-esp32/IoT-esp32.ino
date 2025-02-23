#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

// Pin where the DHT sensor is connected
#define DHTPIN 12      
// DHT11(Blue color) or DHT22(White color) sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// On the same WIFI network backend server is running
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* serverURL = "http://YOUR_SERVER_IP:3000/data";

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temp) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    HTTPClient http;
    http.setTimeout(2000);  // Set 2-second timeout
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{\"temperature\":" + String(temp) + ",\"humidity\":" + String(humidity) + "}";
    Serial.println(jsonData);
    int httpResponseCode = http.POST(jsonData);
    if (httpResponseCode > 0) {
      Serial.println("Data sent successfully");
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
  // Wait for 5 seconds
  delay(5000); 
}
