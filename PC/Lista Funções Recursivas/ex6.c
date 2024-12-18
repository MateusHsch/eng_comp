#include <stdio.h>
#include <stdlib.h>
void printVet(int vet[],int n);
int main (){
    int n,i;
    printf("Insira o tamanho do vetor:\n");
    scanf("%d",&n);
    int *vet = (int *) malloc(n * sizeof(int));
    if (vet == NULL){
        printf("malloc devolveu um NULL!\n");
        exit(EXIT_FAILURE);
    }
    printf("Preencha o vetor.\n");
    for (i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }
    printVet(vet,n);
    free (vet);
    return 0;
}
void printVet(int vet[],int n){
    int i;
    printf("[");
    for (i=0;i<n;i++){
        if (i == n-1){
            printf("%d]\n",vet[n-1]);
        }else {
            printf("%d ",vet[i]);
        }
    }
}