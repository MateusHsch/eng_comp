#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printVet(int* v,int n);
void troca(int* a,int* b);
void quickSort(int* v,int com, int fim);
int particiona(int* v, int com, int fim);
int main() {
    clock_t inicio,fim;
    double tempo;
    int v[] = {42, 17, 89, 31, 76, 50, 7, 63, 93, 27, 12, 4, 58, 71, 65, 21, 84, 98, 2, 36, 6, 54, 29, 96, 79, 19, 85, 9, 60, 74, 13, 44, 91, 25, 3, 37, 55, 22, 81, 16, 48, 88, 69, 47, 38, 68, 72, 34, 95, 8, 66, 59, 14, 87, 45, 97, 26, 5, 64, 18, 30, 67, 23, 80, 41, 92, 33, 77, 11, 70, 52, 15, 40, 75, 53, 94, 61, 46, 86, 39, 73, 10, 56, 35, 1, 28, 83, 62, 20, 49, 24, 32, 90, 51, 82, 57, 99, 78, 43};
    int n = 100;
    printf("Array original:\n");
    printVet(v,n);
    inicio = clock();
    quickSort(v, 0, n-1);
    fim = clock();
    printf("Array ordenado:\n");
    printVet(v,n);
    tempo = (double) (fim-inicio)/CLOCKS_PER_SEC;
    printf("tempo de ordenacao: %f\n",tempo);
    return 0;
}
void printVet(int* v,int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        printf(" %d",v[i]);
    }
    printf(" ]\n\n");
}
void troca(int* a,int* b){
    int aux = *b;
    *b = *a;
    *a = aux;
}
void quickSort(int* v,int com, int fim){
    if (com < fim){
        int pi = particiona(v,com,fim);
        quickSort(v,com,pi-1);
        quickSort(v,pi+1,fim);
    }
}
int particiona(int* v, int com, int fim){
    int pivo = v[fim]; //escolhe o ultimo como pivo
    int i = (com-1); //marca quantos elementos são menores que o pivo
    for(int j=com; j<fim; j++){ 
        if(v[j] <= pivo){
            i++;
            troca(&v[i],&v[j]);
        } //faz as trocas garantindo que todos os elementos meores que o pivo fiquem na 1a mentade do vetor
    }
    troca(&v[i+1],&v[fim]); //traz o vetor do fim para o meio do vetor
    return (i+1);
}