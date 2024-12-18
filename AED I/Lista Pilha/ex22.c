#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista {
    char nome[81];
    int matricula;
    char turma;
    float p1;
    float p2;
    float p3;
    struct lista* prox;
};
typedef struct lista Lista;
Lista* list_create( void );
void list_destroy( Lista* l );
Lista* insere_ord(Lista* l, char* nome, int matricula, char turma, float p1, float p2, float p3);
void list_print(Lista* l);

int main(){
    Lista* l = list_create();
    l = insere_ord(l,"junior",15,'T',5.0,5.0,5.0);
    list_print(l);
    l = insere_ord(l,"mateus",11,'T',9.0,9.0,9.0);
    l = insere_ord(l,"creito",12,'T',7.0,7.0,7.0);
    l = insere_ord(l,"avoado",77,'T',9.0,4.0,5.0);
    list_print(l);
    list_destroy(l);
    return 0;
}

Lista* list_create( void ){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l = NULL;
    return l;
}
void list_destroy( Lista* l ){
    Lista* atual = l;
    while(atual != NULL){
        Lista* temp = atual;
        atual = atual->prox;
        free(temp);
        printf("No desalocado.\n");
    }
    free(l);
    printf("Lista desalocada.\n");
}
Lista* insere_ord(Lista* l, char* nome, int matricula, char turma, float p1, float p2, float p3){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    strcpy(novo->nome,nome);
    novo->matricula = matricula;
    novo->turma = turma;
    novo->p1 = p1;
    novo->p2 = p2;
    novo->p3 = p3;
    novo->prox = NULL;
    float novamed = (p1+p2+p3)/3;
    if (l == NULL || novamed <= (l->p1+l->p2+l->p3)/3) {
        novo->prox = l;
        return novo;
    }
    Lista* atual = l;
    while (atual->prox != NULL && novamed > (atual->prox->p1+atual->prox->p2+atual->prox->p3)/3) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return l;
}
void list_print(Lista* l){
    Lista* atual = l;
    while(atual != NULL){
        printf("No: %p\n",atual);
        printf("Nome: %s\n",atual->nome);
        atual = atual->prox;
    }
}

