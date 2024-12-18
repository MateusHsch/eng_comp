#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6
int main(){
    int mat[TAM][TAM];
    int i,j;
    for (i=0;i<TAM;i++){
        mat[i][0] = 1;
        for (j=1;j<TAM;j++){
            mat[i][j] = 0;
            
        }
    }
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<TAM-1;i++){
        for (j=0;j<TAM;j++){
            if((i+1)>j){
                mat[i+1][j+1] = mat[i][j]+mat[i][j+1];
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