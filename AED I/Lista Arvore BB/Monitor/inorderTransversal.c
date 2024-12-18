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

int* abb_inorderTranversal( TNoA *raiz,int *t );
void abb_inorder( TNoA *no,int *vet,int* t );

int main(){
    int t = 0;
    TNoA* raiz = abb_criar();
    raiz = abb_inserir(raiz,10);
    raiz = abb_inserir(raiz,7);
    raiz = abb_inserir(raiz,12);
    raiz = abb_inserir(raiz,3);
    raiz = abb_inserir(raiz,11);
    raiz = abb_inserir(raiz,15);
    abb_imprimir(raiz,2);
    printf("\n\n");

    int *vet = abb_inorderTranversal(raiz,&t);
    printf("[");
    for(int i=0;i<t;i++){
        printf(" %d",vet[i]);
    }
    printf(" ]\n");
    free(vet);

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

int* abb_inorderTranversal( TNoA *raiz,int *t ){
    int *vet = NULL;
    *t = 0;
    abb_inorder(raiz,vet,t);
    vet = (int *)malloc((*t)*sizeof(int));
    *t = 0;
    abb_inorder(raiz,vet,t);
    return vet;
}
void abb_inorder( TNoA *no,int * vet,int* t ){
    if(no != NULL){
        abb_inorder(no->esq,vet,t);
        if(vet != NULL){
            vet[*t] = no->info;
        }
        *t = *t +1;
        abb_inorder(no->dir,vet,t);
    }
}