#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherMat(int mat[][6],int n);
void somaMat(int M[][6],int N[][6],int Smat[][6],int n);
void difMat(int M[][6],int N[][6],int Dmat[][6],int n);
void multMat(int M[][6],int N[][6],int Mmat[][6],int n);
void printMat(int mat[][6],int n);
void printRes(int M[][6],int N[][6],int Smat[][6],int Dmat[][6],int Mmat[][6],int n);
int main (){
    srand(time(NULL));
    int M[6][6],N[6][6],Smat[6][6],Dmat[6][6],Mmat[6][6];
    int op,exit=0;
    preencherMat(M,6);
    preencherMat(N,6);
    do{
        printf("1 - soma de M com N.\n");
        printf("2 - diferenca de M com N.\n");
        printf("3 - produto matricial de M por N.\n");
        printf("4 - Imprima as matrizes lidas e as calculadas.\n");
        printf("Insira a opcao que deseja:\n");
        scanf("%d",&op);
        switch (op){
            case 1:
                somaMat(M,N,Smat,6);
                break;
            case 2:
                difMat(M,N,Dmat,6);
                break;
            case 3:
                multMat(M,N,Mmat,6);
                break;
            case 4:
                printRes(M,N,Smat,Dmat,Mmat,6);
                exit = 1;
                break;
            default:
                printf("opcao invalida.\n");
                break;
        }
    } while (exit != 1);
    return 0;
}
void preencherMat(int mat[][6],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            mat[i][j] = rand()%50 +1;
        }
    }
}
void somaMat(int M[][6],int N[][6],int Smat[][6],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            Smat[i][j] = M[i][j]+N[i][j];
        }
    }
}
void difMat(int M[][6],int N[][6],int Dmat[][6],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            Dmat[i][j] = M[i][j]-N[i][j];
        }
    }
}
void multMat(int M[][6],int N[][6],int Mmat[][6],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            Mmat[i][j] = M[i][j]*N[i][j];
        }
    }
}
void printMat(int mat[][6],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void printRes(int M[][6],int N[][6],int Smat[][6],int Dmat[][6],int Mmat[][6],int n){
    printMat(M,n);
    printMat(N,n);
    printMat(Smat,n);
    printMat(Dmat,n);
    printMat(Mmat,n);
}  