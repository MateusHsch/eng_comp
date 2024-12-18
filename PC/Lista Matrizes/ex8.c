#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TLIN 5
#define TCOL 5
int main(){
    int mat[TLIN][TCOL];
    int i,j,r=0,maior=0,menor=100;
    srand(time(NULL));
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-1);j++){
            r = (rand()%101);
            mat[i][j] = r;
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-1);j++){
            if (i<j){
                if (mat[i][j]>maior){
                    maior = mat[i][j];
                }
            }else if ((i+j)>(TLIN-1)){
                if (mat[i][j]<menor){
                    menor = mat[i][j];
                }
            }
        }
    }
    printf("%d e o maior numero acima da diagonal principal.\n",maior);
    printf("%d e o menor numero abaixo da diagonal secundaria.\n",menor);
    return 0;
}