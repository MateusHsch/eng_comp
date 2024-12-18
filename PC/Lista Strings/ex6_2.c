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
        if (frase[i] == ' '){
            while (frase[i+1] == ' '){
                for(j=i+2;j<tfrase;j++){
                    frase[j-1] = frase[j];
                }
                frase[tfrase-1] = '\0';
            }
        }
    }
    printf("%s",frase);
    return 0;
}