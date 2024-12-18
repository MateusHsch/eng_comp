#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
typedef struct Contato{
    char nome[30];
    char tel[15];
    int idade;
} Contato;
int main (){
    int i,contlen=0,exit=0,op=0,eq=0;
    Contato contatos[TAM];
    char nomet[30];
    do{
        printf("1 para inserir novo contato.\n");
        printf("2 para pesquisar por um nome.\n");
        printf("3 para ordenar por idade.\n");
        printf("4 para imprimir toda a agenda.\n");
        printf("5 para sair.\n");
        printf("Insira a opção que deseja:\n");
        scanf("%d",&op);
        fflush(stdin);
        switch (op){
            case 1:
                //inserir um novo contato
                if (contlen < 100){
                    printf("Insira o nome:\n");
                    fgets(nomet,30,stdin);
                    nomet[strlen(nomet)-1] = '\0';
                    if (contlen != 0){
                        for (i=0;i<contlen;i++){
                            eq = strcmp(nomet,contatos[i].nome);
                        }
                        if (eq == 0){
                            strcpy(contatos[contlen].nome,nomet);
                            printf("Insira a idade:\n");
                            scanf("%d",&contatos[contlen].idade);
                            fflush(stdin);
                            printf("Insira o telefone:\n");
                            fgets(contatos[contlen].tel,15,stdin);
                            contlen ++;
                            printf("O contato foi adicionado.\n");
                        }else {
                            printf("Esse contato ja está na lista.\n");
                        }
                    }else {
                        strcpy(contatos[contlen].nome,nomet);
                        printf("Insira a idade:\n");
                        scanf("%d",&contatos[contlen].idade);
                        fflush(stdin);
                        printf("Insira o telefone:\n");
                        fgets(contatos[contlen].tel,15,stdin);
                        contlen ++;
                        printf("O contato foi adicionado.\n");
                    }
                }else {
                    printf("A agenda esta cheia.\n");
                }
                break;
            case 2:
                //pesquisar por nome
                printf("Insira o nome que deseja pesquisar:\n");
                fgets(nomet,30,stdin);
                nomet[strlen(nomet)-1] = '\0';
                if (contlen != 0){
                    for (i=0;i<contlen;i++){
                        eq = strcmp(nomet,contatos[contlen].nome);
                        if (eq == 0){
                            printf("Nome: %s\n",contatos[contlen].nome);
                            printf("Idade: %d\n",contatos[contlen].idade);
                            printf("Telefone: %s\n",contatos[contlen].tel);
                        }
                    }
                } else{
                    printf("A agenda esta vazia.\n");
                }
                break;
            case 3:
                //ordenar por idade
                break;
            case 4:
                //imprimir a agenda
                break;
            case 5:
                //sair
                break;
            default:
                printf("opcao invalida.\n");
                break;
        }
    }while (exit != 1);
    return 0;
}