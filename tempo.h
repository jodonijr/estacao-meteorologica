#pragma once
#include <WiFi.h>
#include <time.h>

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASS = "";
const char* NTP_SERVER = "pool.ntp.org";
const long FUSO = -10800; // fuso Brasília -3 (-10800 = 60 segundos * 60 minutos * -3)

void iniciarTempo() {
  Serial.print("> conectando wi-fi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");    
    delay(500);
  }

  Serial.print(" conectado! <\n");
  configTime(FUSO, 0 /* sem horário verão */, NTP_SERVER);
  Serial.print("> sincronizando tempo NTP");
  struct tm tempo;

  while (!getLocalTime(&tempo)) {
    Serial.print(".");
    delay(500);    
  }

  Serial.print(" sincronizado! <\n");  
}

String dataHora() {
  struct tm tempo;

  if (!getLocalTime(&tempo))
    return "falha NTP";

  char tempoBuffer[50];
  strftime(tempoBuffer, sizeof(tempoBuffer), "%Y-%m-%d %H:%M:%S", &tempo);
  return String(tempoBuffer);
}
