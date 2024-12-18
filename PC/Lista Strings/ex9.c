#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i;
    char a,b;
    char txt[100];
    printf("Insira uma frase:\n");
    fgets(txt,100,stdin);
    printf("Insira uma letra:\n");
    scanf("%c",&a);
    fflush(stdin);
    printf("Insira outra letra:\n");
    scanf("%c",&b);
    for (i=0;i<strlen(txt);i++){
        if (txt[i] == a){
            txt[i] = b;
        }
    }
    printf("%s\n",txt);
}