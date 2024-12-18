#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
typedef struct Pessoa{
    char nome[30];
    char ender[50];
    char tel[20];
} Pessoa;
int main(){
    int i,j;
    Pessoa pvar;
    Pessoa pessoas[TAM];
    for (i=0;i<TAM;i++){
        printf("Nome da pessoa %d:\n",i+1);
        fgets(pessoas[i].nome,30,stdin);
        //pessoas[i].nome[strlen(pessoas[i].nome)-1] = '\0';
        printf("Endereco da pessoa %d:\n",i+1);
        fgets(pessoas[i].ender,50,stdin);
        printf("Telefone da pessoa %d:\n",i+1);
        fgets(pessoas[i].tel,20,stdin);
    }

    for (i=0;i<(TAM-1);i++){
        for (j=i+1;j<TAM;j++){
            if (strcmp(pessoas[i].nome,pessoas[j].nome) > 0){
                pvar = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = pvar;
            }
        }
    }
    for (i=0;i<TAM;i++){
        printf("Pessoas %d.\n",i+1);
        printf("Nome: %s",pessoas[i].nome);
        printf("Endereco: %s",pessoas[i].ender);
        printf("Telefone: %s",pessoas[i].tel);
    }
    return 0;
}
