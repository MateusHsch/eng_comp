#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5
int main (){
    int mat[TAM][TAM];
    int i,j,var=0;
    float media;
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            mat[i][j] = (rand()%100)+1;
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
            if (i==j){
                var += mat[i][j];
            }
        }
    }
    media = (float)var/(float)TAM;
    printf("a media e: %.2f\n",media);
    return 0;
}