#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
int main(){
    int vet[TAM];
    int i,j,r=0,var=0;
    srand(time(NULL));
    for (i=0;i<=(TAM-1);i++){
        r = (rand()%100)-1;
        vet[i] = r;
        printf("%d ",vet[i]);
    }
    printf("\n");
    for (i=0;i<=(TAM-2);i++){
        for (j=i+1;j<=(TAM-1);j++){
            if (vet[i]>vet[j]){
                var = vet[i];
                vet[i] = vet[j];
                vet[j] = var;
            }
        }
        for (j=0;j<=(TAM-1);j++){
            printf("%d ",vet[j]);
        }
        printf("\n");
    }
}