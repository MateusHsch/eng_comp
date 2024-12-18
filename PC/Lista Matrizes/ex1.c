#include <stdio.h>
#include <stdlib.h>
#define LIN 5
#define COL 5
int main() {
    int i,j;
    int mat[LIN][COL];
    for (i=0;i<LIN;i++){
        for (j=0;j<COL;j++){
            if (i==j){
                mat[i][j]= 1;
            }else {
                mat[i][j] = 0;
            }
        }
    }
    for (i=0;i<LIN;i++){
        for (j=0;j<COL;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
/*
    int mat[LIN][COL] = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
    int i,j;
    for(i=0;i<=(LIN-1);i++){
        for(j=0;j<=(COL-1);j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
*/