#include <stdio.h>
#define TAM 15
int main(){
    int lista[TAM];
    int i,pares=0;
    for (i=0;i<TAM;i++){
        printf("Insira um valor:\n");
        scanf("%d",&lista[i]);
    }
    for (i=0;i<TAM;i++){
        if(lista[i]%2 == 0){
            pares++;
            printf("O numero %d e par.\n",lista[i]);
        }
    }
    printf("Nessa lista tem %d numeros pares.\n",pares);
}