#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,flen;
    char frase[50];
    printf("Insira uma frase:\n");
    fgets(frase,50,stdin);
    printf("Essa e a frase invertida:");
    flen = strlen(frase);
    for (i=flen-1;i>=0;i--){
        printf("%c",frase[i]);
    }
    return 0;
}