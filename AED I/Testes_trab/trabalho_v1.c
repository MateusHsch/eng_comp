#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;
/* ----------< struct matrix.c >---------- */
struct matrix{
    struct matrix* direita;
    struct matrix* abaixo;
    int linha;
    int coluna;
    float info;
};
typedef struct matrix Matrix;
/* ----------< matrix.h >---------- */
Matrix* matrix_create( void );
void matrix_destroy( Matrix* m );
void matrix_print( Matrix* m );
void printMat( Matrix* m );
/* ----------< main.c >---------- */
int main(){
    Matrix* m = matrix_create();
    printf("%d alocacoes.\n",alocacoes);
    printMat(m);
    matrix_print(m);
    matrix_destroy(m);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}
/* ----------< matrix.c >---------- */
Matrix* matrix_create( void ){
    int linhas,colunas; // Linhas e colunas da Matrix
    int i,j; // Posição do elemento lido
    float valor; // Valor do elemento lido
    int aux; // Auxiliar para percorrer o cabeçalho
    Matrix *m = (Matrix*) malloc(sizeof(Matrix)); // Aloca o nó central do cabeçalho
    alocacoes++;
    if (m == NULL){
        printf("malloc devolveu NULL.\n");
        exit(1);
    }
    m->linha = -1;
    m->coluna = -1;
    m->direita = NULL;
    m->abaixo = NULL;
    Matrix *atual,*cabeca,*elemento; // atual: nó atual; cabeca: nó do cabeçalho percorrido; elemento: O elemento
    FILE* fr = fopen("matrix.txt","r"); // Abre o arquivo com a Matrix
    if(fr == NULL){
        printf("matrix.txt\n");
        exit(1);
    }
    fscanf(fr,"%d %d",&linhas,&colunas); // Lê a quantia de linhas e colunas da Matrix;
    atual = m;
    while (linhas != 0){ // Aloca o nó cabeça para todas as linhas
        atual->abaixo = (Matrix*) malloc(sizeof(Matrix));
        alocacoes++;
        if (atual->abaixo == NULL){
            printf("malloc devolveu NULL.\n");
            exit(1);
        }
        atual = atual->abaixo; // Aponta para o nó criado
        atual->linha = -1; // ?
        atual->coluna = -1;
        atual->direita = atual;
        atual->abaixo = m;
        linhas--;
    }
    atual = m;
    while (colunas != 0){ // Aloca o nó cabeça para todas as colunas
        atual->direita = (Matrix*) malloc(sizeof(Matrix));
        alocacoes++;
        if (atual->direita == NULL){
            printf("malloc devolveu NULL.\n");
            exit(1);
        }
        atual = atual->direita; // Aponta para o nó criado
        atual->linha = -1;
        atual->coluna = -1; // ?
        atual->direita = m;
        atual->abaixo = atual;
        colunas--;
    }
    while(fscanf(fr,"\n%d %d %f",&i,&j,&valor) != EOF){ // Lê os elementos da Matrix do arquivo;
        cabeca = m;
        aux = -1;
        while(aux != i){ // Percorre o cabeçalho das linhas até a linha do elemento
            cabeca = cabeca->abaixo;
            aux++;
        }
        atual = cabeca;
        while(atual->direita != cabeca){ // Percorre até o ultimo elemento da linha
            atual = atual->direita;
        }
        atual->direita = (Matrix*) malloc(sizeof(Matrix)); // Aloca o nó do elemento
        alocacoes++;
        if (atual->direita == NULL){
            printf("malloc devolveu NULL.\n");
            exit(1);
        }
        elemento = atual->direita; // Aponta para o elemento criado
        elemento->linha = i;
        elemento->coluna = j;
        elemento->info = valor;
        elemento->direita = cabeca;

        cabeca = m;
        aux = -1;
        while(aux != j){ // Percorre o cabeçalho das colunas até a coluna do elemento
            cabeca = cabeca->direita;
            aux++;
        }
        atual = cabeca;
        while(atual->abaixo != cabeca){ // Percorre até o ultimo elemento da linha
            atual = atual->abaixo;
        }
        atual->abaixo = elemento;
        elemento->abaixo = cabeca;
    }
    fclose(fr);
    return m;
}
void matrix_destroy( Matrix* m ){
    Matrix *cabeca,*atual,*anterior; // atual: nó atual; cabeca: nó do cabeçalho percorrido; Anterior: nó anterior
    cabeca = m;
    if(cabeca->abaixo != m){ // Se há linhas na matriz
        cabeca = cabeca->abaixo;
        while(cabeca->abaixo != m){ // Percorre o cabeçalho de linhas
            atual = cabeca;
            while(atual->direita != cabeca){ // Percorre as linhas liberando
                anterior = atual;
                atual = atual->direita;
                if(anterior != cabeca){
                    free(anterior);
                    desalocacoes++;
                }
            }
            anterior = cabeca;
            cabeca = cabeca->abaixo;
            if(atual != anterior){
                free(atual);
                desalocacoes++;
            }
            free(anterior);
            desalocacoes++;
        }
        atual = cabeca;
        while(atual->direita != cabeca){ // percorre a ultima linha liberando
            anterior = atual;
            atual = atual->direita;
            if(anterior != cabeca){
                free(anterior);
                desalocacoes++;
            }
        }
        free(atual);
        desalocacoes++;
        free(cabeca);
        desalocacoes++;
        // Se tem linha tem coluna...
        cabeca = m->direita;
        while(cabeca->direita != m){
            anterior = cabeca;
            cabeca = cabeca->direita;
            free(anterior);
            desalocacoes++;
        }
        if(cabeca != NULL){
            free(cabeca);
            desalocacoes++;
        }
    }
    free(m);
    desalocacoes++;
}
void matrix_print( Matrix* m ){
    FILE* fw = fopen("prints.txt","a");
    int i=0,j=0;
    Matrix *atual,*cabeca;
    cabeca = m;
    while(cabeca->abaixo != m){
        cabeca = cabeca->abaixo;
        i++;
    }
    cabeca = m;
    while(cabeca->direita != m){
        cabeca = cabeca->direita;
        j++;
    }
    fprintf(fw,"%d %d\n",i,j);
    cabeca = m;
    while(cabeca->abaixo != m){
        cabeca = cabeca->abaixo;
        atual = cabeca;
        while(atual->direita != cabeca){
            atual = atual->direita;
            fprintf(fw,"%d %d %.1f\n",atual->linha,atual->coluna,atual->info);
        }
    }
    fprintf(fw,"\n");
    fclose(fw);
}
void printMat( Matrix* m ){
    int i=0,j=0;
    Matrix *atual,*cabeca;
    cabeca = m;
    while(cabeca->abaixo != m){
        cabeca = cabeca->abaixo;
        i++;
    }
    cabeca = m;
    while(cabeca->direita != m){
        cabeca = cabeca->direita;
        j++;
    }
    printf("%d %d\n",i,j);
    cabeca = m;
    while(cabeca->abaixo != m){
        cabeca = cabeca->abaixo;
        atual = cabeca;
        while(atual->direita != cabeca){
            atual = atual->direita;
            printf("%d %d %.1f\n",atual->linha,atual->coluna,atual->info);
        }
    }
    printf("\n");

}
