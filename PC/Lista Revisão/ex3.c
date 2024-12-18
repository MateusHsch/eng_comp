#include <stdio.h>
//Um professor possui certo número de balas que deseja distribuir igualmente entre seus alunos.
//Ele ficará com as balas que sobrarem, se houver. Faça um programa que leia o número de alunos e o
//número de balas, calcule quantas balas cada aluno receberá e quantas balas ficarão com o professor.
int main(){
    int alunos,balas,result,resto;
    printf("Digite o numero de alunos.\n");
    scanf("%d",&alunos);
    printf("Digite o numero de balas.\n");
    scanf("%d",&balas);
    if (balas<alunos){
        printf("Compra mais bala ai... Para ninguem ficar de fora.\n");
    }else {
        result = balas/alunos;
        resto = balas % alunos;
        printf("Cada aluno vai ganhar %d balas.\n",result);
        printf("O professor vai ganhar %d balas.\n",resto);
    }
    
}