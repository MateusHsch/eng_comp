#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subarrays em ordem crescente
void merge(int arr[], int left, int middle, int right);

// Função mergeSort para dividir e mesclar o array
void mergeSort(int arr[], int left, int right);

// Função de teste para imprimir o array
void printArray(int arr[], int size);

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Criar arrays temporários
    int *leftArr = (int*)malloc(n1 * sizeof(int));
    int *rightArr = (int*)malloc(n2 * sizeof(int));

    // Copiar dados para os arrays temporários
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // Mesclar os arrays temporários em ordem crescente
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes do array da esquerda, se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes do array da direita, se houver
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Liberar a memória dos arrays temporários
    free(leftArr);
    free(rightArr);
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Ordenar a primeira e segunda metade do array
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Mesclar as duas metades ordenadas
        merge(arr, left, middle, right);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}