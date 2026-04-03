#pragma once
#include <DHT.h>
#include "tipos.h"

#define PINO_DHT 15
#define TIPO_DHT DHT22

DHT dht(PINO_DHT, TIPO_DHT);

void iniciarSensores() {
  dht.begin();
}

DadosMetereologicos lerSensores() {
  DadosMetereologicos dados;
  dados.temperatura = dht.readTemperature();
  dados.umidade = dht.readHumidity();
  return dados;
}
