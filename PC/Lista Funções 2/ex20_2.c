#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void contaPalavras(char str[],int tstr);
int main (){
    char str[100];
    int tstr=0;
    printf("Insira uma frase:\n");
    fgets(str,50,stdin);
    str[strlen(str)-1] = '\0';
    tstr = strlen(str);
    contaPalavras(str,tstr);
    return 0;
}
void contaPalavras(char str[],int tstr){
    int i,cont;
    if (str[0] == ' '){
        cont = 0;
    } else{
        cont = 1;
    }
    for (i=0;i<tstr;i++){
        if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0'){
            cont++;
        }
    }
    printf("A frase tem %d palavras.\n",cont);
}