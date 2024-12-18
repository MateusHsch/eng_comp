#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
typedef struct Pessoa{
    int cpf;
    int data[3];
    int tel;
    char sexo;
} Pessoa;
int main(){
    Pessoa agenda[TAM];
    int i,op=0,var=0,tagenda=0,cpft=0,exit=0;
    char cvar;
    for (i=0;i<TAM;i++){
        agenda[i].cpf = 0;
        agenda[i].data[0] = 0;
        agenda[i].data[1] = 0;
        agenda[i].data[2] = 0;
        agenda[i].tel = 0;
        agenda[i].sexo = ' ';
    }
    do{
        printf("1 - Inserir apenas um contato.\n");
        printf("2 - Procurar por um CPF e imprimir todas os dados da pessoa encontrada.\n");
        printf("3 - Buscar pessoas por um mes de aniversario.\n");
        printf("4 - Imprima toda a agenda.\n");
        printf("5 - Liste todos os contatos conforme determinado sexo.\n");
        printf("6 - Sair.\n");
        printf("Insira a opcao que deseja:\n");
        scanf("%d",&op);
        fflush(stdin);
        switch (op){
            case 1:
                if (tagenda < 10){
                    printf("Insira o CPF da pessoa que deseja adicionar:\n");
                    scanf("%d",&cpft);
                    fflush(stdin);
                    var = 0;
                    for(i=0;i<TAM;i++){
                        if (agenda[i].cpf == cpft){
                            var = 1;
                        }
                    }
                    if (var == 0){
                        agenda[tagenda].cpf = cpft;
                        printf("Insira a data de nacimento.\n");
                        printf("Dia: ");
                        scanf("%d",&agenda[tagenda].data[0]);
                        printf("Mes: ");
                        scanf("%d",&agenda[tagenda].data[1]);
                        printf("Ano: ");
                        scanf("%d",&agenda[tagenda].data[2]);
                        printf("Insira o telefone:\n");
                        scanf("%d",&agenda[tagenda].tel);
                        fflush(stdin);
                        printf("Insira o sexo:\n");
                        scanf("%c",&agenda[tagenda].sexo);
                        fflush(stdin);
                        printf("Contato adicionado.\n");
                        tagenda++;
                    } else{
                        printf("Esse CPF ja esta na agenda.\n");
                    }
                } else{
                    printf("A agenda esta cheia.\n");
                }
                break;
            case 2:
                printf("Insira o CPF da pessoa que deseja procurar:\n");
                scanf("%d",&cpft);
                fflush(stdin);
                for (i=0;i<tagenda;i++){
                    if (agenda[i].cpf == cpft){
                        printf("Dados da pessoa.\n");
                        printf("CPF: %d\n",agenda[i].cpf);
                        printf("Data de Nasc.: %d/%d/%d\n",agenda[i].data[0],agenda[i].data[1],agenda[i].data[2]);
                        printf("Telefone: %d\n",agenda[i].tel);
                        printf("Sexo: %c\n",agenda[i].sexo);
                    }
                }
                break;
            case 3:
                printf("Insira o mes de aniversario que deseja buscar:\n");
                scanf("%d",&var);
                fflush(stdin);
                for (i=0;i<tagenda;i++){
                    if (agenda[i].data[1] == var){
                        printf("Dados da pessoa.\n");
                        printf("CPF: %d\n",agenda[i].cpf);
                        printf("Data de Nasc.: %d/%d/%d\n",agenda[i].data[0],agenda[i].data[1],agenda[i].data[2]);
                        printf("Telefone: %d\n",agenda[i].tel);
                        printf("Sexo: %c\n",agenda[i].sexo);
                    }
                }
                break;
            case 4:
                for (i=0;i<tagenda;i++){
                    printf("Dados da pessoa.\n");
                    printf("CPF: %d\n",agenda[i].cpf);
                    printf("Data de Nasc.: %d/%d/%d\n",agenda[i].data[0],agenda[i].data[1],agenda[i].data[2]);
                    printf("Telefone: %d\n",agenda[i].tel);
                    printf("Sexo: %c\n",agenda[i].sexo);
                }
                break;
            case 5:
                printf("Insira o sexo dos contatos que deseja buscar:\n");
                scanf("%c",&cvar);
                fflush(stdin);
                for (i=0;i<tagenda;i++){
                    if (agenda[i].sexo == cvar){
                        printf("Dados da pessoa.\n");
                        printf("CPF: %d\n",agenda[i].cpf);
                        printf("Data de Nasc.: %d/%d/%d\n",agenda[i].data[0],agenda[i].data[1],agenda[i].data[2]);
                        printf("Telefone: %d\n",agenda[i].tel);
                        printf("Sexo: %c\n",agenda[i].sexo);
                    }
                }
                break;
            case 6:
                exit = 1;
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while (exit != 1);
    return 0;
}