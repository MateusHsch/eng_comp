#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0; // Var. Global: Conta as alocações
int desalocacoes = 0; // Var. Global: Conta as desalocações
/* -----------< struct matrix.c >---------- */
struct matrix{
    struct matrix* direita; // Ponteiro para o nó à direita
    struct matrix* abaixo; // Ponteiro para o nó à esquerda
    int linha; // Linha do elemento
    int coluna; // Coluna do elemento
    float info; // Informação do elementos
};
typedef struct matrix Matrix;
/* --------------< matrix.h >-------------- */
Matrix* matrix_create( void ); // Cria a matriz a partir da entrada (matrix.txt)
void matrix_destroy( Matrix* m ); // Destroi a matriz
void matrix_print( Matrix* m ); // Imprime a matriz
/* ---------------< main.c >--------------- */
int main(){

    return 0;
}
/* --------------< matrix.c >-------------- */
Matrix* matrix_create( void ){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    if (m == NULL){
        printf("Malloc");
    }
    int linhas,colunas;



}
