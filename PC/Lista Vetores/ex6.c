#include <stdio.h>
#define TAM 20
int main(){
    int lista[20];
    int i;
    for (i=0;i<20;i++){
        printf("Insira um valor:\n");
        scanf("%d",&lista[i]);
    }
    for (i=0;i<20;i++){
        printf("Numero: %d\n",lista[i]);
    }
}