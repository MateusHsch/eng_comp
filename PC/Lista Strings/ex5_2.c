#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    char frase[50];
    int i,j,tfrase;
    printf("Insira a frase:\n");
    fgets(frase,50,stdin);
    tfrase = strlen(frase);
    for(i=0;i<(tfrase-1);i++){
        while (frase[i] == ' '){
            for(j=i+1;j<tfrase;j++){
                frase[j-1] = frase[j];
            }
            frase[tfrase-1] = '\0';
        }
    }
    printf("%s",frase);
    return 0;
}