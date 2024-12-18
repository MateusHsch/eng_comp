#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getRandom();
void fillVet(int A[],int n);
int maiorElem(int A[],int n);
void printVet(int A[],int n);
int main(){
    int maior,A[5];
    srand(time(NULL));
    fillVet(A,5);
    maior = maiorElem(A,5);
    printVet(A,5);
    printf("maior elemento: %d\n",maior);
    return 0;
}
int getRandom(){
    int n = (rand()%2001)-1000;
    return (n);
}
void fillVet(int A[],int n){
    int i;
    for (i=0;i<n;i++){
        A[i] = getRandom();
    }
}
int maiorElem(int A[],int n){
    int i, maior=0;
    for (i=0;i<n;i++){
        if (A[i]>maior){
            maior = A[i];
        }
    }
    return (maior);
}
void printVet(int A[],int n){
    int i;
    printf("[");
    for (i=0;i<n;i++){
        printf(" %d ",A[i]);
    }
    printf("]\n");
}