#include <stdio.h>
#include <stdlib.h>

int aloca = 0; // Variaveis globais!!!
int desal = 0; // Variaveis globais!!!

typedef struct node{ // Nó da fila.
    float info; // Informação do nó.
    struct node* next; // Próximo nó.
    struct node* prev; // Nó anterior.
}Node;
typedef struct queue{ // Fila.
    int n; // Quantidade de nós da fila.
    Node* start; // Nó inicial da fila.
}Queue;

Queue* queue_create( void );
void queue_destroy( Queue* q );
void queue_insert( Queue* q, float v );
float queue_remove( Queue* q );
void queue_invert( Queue* q );
int queue_empty( Queue* q );
void queue_print( Queue* q );
int interface( Queue* q );

int main(){
    int exit;
    Queue* q = queue_create();
    do{
        exit = interface(q);
    }while(exit == 0);
    queue_destroy(q);
    printf("%d alocacoes.\n",aloca);
    printf("%d desalocacoes.\n",desal);
    return 0;
}
Queue* queue_create( void ){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    aloca++;
    if(q == NULL){
        printf("Malloc devolveu NULL.\n");
        exit(1);
    }
    q->n = 0;
    q->start = NULL;
    return q;
}
void queue_destroy( Queue* q ){
    if(q->start != NULL){
        Node *anterior, *atual = q->start;
        while(atual->next != NULL){
            anterior = atual;
            atual = atual->next;
            free(anterior);
            desal++;
        }
        free(atual);
        desal++;
    }
    free(q);
    desal++;
}
void queue_insert( Queue* q, float v ){
    Node* novo = (Node*) malloc(sizeof(Node));
    aloca++;
    if(novo == NULL){
        printf("Malloc devolveu NULL.\n");
        exit(1);
    }
    q->n++;
    novo->info = v;
    novo->next = NULL;
    novo->prev = NULL;
    if(q->start == NULL){
        q->start = novo;
    }else{
        Node* atual = q->start;
        while(atual->next != NULL){
            atual = atual->next;
        }
        atual->next = novo;
        novo->prev = atual;
    }
}
float queue_remove( Queue* q ){
    if(q->start == NULL){
        printf("Fila vazia.\n");
        return 0;
    }else{
        Node* atual = q->start;
        float v = atual->info;
        q->start = atual->next;
        if(q->start != NULL){
            q->start->prev = NULL;
        }
        free(atual);
        desal++;
        return v;
    }
}
void queue_invert( Queue* q ){
    if(q->n <= 1){
        printf("Fila Invertida.\n");
    }else{
        Node *anterior, *atual = q->start;
        while(atual->next != NULL){
            atual = atual->next;
        }
        q->start = atual;
        atual = atual->prev;
        q->start->next = atual;
        q->start->prev = NULL;
        while(atual != NULL){
            anterior = atual;
            atual = atual->prev;
            anterior->prev = anterior->next;
            anterior->next = atual;
        }
        printf("Fila Invertida.\n");
    }
}
int queue_empty( Queue* q ){
    if(q->n == 0){
        return 1;
    }else{
        return 0;
    }
}
void queue_print( Queue* q ){
    printf("<--[");
    if(q->start != NULL){
        Node* atual = q->start;
        while(atual->next != NULL){
            printf(" %.2f",atual->info);
            atual = atual->next;
        }
        printf(" %.2f",atual->info);
    }
    printf(" ]<--\n\n");
}
int interface( Queue* q ){
    int op;
    float valor;
    printf("--------< Menu >--------\n");
    printf(" 1 - inserir elemento.\n");
    printf(" 2 - remover elemento.\n");
    printf(" 3 - verificar lista.\n");
    printf(" 4 - inverter lista.\n");
    printf(" 5 - imprimir lista.\n");
    printf(" 6 - Sair.\n");
    printf("------------------------\n");
    printf("Escolha uma opcao:");
    scanf("%d",&op);
    getchar();
    printf("\n");
    system("cls");
    switch (op){
    case 1:
        printf("Elemento para inserir:");
        scanf("%f",&valor);
        getchar();
        printf("\n");
        queue_insert(q,valor);
        return 0;
    case 2:
        valor = queue_remove(q);
        printf("Elemento removido: %.2f",valor);
        return 0;
    case 3:
        if(queue_empty(q)){
            printf("Lista Vazia.\n");
        }else{
            printf("Lista nao vazia.\n");
        }
        return 0;
    case 4:
        queue_invert(q);
        return 0;
    case 5:
        queue_print(q);
        return 0;
    default:
        printf("Saindo.\n");
        return 1;
    }
}
