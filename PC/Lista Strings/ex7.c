#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,qe=0;
    char txt[100];
    printf("Insira uma frase:\n");
    fgets(txt,100,stdin);
    for (i=0;i<strlen(txt);i++){
        if (txt[i] == ' '){
            qe++;
        }
    }
    printf("A frase possui %d palavras.\n",qe+1);
}