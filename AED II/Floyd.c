#include <stdio.h>
#include <limits.h>

#define V 4 // Número de vértices no grafo

// Função para encontrar a matriz de distância mínima usando o algoritmo de Floyd-Warshall
void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    // Inicializa a matriz de distância
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Passa por todos os vértices intermediários
    for (k = 0; k < V; k++) {
        // Passa por todas as posições da matriz
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // Se o vértice k for um caminho mais curto
                // de i para j, então atualize o valor de dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Imprime a matriz de distâncias mínimas
    printf ("Matriz de distância mínima:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Um exemplo de grafo de entrada, com pesos das arestas
    int graph[V][V] = { {0, 5, INT_MAX, 10},
                        {INT_MAX, 0, 3, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 1},
                        {INT_MAX, INT_MAX, INT_MAX, 0} };

    // Chama a função para encontrar a matriz de distância mínima
    floydWarshall(graph);
    return 0;
}