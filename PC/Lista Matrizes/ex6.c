#include <stdio.h>
#include <stdlib.h>
#define LIN 3
#define COL 3
int main (){
    int i,j,var;
    int sl[LIN], sc[COL];
    int mat[LIN][COL];
    printf("Preencha a matriz:\n");
    for (i=0;i<LIN;i++){
        for (j=0;j<COL;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
    for (i=0;i<LIN;i++){
        for (j=0;j<COL;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0;i<LIN;i++){
        var=0;
        for (j=0;j<COL;j++){
            var += mat[i][j];
        }
        sl[i] = var;
    }
    for (j=0;j<COL;j++){
        var=0;
        for (i=0;i<LIN;i++){
            var += mat [i][j];
        }
        sc[j] = var;
    }
    printf("soma da linhas:\n");
    for (i=0;i<LIN;i++){
        printf("linha %d: %d\n",i,sl[i]);
    }
    printf("\nsoma das colunas:\n");
    for (j=0;j<COL;j++){
        printf("coluna %d: %d\n",j,sc[j]);
    }
    return 0;
}
/*
printf("\n");
for (i=0;i<LIN;i++){
    var=0;
    for (j=0;j<COL;j++){
        var += mat[i][j];
    }
    sl[i] = var;
}
for (j=0;j<COL;j++){
    var=0;
    for (i=0;i<LIN;i++){
        var += mat [i][j];
    }
    sc[j] = var;
}
*/