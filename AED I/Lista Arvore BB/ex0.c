#include <stdio.h>
#include <stdlib.h>
int alocacoes;
int desalocacoes;

typedef struct noA{
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

int main(){
    int retorno;
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
    if(no == NULL){
        no = (TNoA*) malloc(sizeof(TNoA));
        if(no == NULL){
            printf("Malloc devolveu NULL!!!\n");
            exit(1);
        }
        alocacoes++;
        no->chave = chave;
        no->info = info;
        no->dir = NULL;
        no->esq = NULL;
    }else if(chave < no->chave){
        no->esq = abb_inserir(no->esq,chave,info);
    }else if(chave > no->chave){
        no->dir = abb_inserir(no->dir,chave,info);
    }else{
        printf("Insercao invalida, essa chave ja existe.\n");
    }
    return no;
}
TNoA* abb_buscar( TNoA *no,int chave ){
    if(no == NULL){
        printf("Chave nao encontrada.\n");
        return NULL;
    }else if(no->chave == chave){
        return no;
    }else if(no->chave > chave){
        abb_buscar(no->esq,chave);
    }else{
        abb_buscar(no->dir,chave);
    }
}
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

