#include <stdio.h>
#include <stdlib.h>

typedef struct noA{
    int info;
    struct noA *esq;
    struct noA *dir;
}TNoA;

TNoA* abb_criar( void );
TNoA* abb_inserir( TNoA *no,int info );
void abb_liberar( TNoA *no );
void abb_imprimir( TNoA *no, int tab );

TNoA* increasingBST(TNoA* root);
void inorder(TNoA* root, TNoA** newRoot, TNoA** curr);

int main(){
    TNoA* raiz = abb_criar();
    raiz = abb_inserir(raiz,10);
    raiz = abb_inserir(raiz,7);
    raiz = abb_inserir(raiz,12);
    raiz = abb_inserir(raiz,3);
    raiz = abb_inserir(raiz,11);
    raiz = abb_inserir(raiz,15);
    abb_imprimir(raiz,2);
    printf("\n\n");

    TNoA* raiz2 = increasingBST(raiz);
    abb_imprimir(raiz2,2);
    printf("\n\n");

    abb_liberar(raiz);
    return 0;
}
TNoA* abb_criar( void ){
    return NULL;
}
TNoA* abb_inserir( TNoA *no,int info ){
    if(no == NULL){
        no = (TNoA*) malloc(sizeof(TNoA));
        if(no == NULL){
            printf("Malloc devolveu NULL!!!\n");
            exit(1);
        }
        no->info = info;
        no->dir = NULL;
        no->esq = NULL;
    }else if(info < no->info){
        no->esq = abb_inserir(no->esq,info);
    }else if(info > no->info){
        no->dir = abb_inserir(no->dir,info);
    }else{
        printf("Insercao invalida, essa info ja existe.\n");
    }
    return no;
}
void abb_liberar( TNoA *no ){
    if((no->dir == NULL)&&(no->esq == NULL)){
        free(no);
    }else{
        if(no->esq != NULL){
            abb_liberar( no->esq );
        }
        if(no->dir != NULL){
            abb_liberar( no->dir );
        }
        free(no);
    }
}
void abb_imprimir( TNoA *no, int tab ){
    for(int i=0; i<tab; i++){
        printf("-");
    }
    if(no != NULL){
        printf(" %d\n",no->info);
        abb_imprimir(no->esq,tab+2);
        printf("\n");
        abb_imprimir(no->dir,tab+2);
    }else{
        printf("vazio");
    }
}

TNoA* increasingBST(TNoA* raiz) {
    TNoA *novaRaiz = NULL, *atual = NULL;
    
    inorder(raiz, &novaRaiz, &atual);
    
    return novaRaiz;
}

void inorder(TNoA* raiz, TNoA** novaRaiz, TNoA** atual) {
    if (raiz == NULL) {
        return;
    }
    
    inorder(raiz->esq, novaRaiz, atual);
    
    if (*novaRaiz == NULL) {
        *novaRaiz = raiz;
    } else {
        (*atual)->dir = raiz;
    }
    *atual = raiz;
    raiz->esq = NULL;
    
    inorder(raiz->dir, novaRaiz, atual);
}