#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,tam;
    char frase[50];
    printf("insira uma palavra:\n");
    fgets(frase,50,stdin);
    for (i=0;i<50;i++){
        if (frase[i]=='\n'){
            tam=i;
        }
    }
    printf("O tamanho da frase e %d",tam);
    return 0;
}
