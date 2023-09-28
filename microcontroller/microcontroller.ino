#include <WiFi.h>
#include <PubSubClient.h>
// Wi-Fi credentials
const char* ssid = "iPhone";
const char* password = "1678namning";

// MQTT broker configuration
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

// MQTT topic
const char* topic = "led/";
const char* publedstate = "publedstate/";
bool state = false;
// Wi-Fi and MQTT client instances
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// Callback function for receiving MQTT messages
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message received: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
  }
  Serial.println();
  state = !state;
}

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  // Connect to MQTT broker and subscribe to the topic
  mqttClient.setServer(mqtt_server, mqtt_port);
  mqttClient.setCallback(callback);
  while (!mqttClient.connected()) {
    if (mqttClient.connect("ESP32_subscriber")) {
      Serial.println("Connected to MQTT broker");
      mqttClient.subscribe(topic);
    } else {
      Serial.println("Failed to connect to MQTT broker, retrying...");
      delay(1000);
    }
  }
}

void loop() {
  float x = random(201);
  float y = random(201);
  float z = 87.1;
  Serial.println(String(x)+ " "+String(y) + " "+String(z));
  mqttClient.publish(publedstate, state ? "1" : "0");
  mqttClient.loop();
  digitalWrite(2,state);
}
