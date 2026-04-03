#pragma once

#define PINO_CHUVA 32
const float VOLUME_BASCULA = 0.2; // 0.2 mm de chuva por pressionamento
const unsigned long TEMPO_DEBOUNCE = 200; // ms

volatile int pressionamentos = 0;
volatile unsigned long tempoUltimoPress = 0;

void IRAM_ATTR contarChuvaISR() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoUltimoPress > TEMPO_DEBOUNCE) {
    pressionamentos++;
    tempoUltimoPress = tempoAtual;
  }
}

void iniciarPluviometro() {
  pinMode(PINO_CHUVA, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PINO_CHUVA), contarChuvaISR, FALLING);
}

float chuvaAcumulada() {
  return pressionamentos * VOLUME_BASCULA;
}
