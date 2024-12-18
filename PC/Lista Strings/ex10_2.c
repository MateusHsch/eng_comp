#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
int main (){
    char mods[TAM][10];
    float cons[TAM];
    float lkm[TAM];
    int i,j,idx,var;
    for (i=0;i<TAM;i++){
        printf("Modelo do carro %d:\n",i+1);
        fgets(mods[i],10,stdin);
        mods[i][strlen(mods[i])-1] = '\0';
        printf("Consumo do carro %d:\n",i+1);
        scanf("%f",&cons[i]);
        fflush(stdin);
    }
    var = 100;
    idx = 0;
    for (i=0;i<TAM;i++){
        if (cons[i]<var){
            var = cons[i];
            idx = i;
        }
    }
    for (i=0;i<TAM;i++){
        lkm[i] = cons[i]*1000;
    }
    printf("%s tem o menor consumo com %.2f l/km.\n",mods[idx],var);
    for (i=0;i<TAM;i++){
        printf("%s gasta %.2f litros para fazer 1000km.\n",mods[i],lkm[i]);
    }
    return 0;
}