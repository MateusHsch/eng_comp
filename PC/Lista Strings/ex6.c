#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,j,tfrase;
    char frase[50];
    printf("Insira uma frase:\n");
    fgets(frase,50,stdin);
    tfrase = strlen(frase);
    for (i=0;i<(tfrase-1);i++){
        if (frase[i]==' '){
            i++;
            while (frase[i]==' '){
                for (j=i+1;j<tfrase;j++){
                    frase[j-1]=frase[j];
                }
                frase[j]='\0';
                tfrase--;
            }
        }
    }
    printf("%s",frase);
    return 0;
}