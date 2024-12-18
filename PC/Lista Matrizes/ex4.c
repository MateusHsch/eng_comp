#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 3
#define COL 3
int main (){
    int i,j,var=0;
    int mat[LIN][COL];
    srand(time(NULL));
    for (i=0;i<LIN;i++){
        for (j=0;j<COL;j++){
            mat[i][j] = (rand()%100)+1;
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<LIN;i++){
        for (j=0;j<COL;j++){
            if (mat[i][j]%2 == 0){
                var++;
            }
        }
    }
    printf("pares: %d\n",var);
}