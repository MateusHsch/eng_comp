#ifndef PONTO_H
#define PONTO_H

typedef struct {
    double x;
    double y;
} Ponto;

// Funções para manipulação do ponto
Ponto criarPonto(double x, double y);
double calcularDistancia(Ponto p1, Ponto p2);

#endif // PONTO_H