#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct ab{
    int info;
    struct ab *dir;
    struct ab *esq;
}AB;

//AB* ab_criar( void );
AB* ab_criarNo( int info );
void ab_liberar( AB *no );
//AB* ab_inserir( AB *no );
void ab_imprimir( AB *no, int tab );
AB* ab_copiar( AB *no );
AB* ab_inverter( AB *no );
AB* ab_maior( AB *no );
AB* ab_menor( AB *no );

int main(){
    AB *raiz = ab_criarNo(1);
    raiz->esq = ab_criarNo(2);
    raiz->dir = ab_criarNo(5);
    raiz->esq->esq = ab_criarNo(3);
    raiz->esq->dir = ab_criarNo(4);
    ab_imprimir(raiz,2);
    printf("\n\n");
    ab_liberar(raiz);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}
/*
AB* ab_criar( void ){
    return NULL;
}
*/
AB* ab_criarNo( int info ){
    AB *novo = (AB*) malloc(sizeof(AB));
    alocacoes++;
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
void ab_liberar( AB *no ){
    if(no != NULL){
        ab_liberar(no->esq);
        ab_liberar(no->dir);
        free(no);
        desalocacoes++;
    }
}
void ab_imprimir( AB *no, int tab ){
    for(int i=0; i<tab; i++){
        printf("-");
    }
    if(no != NULL){
        printf(" %d\n",no->info);
        ab_imprimir(no->esq,tab+2);
        printf("\n");
        ab_imprimir(no->dir,tab+2);
    }else{
        printf("vazio");
    }
}
AB* ab_copiar( AB *no ){
    AB *novo = NULL;
    if(no != NULL){
        novo = (AB*) malloc(sizeof(AB));
        alocacoes++;
        novo->info = no->info;
        novo->esq = ab_copiar(no->esq);
        novo->dir = ab_copiar(no->dir);
    }
    return novo;
}
AB* ab_inverter( AB *no ){
    AB *novo = NULL;
    if(no != NULL){
        novo = (AB*) malloc(sizeof(AB));
        alocacoes++;
        novo->info = no->info;
        novo->esq = ab_copiar(no->dir);
        novo->dir = ab_copiar(no->esq);
    }
    return novo;
}
AB* ab_maior( AB *no ){
    if(no == NULL){
        return NULL;
    }
    AB* maiorEsq = ab_maior(no->esq);
    AB* maiorDir = ab_maior(no->dir);
    AB* max = no;
    if((maiorEsq != NULL)&&(maiorEsq->info > max->info)){
        max = maiorEsq;
    }
    if((maiorDir != NULL)&&(maiorDir->info > max->info)){
        max = maiorDir;
    }
    return max;
}
AB* ab_menor( AB *no ){
    if(no == NULL){
        return NULL;
    }
    AB* menorEsq = ab_menor(no->esq);
    AB* menorDir = ab_menor(no->dir);
    AB* min = no;
    if((menorEsq != NULL)&&(menorEsq->info < min->info)){
        min = menorEsq;
    }
    if((menorDir != NULL)&&(menorDir->info < min->info)){
        min = menorDir;
    }
    return min;
}

