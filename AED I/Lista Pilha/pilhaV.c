#include <stdio.h>
#include <stdlib.h>
#define N 50
struct stack{
    int n;
    float vet[N];
};
typedef struct stack Stack;

Stack* stack_create();
void stack_destroy(Stack* s);
void stack_push(Stack* s, float v);
float stack_pop(Stack* s);
int stack_empty(Stack* s);
void stack_print(Stack* s);
void stack_transfeer(Stack* s1, Stack* s2);
void concatena_pilhas (Stack* p1, Stack* p2);

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
    s->n = 0;
    return s;
}
void stack_destroy(Stack* s){
    free(s);
}
void stack_push(Stack* s, float v){
    if(s->n == N){
        printf("Capacidade da pilha esgotada.\n");
    }else{  
        s->vet[s->n] = v;
        s->n++;
    }
}
float stack_pop(Stack* s){
    if(stack_empty(s)){
        printf("Pilha vazia.\n");
        exit(1);
    }else{
        float v = s->vet[s->n-1];
        s->n--;
        return v;
    }
}
int stack_empty(Stack* s){
    if(s->n == 0){
        return 1;
    }else{
        return 0;
    }
}
void stack_print(Stack* s){
    int i;
    printf("Pilha:\n[");
    for(i=0;i<s->n;i++){
        printf(" %.2f;",s->vet[i]);
    }
    printf(" ] <-- \n\n");
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
void concatena_pilhas (Stack* p1, Stack* p2){
    Stack* temp = stack_create();
    int i,n = p2->n;
    for(i=0;i<n;i++){
        stack_push(temp,stack_pop(p2));
    }
    for(i=0;i<n;i++){
        stack_push(p1,stack_pop(temp));
    }
    stack_destroy(temp);
}

