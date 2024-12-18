#include <stdio.h>
#include <stdlib.h>
#define TAM 20
int main(){
    int vet[TAM];
    int i,var;
    printf("Insira o vetor:\n");
    for (i=0;i<TAM;i++){
        scanf("%d",&vet[i]);
    }
    for (i=0;i<((int)(TAM/2));i++){
        var = vet[i];
        vet[i] = vet[TAM-i-1];
        vet[TAM-i-1] = var;
    }
    for (i=0;i<TAM;i++){
        printf("%d ",vet[i]);
    }
    return 0;
}