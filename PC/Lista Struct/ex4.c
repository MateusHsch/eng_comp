#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2
typedef struct Aluno{
    int mat;
    char nome[30];
    float np1,np2,np3;
} Aluno;
int main (){
    int i,j;
    float mn1=0.0,maiorm=0.0,menorm=100.0;
    float medias[TAM];
    Aluno alunos[TAM];
    for (i=0;i<TAM;i++){
        printf("Insira a matricula do aluno %d:\n",i+1);
        scanf("%d",&alunos[i].mat);
        getchar();
        printf("Insira o nome do aluno %d:\n",i+1);
        fgets(alunos[i].nome,30,stdin);
        alunos[i].nome[strlen(alunos[i].nome)-1] = '\0';
        printf("Insira a nota 1 do aluno %d:\n",i+1);
        scanf("%f",&alunos[i].np1);
        printf("Insira a nota 2 do aluno %d:\n",i+1);
        scanf("%f",&alunos[i].np2);
        printf("Insira a nota 3 do aluno %d:\n",i+1);
        scanf("%f",&alunos[i].np3);
    }
    for (i=0;i<TAM;i++){
        if (alunos[i].np1>=mn1){
            mn1 = alunos[i].np1;
            j = i;
        }
    }
    printf("%s e o aluno com maior nota na prova 1.\n",alunos[j].nome);
    for (i=0;i<TAM;i++){
        medias[i] = (alunos[i].np1+alunos[i].np2+alunos[i].np3)/3;
    }
    for (i=0;i<TAM;i++){
        if (medias[i]>maiorm){
            maiorm = medias[i];
            j = i;
        }
    }
    printf("%s e o aluno com maior media geral.\n",alunos[j].nome);
    for (i=0;i<TAM;i++){
        if (medias[i]<menorm){
            menorm = medias[i];
            j = i;
        }
    }
    printf("%s e o aluno com menor media geral.\n",alunos[j].nome);
    for (i=0;i<TAM;i++){
        if (medias[i]>=6){
            printf("O aluno %s foi aprovado.\n",alunos[i].nome);
        } else{
            printf("O aluno %s foi reprovado.\n",alunos[i].nome);
        }
    }
    return 0;
}