#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    float data;             // Dado do nó
    struct Node* next;    // Ponteiro para o próximo nó
} Node;
typedef struct Stack {
    int n;
    Node* top;            // Ponteiro para o topo da pilha
} Stack;

Stack* stack_create();
void stack_destroy(Stack* s);
void stack_push(Stack* s, float v);
float stack_pop(Stack* s);
void stack_print(Stack* s);
void stack_transfeer(Stack* s1, Stack* s2);

int main(){
    Stack* s = stack_create();
    stack_push(s,2.0);
    stack_push(s,7.0);
    stack_push(s,5.0);
    stack_push(s,9.0);
    printf("%d\n",s->n);
    stack_print(s);
    Stack* sr = stack_create();
    stack_transfeer(s,sr);
    stack_print(sr);
    stack_destroy(s);
    stack_destroy(sr);
    return 0;
}
Stack* stack_create(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->n = 0;
    return s;
}
void stack_destroy( Stack* s ){
    Node* atual = s->top;
    while(atual != NULL){
        Node* temp = atual;
        atual = atual->next;
        free(temp);
        printf("No desalocado.\n");
    }
    free(s);
    printf("Pilha desalocada.\n");
}
void stack_push(Stack* s, float v){
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->next = s->top;
    novo->data = v;
    s->top = novo;
    s->n++;
}
float stack_pop(Stack* s){
    Node* atual = s->top;
    float v;
    if(atual == NULL){
        printf("Pilha está vazia.\n");
        exit(1);
    }else{
        s->top = atual->next;
        v = atual->data;
        free(atual);
        return v;
    }
}
void stack_print(Stack* s){
    Node* atual = s->top;
    printf("-->[");
    while(atual != NULL){
        printf(" %.2f;",atual->data);
        atual = atual->next;
    }
    printf(" ]\n\n");
}
void stack_transfeer(Stack* s1, Stack* s2){
    Stack* temp = stack_create();
    int i,n = s1->n;
    for(i=0;i<n;i++){
        stack_push(temp,stack_pop(s1));
    }
    for(i=0;i<n;i++){
        stack_push(s2,stack_pop(temp));
    }
    stack_destroy(temp);
}
