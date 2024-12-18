#include <stdio.h>
#include <stdlib.h>

int i=0;
int arr[101]={0};

typedef struct noA{
    int info;
    struct noA *esq;
    struct noA *dir;
}TNoA;

TNoA* abb_criar( void );
TNoA* abb_inserir( TNoA *no,int info );
void abb_liberar( TNoA *no );
void abb_imprimir( TNoA *no, int tab );

TNoA* abb_inserirInverso( TNoA *no,int info );
TNoA* abb_inverter( TNoA *no );

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

    TNoA* raiz2 = abb_inverter(raiz);
    abb_imprimir(raiz2,2);
    printf("\n\n");
    
    abb_liberar(raiz);
    abb_liberar(raiz2);
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
TNoA* abb_inverter( TNoA* no ){
    TNoA *novo = NULL;
    if(no != NULL){
        novo = (TNoA*) malloc(sizeof(TNoA));
        if(novo == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        novo->info = no->info;
        novo->esq = abb_inverter(no->dir);
        novo->dir = abb_inverter(no->esq);
    }
    return novo;
}
