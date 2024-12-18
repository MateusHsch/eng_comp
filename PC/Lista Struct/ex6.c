//cada naipe vai de 1 a 13. 1=A, 11=J, 12=Q, 13=K
//naipes Espadas, Paus, Copas e Ouro.
//Pife 9 cartas para cada participante de 104 cartas, 2 baralhos de 52
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 18
typedef struct Carta{
    char naipe;
    int num;
} Carta;
int main(){
    Carta cartas[TAM];
    Carta bar1[TAM/2];
    Carta bar2[TAM/2];
    int i,j,nm,inp,tcarta;
    char cnp;
    srand(time(NULL));
    //inicializando o vetor
    for (i=0;i<TAM;i++){
        cartas[i].naipe = 'X';
        cartas[i].num = 0;
    }
    //gerando as cartas
    for (i=0;i<TAM;i++){
        nm = (rand()%13)+1;
        inp = (rand()%4)+1;
        tcarta=0;
        switch (inp){
            case 1:
                cnp = 'E';
                break;
            case 2:
                cnp = 'P';
                break;
            case 3:
                cnp = 'C';
                break;
            case 4:
                cnp = 'O';
                break;
            default:
                break;
        }
        for (j=0;j<TAM;j++){
            if (cartas[j].num == nm && cartas[j].naipe == cnp){
                tcarta++;  
            }
        }
        if (tcarta < 2){
            cartas[i].num = nm;
            cartas[i].naipe = cnp;
        }
    }
    for (i=0;i<TAM;i++){
        if ((i%2) == 0){
            bar1[(int)i/2].num = cartas[i].num;
            bar1[(int)i/2].naipe = cartas[i].naipe;
        } else{
            bar2[(int)i/2].num = cartas[i].num;
            bar2[(int)i/2].naipe = cartas[i].naipe;
        }
    }
    printf("Baralho do jogador 1:\n");
    for (i=0;i<(TAM/2);i++){
        printf("%d %c\n",bar1[i].num,bar1[i].naipe);
    }
    printf("Baralho do jogador 2:\n");
    for (i=0;i<(TAM/2);i++){
        printf("%d %c\n",bar2[i].num,bar2[i].naipe);
    }
}