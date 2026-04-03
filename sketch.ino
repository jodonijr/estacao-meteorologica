#include "tipos.h"
#include "sensores.h"

void setup() {
  Serial.begin(115200);
  iniciarSensores();
  Serial.println("> estacao meteorologica iniciada <");
}

void loop() {
  DadosMeteorologicos d = lerSensores();
  Serial.println("> dados sensores:");
  Serial.printf("temperatura: %.1f C\n", d.temperatura);
  Serial.printf("umidade: %.1f %%\n", d.umidade);
  delay(1000);
}
