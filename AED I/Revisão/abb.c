#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct noa{
    int chave, info;
    struct noa *esq,*dir;
}Noa;

Noa* criarNo( int chave, int info );

Noa* criar_abb( void );
void liberar_abb( Noa* no );
Noa* inserir_abb( Noa *no, int chave, int info );
Noa* remover_abb( Noa *no, int chave );
void imprimir_abb( Noa *no, int tab );

void imprimir_preOrdem( Noa *no );
void imprimir_simOrdem( Noa *no );
void imprimir_posOrdem( Noa *no );

int maior_abb( Noa *no );
Noa* menor_abb( Noa *no );

Noa* buscar_abb( Noa *no, int chave );
int maioresX_abb( Noa *no, int x );

int main(){
    Noa* raiz = criar_abb();
    raiz = inserir_abb(raiz,5,10);
    raiz = inserir_abb(raiz,2,20);
    raiz = inserir_abb(raiz,7,30);
    raiz = inserir_abb(raiz,1,40);
    raiz = inserir_abb(raiz,3,50);
    imprimir_abb(raiz,2);
    printf("\n\n");



    /*
    imprimir_preOrdem(raiz);
    printf("\n\n");
    imprimir_simOrdem(raiz);
    printf("\n\n");
    imprimir_posOrdem(raiz);
    printf("\n\n");
    */

    liberar_abb(raiz);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}

Noa* criarNo( int chave, int info ){
    Noa *novo = (Noa*) malloc(sizeof(Noa));
    if(novo == NULL){
        printf("Malloc devolveu NULL.\n\n");
        exit(1);
    }
    alocacoes++;
    novo->chave = chave;
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Noa* criar_abb( void ){
    return NULL;
}
void liberar_abb( Noa* no ){
    if(no != NULL){
        liberar_abb(no->esq);
        liberar_abb(no->dir);
        free(no);
        desalocacoes++;
    }
}
Noa* inserir_abb( Noa *no, int chave, int info ){
    if(no == NULL){
        Noa *novo = (Noa*) malloc(sizeof(Noa));
        if(novo == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        novo->chave = chave;
        novo->info = info;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }else if(chave < no->chave){
        no->esq = inserir_abb(no->esq,chave,info);
    }else if(chave > no->chave){
        no->dir = inserir_abb(no->dir,chave,info);
    }else{
        printf("Chave ja existe na arvore.\n\n");
    }
    return no;
}
Noa* remover_abb( Noa *no, int chave ){
    if(no == NULL){
        printf("Chave nao encontrada.\n\n");
        return no;
    }else if(chave < no->chave){
        no->esq = remover_abb(no->esq,chave);
        return no;
    }else if(chave > no->chave){
        no->dir = remover_abb(no->dir,chave);
        return no;
    }else{
        if((no->esq == NULL)&&(no->dir == NULL)){
            free(no);
            desalocacoes++;
            return NULL;
        }else if(no->esq == NULL){
            Noa* temp = no;
            no = no->dir;
            free(temp);
            desalocacoes++;
            return no;
        }else if(no->dir == NULL){
            Noa* temp = no;
            no = no->esq;
            free(temp);
            desalocacoes++;
            return no;
        }else{
            Noa *temp = no->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }
            int aux = no->info;
            no->chave = temp->chave;
            no->info = temp->info;
            temp->info = aux;
            temp->chave = chave;
            remover_abb(no->esq,chave);
            return no;
        }
    }
}
void imprimir_abb( Noa *no, int tab ){
    for(int i=0; i<tab; i++){
        printf("-");
    }
    if(no == NULL){
        printf(" vazio");
    }else{
        printf(" %d: info = %d\n",no->chave,no->info);
        imprimir_abb(no->esq,tab+2);
        printf("\n");
        imprimir_abb(no->dir,tab+2);
    }
}
void imprimir_preOrdem( Noa *no ){
    if(no != NULL){
        printf("%d\t",no->chave);
        imprimir_preOrdem(no->esq);
        imprimir_preOrdem(no->dir);
    }
}
void imprimir_simOrdem( Noa *no ){
    if(no != NULL){
        imprimir_simOrdem(no->esq);
        printf("%d\t",no->chave);
        imprimir_simOrdem(no->dir);
    }
}
void imprimir_posOrdem( Noa *no ){
    if(no != NULL){
        imprimir_posOrdem(no->esq);
        imprimir_posOrdem(no->dir);
        printf("%d\t",no->chave);
    }
}
/*
int maior_abb( Noa *no ){
    if (no == NULL){
        return -1;
    }
    while(no->dir != NULL){
        no = no->dir;
    }
    return no->chave;
}
*/
int maior_abb( Noa *no ){
    if (no == NULL){
        return -1;
    }else if(no->dir == NULL){
        return no->chave;
    }else{
        return maior_abb(no->dir);
    }
}
Noa* menor_abb( Noa *no ){
    if (no == NULL){
        return NULL;
    }else if(no->esq == NULL){
        return no;
    }else{
        return menor_abb(no->esq);
    }
}
Noa* buscar_abb( Noa *no, int chave ){
    if(no == NULL){
        return NULL;
    }else if(chave < no->chave){
        return buscar_abb(no->esq,chave);
    }else if(chave > no->chave){
        return buscar_abb(no->dir,chave);
    }else{
        return no;
    }
}
int maioresX_abb( Noa *no, int x ){
    if(no == NULL){
        return 0;
    }else{
        int maiores = 0;
        if(no->chave > x){
            maiores++;
        }
        maiores += maioresX_abb(no->esq,x);
        maiores += maioresX_abb(no->dir,x);
        return maiores;
    }
}


/*
int verifica_abb( Noa *no ){
    if(no == NULL){
        return 1;
    }else if((no->esq == NULL)&&(no->dir == NULL)){
        return 1;
    }else if(no->esq == NULL){
        if(no->chave < no->dir->chave){
            return (verifica_abb(no->dir) && 1);
        }else{
            return 0;
        }
    }else if(no->dir == NULL){
        if(no->chave > no->esq->chave){
            return (verifica_abb(no->esq) && 1);
        }else{
            return 0;
        }
    }else{
        int retorno = 0;
        if(no->chave > no->esq->chave){
            retorno = (verifica_abb(no->esq) && 1);
            if(no->chave < no->dir->chave){
                retorno = (verifica_abb(no->dir) && 1);
            }else{
                retorno = 0;
            }
        }else{
            retorno = 0;
        }
        return retorno;
    }
}
*/