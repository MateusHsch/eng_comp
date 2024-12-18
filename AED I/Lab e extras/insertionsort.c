#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherVet(int *vet,int n);  //Preenche o vetor de tamanho n com numeros aleatórios de 1 a 100.
void printVet(int *vet,int n);      //Imprime o vetor.
void insertionSort(int *vet,int n); //Ordena o vetor usando insertionsort.
int main (){
    srand(time(NULL));
    int n;
    clock_t inicio, fim;
    double tempo_decorrido;
    printf("insira o tamanho do vetor: ");
    scanf("%d",&n);
    fflush(stdin);
    printf("\n");
    int *vet = (int*) malloc(n * sizeof(int));
    if (vet == NULL){
        printf("malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
    }
    preencherVet(vet,n);
    printVet(vet,n);
    inicio = clock(); //começa a medir o tempo.
    insertionSort(vet,n); //Ordena o vetor.
    fim = clock(); //termina de medir o tempo.
    tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos.
    printf("Vetor Ordenado:\n");
    printVet(vet,n);
    printf("Tempo de Ordenacao: %f segundos\n", tempo_decorrido);
    free(vet);
    return 0;
}
void preencherVet(int *vet,int n){
    int i;
    for(i=0;i<n;i++){
        vet[i] = rand()%100+1;
    }
}
void printVet(int *vet,int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        printf(" %d",vet[i]);
    }
    printf(" ]\n");
}
void insertionSort(int *vet,int n){
    int i,j,atual;
    for(i=1;i<n;i++){
        atual = vet[i]; //Guarda o numero na posição i do vetor.
        for(j=i;(j>0) && (atual<vet[j-1]);j--){ //Desloca o numero na posição i até ele ser maior que o anterior.
            vet[j] = vet[j-1];
        }
        vet[j] = atual;
    }
}