#include "ponto.h"
#include <math.h>

// Função para criar um ponto
Ponto criarPonto(double x, double y) {
    Ponto ponto;
    ponto.x = x;
    ponto.y = y;
    return ponto;
}

// Função para calcular a distância entre dois pontos
double calcularDistancia(Ponto p1, Ponto p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}