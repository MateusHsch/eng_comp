//6 primeiras linhas do triângulo de Pascal c/ alocação dinâmica
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main (){
    int i,j=1;
    int **mat = (int**) malloc(TAM*sizeof(int*));
    for (i=0;i<TAM;i++){
        mat[i] = (int*) malloc(j*sizeof(int));
        j++;
    }
    if (mat == NULL){
        printf("malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
    }
    mat[0][0] = 1;
    for (i=1;i<TAM;i++){
        mat[i][0] = 1;
        mat[i][i] = 1;
    }
    for(i=1;i<TAM-1;i++){
        for(j=1;j<=i;j++){
            mat[i+1][j] = mat[i][j] + mat[i][j-1];
        }
    }
    for(i=0;i<TAM;i++){
        for(j=0;j<=i;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<TAM;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}