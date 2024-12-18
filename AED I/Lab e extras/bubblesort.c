#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherVet(int *vet,int n);  //Preenche o vetor de tamanho n com numeros aleatórios de 1 a 100.
void printVet(int *vet,int n);      //Imprime o vetor.
void bubbleSort(int *vet,int n);    //Ordena o vetor usando bubblesort.
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
    bubbleSort(vet,n); //Ordena o vetor.
    fim = clock(); //termina de medir o tempo.
    tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
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
void bubbleSort(int *vet,int n){
    int i,aux,continua,fim = n;
    do{
        continua = 0;
        for(i=0;i<fim-1;i++){
            if(vet[i] > vet[i+1]){ //Se o valor na posição atual é maior que o da próxima, então troca.
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}