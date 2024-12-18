#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,j,tam;
    char frase[100] = "";
    printf("Escreva uma frase:\n");
    gets(frase);
    tam = strlen(frase);
    for (i=0;i<=(tam-2);i++){
        if (frase[i]==' '){
            for (j=i+1;j<=(tam-1);j++){
                frase[j-1] = frase[j];
            }
            tam -= 1;
            frase[tam] = ' ';
        }
    }
    printf("Esta e a frase sem espacos.\n");
    printf("%s",frase);
    return 0;
}