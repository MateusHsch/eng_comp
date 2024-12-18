/*
8. Implemente uma função que indique se uma matriz quadrada de números
inteiros é uma matriz identidade ou não. A função deve retornar 1 se a matriz
for uma matriz identidade, e 0 caso contrário. A função recebe como
parâmetros a matriz de inteiros, usando a representação de matrizes através de
vetores de ponteiros, e um inteiro n, indicando a dimensão da matriz. Essa
função deve obedecer o protótipo:
int matriz_identidade (int** mat, int n);
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int matriz_identidade(int** mat, int n);
void printMat(int** mat, int n);
int main(){
    srand(time(NULL));
    int n = 3,i,j,ok;
    int** mat = (int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        mat[i] = (int*) malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat[i][j] = rand()%10;
        }
    }
    printMat(mat,n);
    ok = matriz_identidade(mat,n);
    printf("A matriz e identidade: %d\n",ok);
    for(i=0;i<n;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}
int matriz_identidade(int** mat, int n){
    int i,j,ok=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j] != mat[j][i]){
                ok=0;
            }
        }
    }
    return ok;
}
void printMat(int** mat, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}