#include <stdio.h>
#include <stdlib.h>
typedef struct Lista{
    int info;
    struct Lista* prox;
}Lista;

Lista* lista_create();
void lista_detruir(Lista* l);
Lista* lista_inserir(Lista* l, int v);
Lista* lista_inserirfim(Lista* l, int v);
void lista_print(Lista* l);

int main(){
    Lista* l = lista_create();
    l = lista_inserirfim(l,5);
    lista_print(l);
    l = lista_inserir(l,10);
    l = lista_inserirfim(l,6);
    lista_print(l);
    lista_detruir(l);
    return 0;
}
Lista* lista_create(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l == NULL){
        printf("Espaco insuficiente.\n");
        exit(1);
    }
    l->prox = NULL;
    return l;
}
void lista_detruir(Lista* l){
    Lista* atual = l;
    while(atual != NULL){
        Lista* anter = atual;
        atual = atual->prox;
        free(anter);
        printf("No desalocado.\n");
    }
    free(l);
    printf("Lista desalocada.\n");
}
Lista* lista_inserir(Lista* l, int v){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Espaco insuficiente.\n");
        exit(1);
    }
    novo->info = v;
    novo->prox = l;
    return novo;
}
Lista* lista_inserirfim(Lista* l, int v){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Espaco insuficiente.\n");
        exit(1);
    }
    novo->info = v;
    Lista* atual = l;
    Lista* anter = NULL;
    while(atual != NULL){
        anter = atual;
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return l;
}
void lista_print(Lista* l){
    Lista* atual = l;
    while(atual != NULL){
        printf("endereco: %p ; info: %d\n",atual,atual->info);
        atual = atual->prox;
    }
    printf("\n");
}