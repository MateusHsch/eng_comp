#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    char frase[50];
    char a,b;
    int i,strl;
    printf("Insira a frase:\n");
    fgets(frase,50,stdin);
    printf("Insira 'a':\n");
    scanf("%c",&a);
    fflush(stdin);
    printf("Insira 'b':\n");
    scanf("%c",&b);
    fflush(stdin);
    strl = strlen(frase);
    for (i=0;i<strl;i++){
        if (frase[i] == a){
            frase[i] = b;
        }
    }
    printf("%s\n",frase);
    return 0;
}