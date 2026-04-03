#pragma once
#include <DHT.h>
#include "tipos.h"
#include "calculos.h"
#include "pluviometro.h"

#define PINO_DHT 15
#define TIPO_DHT DHT22
#define PINO_ANEMOMETRO 35
#define PINO_LDR 34

DHT dht(PINO_DHT, TIPO_DHT);

void iniciarSensores() {
  dht.begin();
  iniciarPluviometro();
}

DadosMeteorologicos lerSensores() {
  DadosMeteorologicos dados;
  dados.temperatura = dht.readTemperature();
  dados.umidade = dht.readHumidity();
  dados.pressao = simularPressaoAtmosferica();
  dados.pontoOrvalho = calcularPontoOrvalho(dados.temperatura, dados.umidade);
  dados.velocidadeVento = calcularVelocidadeVento(analogRead(PINO_ANEMOMETRO));
  dados.radiacaoSolar = calcularRadiacaoSolar(analogRead(PINO_LDR));
  dados.chuvaAcumulada = chuvaAcumulada();
  return dados;
}
