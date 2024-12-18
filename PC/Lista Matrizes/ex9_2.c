#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3
int main (){
    float mat[TAM][TAM];
    int i,j,var;
    printf("Preencha a matriz:\n");
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            scanf("%f",&mat[i][j]);
        }
    }
    printf("\n");
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%.2f ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<TAM;i++){
        var = mat[i][i];
        for (j=0;j<TAM;j++){
            mat[i][j] = mat[i][j]*var;
        }
    }
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%.2f ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}