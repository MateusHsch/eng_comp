#include <stdio.h>
#include <stdlib.h>
int alocacoes=0;
int desalocacoes=0;

typedef struct noArv{
    int info;
    struct noArv *esq;
    struct noArv *dir;
}NoArv;

NoArv* abb_criar( void );
void abb_liberar( NoArv *no );
void abb_imprimir( NoArv *no, int tab );
NoArv* abb_inserir( NoArv *no, int info );
NoArv* abb_remover( NoArv *no, int info );

NoArv* menor_valor(NoArv* a);


int main(){
    NoArv *raiz = abb_criar();
    raiz = abb_inserir(raiz,8);
    raiz = abb_inserir(raiz,3);
    raiz = abb_inserir(raiz,1);
    raiz = abb_inserir(raiz,6);
    raiz = abb_inserir(raiz,4);
    raiz = abb_inserir(raiz,7);
    raiz = abb_inserir(raiz,10);
    raiz = abb_inserir(raiz,14);
    raiz = abb_inserir(raiz,13);
    abb_imprimir(raiz,2);
    printf("\n\n");

    NoArv *menor = menor_valor(raiz);
    printf("menor valor = %d\n\n",menor->info);

    abb_liberar(raiz);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}
NoArv* abb_criar( void ){
    return NULL;
}
void abb_liberar( NoArv *no ){
    if(no != NULL){
        abb_liberar(no->esq);
        abb_liberar(no->dir);
        free(no);
        desalocacoes++;
    }
}
void abb_imprimir( NoArv *no, int tab ){
    for(int i=0;i<tab;i++){
        printf("-");
    }
    if(no != NULL){
        printf(" %d\n",no->info);
        abb_imprimir(no->esq,tab+2);
        printf("\n");
        abb_imprimir(no->dir,tab+2);
    }else{
        printf(" vazio");
    }
}
NoArv* abb_inserir( NoArv *no, int info ){
    if(no == NULL){
        no = (NoArv*) malloc(sizeof(NoArv));
        alocacoes++;
        if(no == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        no->info = info;
        no->dir = NULL;
        no->esq = NULL;
    }else if( info < no->info){
        no->esq = abb_inserir(no->esq,info);
    }else if( info > no->info ){
        no->dir = abb_inserir(no->dir,info);
    }else{
        printf("Elemento já existe.\n\n");
    }
    return no;
}
NoArv* abb_remover( NoArv *no, int info ){
    if(no == NULL){ // arvore vazia -> Nada;
        printf("Arvore vazia.\n\n");
    }else if(info < no->info){ // info à esquerda -> chama o remover para o nó da esquerda
        no->esq = abb_remover(no->esq,info);
    }else if(info > no->info){ // info à direita -> chama o remover para o nó da direita
        no->dir = abb_remover(no->dir,info);
    }else{ // info nesse nó -> remove
        if((no->esq == NULL)&&(no->dir == NULL)){
            free(no);
            desalocacoes++;
            no = NULL;
        }else if(no->esq == NULL){
            NoArv *temp = no;
            no = no->dir;
            free(temp);
            desalocacoes++;
        }else if(no->dir == NULL){
            NoArv *temp = no;
            no = no->esq;
            free(temp);
            desalocacoes++;
        }else{
            NoArv *temp = no->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }
            no->info = temp->info;
            temp->info = info;
            no->esq = abb_remover(no->esq,info);
        }
    }
    return no;
}
NoArv* menor_valor(NoArv* a){
    if(a == NULL){
        return NULL;
    }else{
        if(a->esq == NULL){
            return a;
        }else{
            return menor_valor(a->esq);
        }
    }
}
