#include "tipos.h"
#include "sensores.h"
#include "tempo.h"
#include "mqtt.h"

void setup() {
  Serial.begin(115200);
  iniciarSensores();
  iniciarTempo();
  iniciarMQTT();
  Serial.println("> estacao meteorologica iniciada <");
}

void loop() {
  manterMQTT();
  DadosMeteorologicos dados = lerSensores();
  dados.dataHora = dataHora();
  Serial.println("> dados sensores:");
  Serial.printf("temperatura: %.1f C | ", dados.temperatura);
  Serial.printf("umidade: %.1f %%\n", dados.umidade);
  Serial.printf("pressao: %.1f hPa (simulada) | ", dados.pressao);
  Serial.printf("orvalho: %.1f C\n", dados.pontoOrvalho);
  Serial.printf("vento: %.1f m/s | ", dados.velocidadeVento);
  Serial.printf("radiacao: %.1f KJ/m2\n", dados.radiacaoSolar);
  Serial.printf("chuva: %.1f mm | ", dados.chuvaAcumulada);
  Serial.printf("data/hora: %s\n", dados.dataHora.c_str());
  publicarMQTT(dados);
  delay(60000);
}
