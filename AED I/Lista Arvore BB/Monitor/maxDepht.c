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

int abb_depht( TNoA *no );

int main(){
    TNoA* raiz = abb_criar();
    raiz = abb_inserir(raiz,10);
    raiz = abb_inserir(raiz,7);
    raiz = abb_inserir(raiz,12);
    raiz = abb_inserir(raiz,1);
    raiz = abb_inserir(raiz,11);
    raiz = abb_inserir(raiz,15);
    abb_imprimir(raiz,2);
    printf("\n\n");

    int profundidade = abb_depht(raiz);
    printf("profundidade = %d\n\n",profundidade);

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

int abb_depht( TNoA *no ){
    if(no == NULL){
        return -1;
    }else{
        int pesq = abb_depht(no->esq);
        int pdir = abb_depht(no->dir);
        int pmax;
        if(pesq > pdir){
            pmax = pesq;
        }else{
            pmax = pdir;
        }
        return 1 + pmax;
    }
}