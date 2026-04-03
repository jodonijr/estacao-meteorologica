#pragma once
#include <math.h>

float simularPressaoAtmosferica() {
  float tempo = millis() / 100000.0;
  float amplitude = 7.5;             
  float base = 1012.5;               
  return base + (amplitude * sin(tempo));
}

const float MAGNUS_A = 17.27;
const float MAGNUS_B = 237.3;

float calcularPontoOrvalho(float temp, float umidade) {
  if (umidade <= 0)
    return 0;
  
  float alpha = log(umidade / 100.0) + ((MAGNUS_A * temp) / (MAGNUS_B + temp));
  return (MAGNUS_B * alpha) / (MAGNUS_A - alpha);
}