#include "tipos.h"
#include "sensores.h"

void setup() {
  Serial.begin(115200);
  iniciarSensores();
  Serial.println("> estacao meteorologica iniciada <");
}

void loop() {
  DadosMeteorologicos dados = lerSensores();
  Serial.println("> dados sensores:");
  Serial.printf("temperatura: %.1f C\n", dados.temperatura);
  Serial.printf("umidade: %.1f %%\n", dados.umidade);
  Serial.printf("pressao: %.1f hPa (simulada)\n", dados.pressao);
  Serial.printf("orvalho: %.1f C\n", dados.pontoOrvalho);
  Serial.printf("vento %.1f m/s", dados.velocidadeVento);
  delay(1000);
}
