#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "vibration-project-id.firebaseio.com"
#define FIREBASE_AUTH "vibration-database-secret"
#define WIFI_SSID "kumbu"
#define WIFI_PASSWORD "kiko1234"


FirebaseData fbdo;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  float vibration = analogRead(A0); // Simulate sensor input
  String path = "/Machines/Machine_1/vibration_level";
  if (Firebase.setFloat(fbdo, path, vibration)) {
    Serial.println("Data sent successfully.");
  } else {
    Serial.println("Error sending data.");
  }
  delay(5000);
}
