#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TLIN 5
#define TCOL 5
int main(){
    int mat[TLIN][TCOL];
    int i,j,k,r=0,var=0;
    srand(time(NULL));
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-1);j++){
            r = (rand()%101)-50;
            mat[i][j] = r;
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-2);j++){
            for (k=j+1;k<=(TCOL-1);k++){
                if (mat[i][j]>mat[i][k]){
                var = mat[i][j];
                mat[i][j] = mat[i][k];
                mat[i][k] = var;
                }
            }
        }
    }
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-1);j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}