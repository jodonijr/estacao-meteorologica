#pragma once

struct DadosMeteorologicos {
  String dataHora;
  float temperatura;     // °C
  float umidade;         // %
  float pressao;         // hPa (simular)
  float pontoOrvalho;    // °C (calcular)
  float velocidadeVento; // m/s (ler do potenciômetro)
  float radiacaoSolar;   // KJ/m² (ler do LDR)
  float chuvaAcumulada;  // mm (calcular via interrupção do botão)
};
