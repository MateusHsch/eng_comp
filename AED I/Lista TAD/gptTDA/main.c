#include <stdio.h>
#include "ponto.h"

int main() {
    Ponto p1 = criarPonto(1.0, 2.0);
    Ponto p2 = criarPonto(4.0, 6.0);

    printf("P1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("P2: (%.2f, %.2f)\n", p2.x, p2.y);

    double distancia = calcularDistancia(p1, p2);
    printf("Distancia entre P1 e P2: %.2f\n", distancia);

    return 0;
}