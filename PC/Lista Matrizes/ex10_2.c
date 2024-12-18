#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
int main(){
    int mat[TAM][TAM];
    int i,j,k,var=0;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            mat[i][j] = (rand()%101)-50;
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<TAM;i++){
        for (j=0;j<(TAM-1);j++){
            for (k=j+1;k<TAM;k++){
                if (mat[i][j] > mat[i][k]){
                    var = mat[i][j];
                    mat[i][j] = mat[i][k];
                    mat[i][k] = var;
                }
            }
        }
    }
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}