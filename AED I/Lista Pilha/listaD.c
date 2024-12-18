#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct List{
    int qnt;
    Node* head;
}List;
List* list_create( void ); // cria lista vazia
void list_destroy( List* l);
List* list_insert( List* l, int i ); //insere nó com informação i no início da lista
List* list_remove( List* l, int v ); //retira nó com informação v
int list_empty(List* l); //retorna 1 se lista vazia
Node* list_get(List* l, int v); //retorna ponteiro para nó com informação v
void list_print(List* l); //imprime conteúdo da lista em stdout

int main(){
    List* l = list_create();
    int n = list_empty(l);
    printf("Lista vazia: %d\n",n);
    l = list_insert(l,10);
    l = list_insert(l,5);
    l = list_insert(l,3);
    n = list_empty(l);
    printf("Lista vazia: %d\n",n);
    Node* no = list_get(l,5);
    printf("no %p, info: %d\n",no,no->data);
    list_print(l);
    list_remove(l,5);
    list_print(l);
    list_destroy(l);
    return 0;
}
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
        l->qnt--;
        printf("No desalocado.\n");
    }
    free(l);
    printf("Lista desalocada.\n");
}
List* list_insert( List* l, int i ){
    Node* p;
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->data = i;
    novo->next = l->head;
    if(novo->next != NULL){
        p = novo->next;
        p->prev = novo;
    }
    novo->prev = NULL;
    l->head = novo;
    l->qnt++;
    return l;
}
List* list_remove( List* l, int v ){
    if(l == NULL || l->head == NULL){
        return l;
    }
    Node* atual = l->head;
    Node* p;
    while(atual != NULL && atual->data != v){
        atual = atual->next;
    }
    if(atual == NULL){
        return l;
    }
    if(atual->prev == NULL){
        l->head = atual->next;
        if(atual->next != NULL){
            p = atual->next;
            p->prev = NULL;
        }
    }else{
        p = atual->prev;
        p->next = atual->next;
        p = atual->next;
        p->prev = atual->prev;
    }
    free(atual);
    printf("No desalocado.\n");
    l->qnt--;
    return l;
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