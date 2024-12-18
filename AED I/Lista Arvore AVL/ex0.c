#include <stdio.h>
#include <stdlib.h>
int alocacoes;
int desalocacoes;

typedef struct noA{
    int fb;
    int chave;
    char info;
    struct noA *esq;
    struct noA *dir;
}TNoA;

TNoA* abb_criar( void );
TNoA* abb_inserir( TNoA *no,int chave,char info );
TNoA* abb_buscar( TNoA *no,int chave );
TNoA* abb_remover( TNoA *no,int chave );
void abb_imprimir( TNoA *no,int tab );
void abb_liberar( TNoA *no );

int abb_profundidade( TNoA *no );
TNoA* abb_fb( TNoA *no,int chave );
TNoA* abb_rotsimplesDir( TNoA *no );
TNoA* abb_rotduplaDir( TNoA *no );
TNoA* abb_rotsimplesEsq( TNoA *no );
TNoA* abb_rotduplaEsq( TNoA *no );

int main(){
    TNoA* raiz = abb_criar();
    raiz = abb_inserir(raiz,10,'A');
    raiz = abb_inserir(raiz,7,'B');
    raiz = abb_inserir(raiz,12,'C');
    raiz = abb_inserir(raiz,3,'D');
    raiz = abb_inserir(raiz,11,'E');
    raiz = abb_inserir(raiz,15,'F');
    abb_imprimir(raiz,1);
    printf("\n\n");

    abb_liberar(raiz);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}

TNoA* abb_criar( void ){
    return NULL;
}
TNoA* abb_inserir( TNoA *no,int chave,char info ){
    TNoA *atual = abb_buscar(no,chave);
    if(atual == NULL){
        atual = (TNoA*) malloc(sizeof(TNoA));
        if(atual == NULL){
            printf("Malloc devolveu NULL!!!\n");
            exit(1);
        }
        alocacoes++;
        atual->chave = chave;
        atual->info = info;
        atual->dir = NULL;
        atual->esq = NULL;
        atual->fb = 0;
        printf("oi.\n");
        no = abb_fb(no,chave);
    }else{
        printf("Insercao invalida, essa chave ja existe.\n");
    }
    return no;
}
TNoA* abb_buscar( TNoA *no,int chave ){
    if(no == NULL){
        printf("Chave nao encontrada.\n");
        return NULL;
    }else if(no->chave > chave){
        return abb_buscar(no->esq,chave);
    }else if(no->chave < chave){
        return abb_buscar(no->dir,chave);
    }else{
        return no;
    }
}
int abb_profundidade( TNoA *no ){
    if (no == NULL){
        return -1;
    }else{
        int pesq = abb_profundidade(no->esq);
        int pdir = abb_profundidade(no->dir);
        int pmax;
        if(pesq > pdir){
            pmax = pesq;
        }else{
            pmax = pdir;
        }
        return 1 + pmax;
    }
}
TNoA* abb_fb( TNoA *no,int chave ){
    printf("oi.\n");
    printf("chave = %d.\n",chave);
    if(no->chave > chave){
        no = abb_fb(no->esq,chave);
        no->fb = abb_profundidade(no->esq) - abb_profundidade(no->dir);
        printf("%d tem fb %d.\n",no->chave,no->fb);
        if((no->esq->fb = 1)&&(no->fb = 2)){
            no = abb_rotsimplesDir(no);
        }else if((no->esq->fb = -1)&&(no->fb = 2)){
            no = abb_rotduplaDir(no);
        }else if((no->esq->fb = -1)&&(no->fb = -2)){
            no = abb_rotsimplesEsq(no);
        }else if((no->esq->fb = 1)&&(no->fb = -2)){
            no = abb_rotduplaEsq(no);
        }
    }else if(no->chave < chave){
        no = abb_fb(no->dir,chave);
        no->fb = abb_profundidade(no->esq) - abb_profundidade(no->dir);
        printf("%d tem fb %d.\n",no->chave,no->fb);
        if((no->esq->fb = 1)&&(no->fb = 2)){
            no = abb_rotsimplesDir(no);
        }else if((no->esq->fb = -1)&&(no->fb = 2)){
            no = abb_rotduplaDir(no);
        }else if((no->esq->fb = -1)&&(no->fb = -2)){
            no = abb_rotsimplesEsq(no);
        }else if((no->esq->fb = 1)&&(no->fb = -2)){
            no = abb_rotduplaEsq(no);
        }
    }else{
        printf("oi\n");
        no->fb = 0;
    }
    return no;
}
TNoA* abb_rotsimplesDir( TNoA *no ){
    TNoA *temp = no->esq;
    no->esq = temp->dir;
    temp->dir = no;
    return temp;
}
TNoA* abb_rotduplaDir( TNoA *no ){
    TNoA *temp1 = no->esq;
    TNoA *temp2 = temp1->dir;
    temp1->dir = temp2->esq;
    temp2->esq = temp1;
    no->esq = temp2;
    temp2->dir = no;
    no->esq = NULL;
    return temp2;
}
TNoA* abb_rotsimplesEsq( TNoA *no ){
    TNoA *temp = no->dir;
    no->dir = temp->esq;
    temp->esq = no;
    return no;
}
TNoA* abb_rotduplaEsq( TNoA *no ){
    TNoA *temp1 = no->dir;
    TNoA *temp2 = temp1->esq;
    temp1->esq = temp2->dir;
    temp2->dir = temp1;
    no->dir = temp2;
    temp2->esq = no;
    no->dir = NULL;
    return temp2;
}
/*
int abb_fb( TNoA *no ){
    int fb;
    fb = abb_profundidade(no->esq) - abb_profundidade(no->dir); 
    return fb;
}
*/
TNoA* abb_remover( TNoA *no,int chave ){
    if(no == NULL){
        return NULL;
    }else if(no->chave > chave){
        no->esq = abb_remover(no->esq,chave);
    }else if(no->chave < chave){
        no->dir = abb_remover(no->dir,chave);
    }else{ // Achou o nó a remover
        if((no->esq == NULL)&&(no->dir == NULL)){
            free(no);
            no = NULL;
        }else if(no->dir == NULL){
            TNoA *temp = no;
            no = no->esq;
            free(temp);
        }else if(no->esq == NULL){
            TNoA *temp = no;
            no = no->dir;
            free(temp);
        }else{
            int aux;
            TNoA *temp = no->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }
            aux = no->info;
            no->chave = temp->chave;
            no->info = temp->info;
            temp->info = aux;
            temp->chave = chave;
            no->esq = abb_remover(no->esq,chave);
        }
    }
    return no;
}
void abb_imprimir( TNoA *no,int tab ){
    for(int i=0;i<tab;i++){
        printf("-");
    }
    if(no != NULL){
        printf(" %d: %c\n",no->chave,no->info);
        abb_imprimir(no->esq,tab+2);
        printf("\n");
        abb_imprimir(no->dir,tab+2);
    }else{
        printf(" vazio");
    }
}
void abb_liberar( TNoA *no ){
    if((no->dir == NULL)&&(no->esq == NULL)){
        free(no);
        desalocacoes++;
    }else{
        if(no->esq != NULL){
            abb_liberar( no->esq );
        }
        if(no->dir != NULL){
            abb_liberar( no->dir );
        }
        free(no);
        desalocacoes++;
    }
}
