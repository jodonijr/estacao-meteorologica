#pragma once
#include <math.h>

const float FATOR_TEMPO = 100000.0;
const float AMPLITUDE_PRESSAO_HPA = 7.5;
const float PRESSAO_MEDIA_NIVEL_MAR = 1012.5;

float simularPressaoAtmosferica() {
  float tempo = millis() / FATOR_TEMPO;
  return PRESSAO_MEDIA_NIVEL_MAR + (AMPLITUDE_PRESSAO_HPA * sin(tempo));
}

const float MAGNUS_A = 17.27;
const float MAGNUS_B = 237.3;

float calcularPontoOrvalho(float temp, float umidade) {
  if (umidade <= 0)
    return 0;
  
  float alpha = log(umidade / 100.0) + ((MAGNUS_A * temp) / (MAGNUS_B + temp));
  return (MAGNUS_B * alpha) / (MAGNUS_A - alpha);
}
