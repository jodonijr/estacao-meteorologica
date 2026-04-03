#pragma once
#include <DHT.h>
#include "tipos.h"
#include "calculos.h"

#define PINO_DHT 15
#define TIPO_DHT DHT22
#define PINO_ANEMOMETRO 35

DHT dht(PINO_DHT, TIPO_DHT);

void iniciarSensores() {
  dht.begin();
}

DadosMeteorologicos lerSensores() {
  DadosMeteorologicos dados;
  dados.temperatura = dht.readTemperature();
  dados.umidade = dht.readHumidity();
  dados.pressao = simularPressaoAtmosferica();
  dados.pontoOrvalho = calcularPontoOrvalho(dados.temperatura, dados.umidade);
  dados.velocidadeVento = calcularVelocidadeVento(analogRead(PINO_ANEMOMETRO));
  return dados;
}
