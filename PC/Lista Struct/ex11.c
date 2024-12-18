#include <stdio.h>
#include <stdlib.h>
#define TAM 2
typedef struct Aluno{
    int mat,tel;
    char curso;
} Aluno;
int main(){
    Aluno alunos[TAM];
    Aluno var;
    int i,j;
    for (i=0;i<TAM;i++){
        printf("Insira a matriculo do aluno %d:\n",i+1);
        scanf("%d",&alunos[i].mat);
        printf("Insira o telefone do aluno %d:\n",i+1);
        scanf("%d",&alunos[i].tel);
        fflush(stdin);
        printf("Insira a inicial do curso do aluno %d:\n",i+1);
        scanf("%c",&alunos[i].curso);
        fflush(stdin);
    }
    for (i=0;i<(TAM-1);i++){
        for (j=i+1;j<TAM;j++){
            if (alunos[i].mat > alunos[j].mat){
                var = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = var;
            }
        }
    }
    for (i=0;i<TAM;i++){
        printf("Aluno %d.\n",i+1);
        printf("Matricula: %d\n",alunos[i].mat);
        printf("Telefone: %d\n",alunos[i].tel);
        printf("Curso: %c\n",alunos[i].curso);
    }
    return 0;
}