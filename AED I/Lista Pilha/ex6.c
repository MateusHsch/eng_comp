/*
6. Faça uma função para concatenar duas listas em uma terceira lista que deverá
ser retornada pela função.
*/
#include <stdio.h>
#include <stdlib.h>
/* ----------< struct list.c >----------- */
typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct List{
    int qnt;
    Node* head;
}List;
/* ----------< list.h >---------- */
List* list_create( void ); // cria lista vazia
void list_destroy( List* l);
void list_insert( List* l, int i ); //insere nó com informação i no início da lista
void list_endinsert( List* l, int i ); //insere nó com informação i no início da lista
void list_remove( List* l, int v ); //retira nó com informação v
int list_nremove( List* l, int n ); //retira os n primeiros nos da lista
int list_empty(List* l); //retorna 1 se lista vazia
Node* list_get(List* l, int v); //retorna ponteiro para nó com informação v
void list_print(List* l); //imprime conteúdo da lista em stdout
List* list_cat(List* l1,List* l2); //concatena l1 com l2 e retorna lr
int list_nremove( List* l, int n );  //remove n elementos da lista
int list_high(List* l, int* maior, int* idx); //retorna o maior elemento e seu indice
/* ----------< main.c >----------- */
int main(){
    List* l = list_create();
    List* p = list_create();
    int n = list_empty(l);
    printf("Lista l vazia: %d\n",n);
    list_endinsert(l,3);
    list_endinsert(l,5);
    list_endinsert(l,10);
    list_endinsert(p,4);
    list_endinsert(p,2);
    n = list_empty(l);
    printf("Lista l vazia: %d\n",n);
    list_print(l);
    printf("\n");
    list_print(p);
    printf("\n");
    List* d = list_cat(l,p);
    list_print(d);
    printf("\n");
    int maior,idx;
    int ok = list_high(d,&maior,&idx);
    printf("high: %d\n",ok);
    printf("o maior elemento e %d na posicao %d\n",maior,idx);
    printf("\n");
    list_destroy(l);
    list_destroy(p);
    list_destroy(d);
    return 0;
}
/* ----------< list.c >---------- */
List* list_create( void ){
    List* l = (List*) malloc(sizeof(List));
    l->head = NULL;
    l->qnt = 0;
    return l;
}
void list_destroy( List* l ){
    Node* atual = l->head;
    while(atual != NULL){
        Node* temp = atual;
        atual = atual->next;
        free(temp);
        printf("No desalocado.\n");
    }
    free(l);
    printf("Lista desalocada.\n");
}
void list_insert( List* l, int i ){
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->data = i;
    novo->next = l->head;
    l->head = novo;
    l->qnt++;;
}
void list_endinsert( List* l, int i ){
    int n = l->qnt;
    if(n != 0){
        Node* atual = l->head;
        while(atual->next != NULL){
            atual = atual->next;
        }
        Node* novo = (Node*) malloc(sizeof(Node));
        atual->next = novo;
        novo->data = i;
        novo->next = NULL;
        l->qnt++;
    }else{
        Node* novo = (Node*) malloc(sizeof(Node));
        l->head = novo;
        novo->data = i;
        novo->next = NULL;
        l->qnt++;
    }
}
void list_remove( List* l, int v ){
    if(l != NULL && l->head != NULL){
        Node* atual = l->head;
        Node* anter = NULL;
        while(atual != NULL && atual->data != v){
            anter = atual;
            atual = atual->next;
        }
        if(anter == NULL){
            l->head = atual->next;
        }else if(atual != NULL){
            anter->next = atual->next;
        }
        if (atual != NULL){
            free(atual);
            printf("No desalocado.\n");
            l->qnt--;
        }
    } 
}
int list_empty(List* l){
    if(l->qnt == 0){
        return 1;
    }else{
        return 0;
    }
}
Node* list_get(List* l, int v){
    Node* atual = l->head;
    while(atual != NULL && atual->data != v){
        atual = atual->next;
    }
    if(atual == NULL){
        printf("Elemento nao encontrado.\n");
        return atual;
    }else{
        return atual;
    }
}
void list_print(List* l){
    Node* atual = l->head;
    while(atual != NULL){
        printf("No: %p\n",atual);
        printf("info: %d\n",atual->data);
        atual = atual->next;
    }
}
List* list_cat(List* l1,List* l2){
    List* lf = list_create();
    Node* atual = l1->head;
    while(atual != NULL){
        list_endinsert(lf,atual->data);
        atual = atual->next;
    }
    atual = l2->head;
    while(atual != NULL){
        list_endinsert(lf,atual->data);
        atual = atual->next;
    }
    return lf;
}
int list_nremove( List* l, int n ){
    Node* atual = l->head;
    Node* anter = NULL;
    while(n > 0 && l->head != NULL){
        anter = atual;
        atual = atual->next;
        free(anter);
        printf("No desalocado.\n");
        l->head = atual;
        n--;
        l->qnt--;
    }
    if(n == 0){
        return 1;
    }else{
        return 0;
    }
}
int list_high(List* l, int* maior, int* idx){
    Node* atual = l->head;
    int qnt=-1;
    *idx = qnt;
    if(atual != NULL){
        *maior = atual->data;
        atual = atual->next;
        qnt++;
        *idx = qnt;
    }
    while(atual != NULL){
        qnt++;
        if(*maior < atual->data){
            *maior = atual->data;
            *idx = qnt;
        }
        atual = atual->next;
    }
    if (*idx == -1){
        return 0;
    }else{
        return 1;
    }
}
