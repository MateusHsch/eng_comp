#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherMat(int mat[][8],int n);
void printMat(int mat[][8],int n);
int menorCDS(int mat[][8],int n);
int main (){
    srand(time(NULL));
    int mat[8][8];
    int menor;
    preencherMat(mat,8);
    printMat(mat,8);
    menor = menorCDS(mat,8);
    printf("%d e o menor numero acima da diagonal secundaria.\n",menor);
    return 0;
}
void preencherMat(int mat[][8],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            mat[i][j] = rand()%100 +1;
        }
    }
}
void printMat(int mat[][8],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
int menorCDS(int mat[][8],int n){
    int i,j,menor=100;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (i+j < n-1){
                if (mat[i][j] < menor){
                    menor = mat[i][j];
                }
            }
        }
    }
    return (menor);
}