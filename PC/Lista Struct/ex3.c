#include <stdio.h>
#include <stdlib.h>
#define TAM 2
typedef struct Aluno{
char nome[40];
char curso[30];
int mat;
} Aluno;
int main (){
    Aluno alunos[TAM];
    int i;
    for (i=0;i<TAM;i++){
        printf("Aluno numero %d\n",i+1);
        printf("Insira o nome:\n");
        fgets(alunos[i].nome,40,stdin);
        printf("Insira o curso:\n");
        fgets(alunos[i].curso,30,stdin);
        printf("Insira a matricula:\n");
        scanf("%d",&alunos[i].mat);
        getchar(); // consome o caractere \n deixado pelo scanf
    }
    for (i=0;i<TAM;i++){
        printf("Aluno numero %d\n",i+1);
        printf("Nome: %s",alunos[i].nome);
        printf("Curso: %s",alunos[i].curso);
        printf("Matricula: %d\n",alunos[i].mat);
    }
    return 0;
}