/*
Pergunte ao usuário quantas linhas deseja em uma matriz, crie dinamicamente a matriz com 1 coluna na primeira
linha, 2 colunas na segunda linha, 3 colunas na terceira linha e assim por diante… Permita que o usuário preencha
essa matriz e, por fim, imprima no formato matricial.
*/
#include <stdio.h>
#include <stdlib.h>
void preencherMat(int** mat, int m);
void printMat(int** mat, int m);
int main(){
  int i,m,n=1;
  printf("Quantas linhas deseja na sua matriz?\n");
  scanf("%d",&m);
  int **mat = (int**) malloc(m*sizeof(int*));
  for(i=0;i<m;i++){
    n++;
    mat[i] = (int*) malloc(n*sizeof(int));
  }
  if (mat == NULL){
    printf("malloc retornou NULL.\n");
    exit(EXIT_FAILURE);
  }
  preencherMat(mat,m);
  printMat(mat,m);
  return 0;
}
void preencherMat(int** mat, int m){
  int i,j,n=0;
  printf("Preencha a matriz.\n");
  for(i=0;i<m;i++){
    n++;
    for(j=0;j<n;j++){
      printf("mat[%d][%d]: ",i,j);
      scanf("%d",&mat[i][j]);
    }
  }
}
void printMat(int** mat, int m){
  int i,j,n=0;
  printf("\n");
  for(i=0;i<m;i++){
    n++;
    for(j=0;j<n;j++){
      printf("%d\t",mat[i][j]);
    }
    printf("\n");
  }
}