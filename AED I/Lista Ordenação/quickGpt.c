#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos de posição
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que escolhe o pivô e coloca os elementos menores à esquerda e os maiores à direita
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do elemento menor

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor que ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do elemento menor
            swap(&arr[i], &arr[j]); // Troca arr[i] e arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]); // Coloca o pivô na posição correta
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o índice do elemento pivô, de modo que os elementos menores estejam à esquerda
        // e os elementos maiores estejam à direita
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 12, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}