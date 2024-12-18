#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
int main (){
    srand(time(NULL));
    int i,j,var,h1=0,l2=100;
    int mat[TAM][TAM];
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            mat[i][j] = rand()%101;
        }
    }
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            if (i < j){
                if (mat[i][j] > h1){
                    h1 = mat[i][j];
                }
            }
            if (i+j > TAM-1){
                if (mat[i][j] < l2){
                    l2 = mat[i][j];
                }
            }
        }
    }
    printf("maior acima da dp: %d\n",h1);
    printf("menor abaixo da ds: %d\n",l2);
    return 0;
}
