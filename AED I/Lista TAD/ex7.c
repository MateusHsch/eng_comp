/*
7. Implemente uma função que indique se uma matriz quadrada de números
inteiros (int) é uma matriz identidade ou não. A função deve retornar 1 se a
matriz for uma matriz identidade, e 0 caso contrário. A função recebe como
parâmetros a matriz de inteiros, usando a representação de matrizes através de
vetores simples, e um inteiro n, indicando a dimensão da matriz. Essa função
deve obedecer o protótipo:
int matriz_identidade (int* mat, int n);
*/
#include <stdio.h>
#include <stdlib.h>
int matriz_identidade(int* mat, int n);
void printMat(int* mat, int n);
int main(){
    int mat[9] = {1,2,3,2,1,4,3,4,1};
    int n = 3,ok;
    printMat(mat,n);
    ok = matriz_identidade(mat,n);
    printf("A matriz e identidade: %d\n",ok);
    return 0;
}
int matriz_identidade(int* mat, int n){
    int i,j,ok=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i*n+j] != mat[j*n+i]){
                ok=0;
            }
        }
    }
    return ok;
}
void printMat(int* mat, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",mat[i*n+j]);
        }
        printf("\n");
    }
}