// D4, D5, dan D19.
// 3v3, GND

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid = "import java.util.*;";
const char* password = "db_company";

const int espLed = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 19;

bool dapurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;


void setup() {
  Serial.begin(115200);

  pinMode(espLed, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  WiFi.begin(ssid, password);
  Serial.print("connecting to wifi import java.util.*...");

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(espLed, LOW);
    delay(1000);
    Serial.println(".");
  }
  digitalWrite(espLed, HIGH);
  Serial.println("");
  Serial.println("connected to wifi network!");
  Serial.println(WiFi.localIP());

  server.on("/dapur", HTTP_GET, getDapurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET, getMakanLed);

  server.on("/dapur", HTTP_POST, setDapurLed);
  server.on("/tamu", HTTP_POST, setTamuLed);
  server.on("/makan", HTTP_POST, setMakanLed);
  server.begin();
  Serial.println("Server started...");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void setDapurLed() {
  dapurLedState = !dapurLedState;
  digitalWrite(ledPin1, dapurLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void setTamuLed() {
  tamuLedState = !tamuLedState;
  digitalWrite(ledPin2, tamuLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void setMakanLed() {
  makanLedState = !makanLedState;
  digitalWrite(ledPin3, makanLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void getDapurLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void getTamuLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}


void getMakanLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}









