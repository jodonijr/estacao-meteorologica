#pragma once
#include <math.h>

float simularPressaoAtmosferica() {
  float tempo = millis() / 100000.0; 
  float amplitude = 7.5;             
  float base = 1012.5;               
  return base + (amplitude * sin(tempo));
}
