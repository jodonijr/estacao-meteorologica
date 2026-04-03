#pragma once
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "tipos.h"

const char* MQTT_BROKER = "broker.hivemq.com";
const int MQTT_PORT = 1883;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void iniciarMQTT() {
  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
}

String gerarIdEstacao() {
  return "EM-" + String(random(0xffff), HEX);
}

void reconectarMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("> mqtt: conectando ao broker.");

    if (mqttClient.connect(gerarIdEstacao().c_str()))
      Serial.println(" conectado! <");
    else {
      Serial.print(".");
      delay(5000);
    }
  }
}

void manterMQTT() {
  if (!mqttClient.connected())
    reconectarMQTT();
  
  mqttClient.loop();
}

const char* MQTT_TOPIC = "uvsp-pi-v/estacao-meteorologica";

void publicarMQTT(DadosMeteorologicos dados) {
  JsonDocument json;
  json["dataHora"] = dados.dataHora;
  json["temperatura"] = dados.temperatura;
  json["umidade"] = dados.umidade;
  json["pressao"] = dados.pressao;
  json["pontoOrvalho"] = dados.pontoOrvalho;
  json["velocidadeVento"] = dados.velocidadeVento;
  json["radiacaoSolar"] = dados.radiacaoSolar;
  json["chuvaAcumulada"] = dados.chuvaAcumulada;
  char payload[512];
  serializeJson(json, payload);
  Serial.print("> mqtt: publicando: ");
  Serial.println(payload);
  mqttClient.publish(MQTT_TOPIC, payload);
  Serial.print(". publicado! <\n");
}
