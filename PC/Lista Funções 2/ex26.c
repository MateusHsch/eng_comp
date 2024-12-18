#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherMat(int mat[][5],int n);      // preenche de 1 a 50
int somaLinha(int mat[][5],int n,int l);    // linha 4
int somaColuna(int mat[][5],int n,int c);   // coluna 2
int somaDP(int mat[][5],int n);             // diagonal principal
int somaDS(int mat[][5],int n);             // diagonal secundaria
int somaTot(int mat[][5],int n);            // matriz inteira
void printMat(int mat[][5],int n);
int main (){
    srand(time(NULL));
    int mat[5][5];
    int sl,sc,sdp,sds,st;
    preencherMat(mat,5);
    printMat(mat,5);
    sl = somaLinha(mat,5,4);
    sc = somaLinha(mat,5,2);
    sdp = somaDP(mat,5);
    sds = somaDS(mat,5);
    st = somaTot(mat,5);
    printf("Soma linha 4: %d\n",sl);
    printf("Soma coluna 2: %d\n",sc);
    printf("Soma diagonal principal: %d\n",sdp);
    printf("Soma diagonal secundaria: %d\n",sds);
    printf("Soma matriz inteira: %d\n",st);
    return 0;
}

void preencherMat(int mat[][5],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            mat[i][j] = rand()%50 +1;
        }
    }
}
int somaLinha(int mat[][5],int n,int l){
    int j,sl=0;
    for (j=0;j<n;j++){
        sl += mat[l][j];
    }
    return (sl);
}
int somaColuna(int mat[][5],int n,int c){
    int i,sc=0;
    for (i=0;i<n;i++){
        sc += mat[i][c];
    }
    return (sc);
}
int somaDP(int mat[][5],int n){
    int i,j,sdp=0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (i == j){
                sdp += mat[i][j];
            }
        }
    }
    return (sdp);
}
int somaDS(int mat[][5],int n){
    int i,j,sds=0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (i+j == n-1){
                sds += mat[i][j];
            }
        }
    }
    return (sds);
}
int somaTot(int mat[][5],int n){
    int i,j,st=0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            st += mat[i][j];
        }
    }
    return (st);
}
void printMat(int mat[][5],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}