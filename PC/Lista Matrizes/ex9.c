#include <stdio.h>
#include <stdlib.h>
#define TLIN 5
#define TCOL 5
int main(){
    float mat[TLIN][TCOL];
    int i,j;
    float cons=0;
    printf("Preencha a matriz com numeros reais.\n");
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-1);j++){
            scanf("%f",&mat[i][j]);
        }
    }
    printf("\n");
    for (i=0;i<=(TLIN-1);i++){
        cons = mat[i][i];
        for (j=0;j<=(TCOL-1);j++){
            mat[i][j] = cons*mat[i][j];
        }
    }
    for (i=0;i<=(TLIN-1);i++){
        for (j=0;j<=(TCOL-1);j++){
            printf("%.2f\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}