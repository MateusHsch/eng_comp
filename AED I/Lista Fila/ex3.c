#include <stdio.h>
#include <stdlib.h>
#define N 10

// Fila dinâmica
struct fila{
    int n; /* número de elementos na fila */
    int ini; /*posição do próximo elem. a ser retiradoda fila*/
    float vet[N];
};
typedef struct fila Fila;Fila* fila_criar( void );
void fila_liberar( Fila* f );
int fila_vazia( Fila* f );
void fila_print( Fila* f );
void fila_adicionar( Fila* f, float v );
float fila_retirar( Fila* f );
Fila* fila_invert( Fila* f );

// Fila estática
void enfileirar( int vet[], int valor );
int remover( int vet[] );
int buscar( int vet[], int valor );
void imprimir( int vet[] );
int vazia( int vet[] );
void inverter( int vet[] );

// Pilha
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
Stack* stack_invert(Stack* s);

int main(){
    /*Stack *s = stack_create();
    stack_push(s, 2.3);
    stack_push(s, 5.4);
    stack_push(s, 8.2);
    stack_print(s);
    s = stack_invert(s);
    stack_print(s);
    stack_destroy(s);*/
    /*Fila *f = fila_criar();
    fila_adicionar(f,2.3);
    fila_adicionar(f,5.4);
    fila_adicionar(f,8.2);
    fila_print(f);
    f = fila_invert(f);
    fila_print(f);
    fila_liberar(f);*/
    int f[N] = {};
    enfileirar(f,2);
    enfileirar(f,5);
    enfileirar(f,8);
    imprimir(f);
    inverter(f);
    imprimir(f);

    return 0;
}

// Fila dinâmica
Fila* fila_criar( void ){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    f->ini = 0;
    return f;
}
void fila_liberar( Fila* f ){
    free(f);
}
int fila_vazia( Fila* f ){
    if(f->n == 0){
        return 1;
    }else{
        return 0;
    }
}
void fila_print( Fila* f ){
    int t = f->n;
    printf(" <--[");
    for(int i=f->ini; t>0; t--){
        printf(" %.2f",f->vet[i]);
        i = (i+1)%N;
    }
    printf(" ]<--\n\n");
}
void fila_adicionar( Fila* f, float v ){
    int fim;
    if(f->n == N){
        printf("Capacidade da fila estorou.\n");
    }else{
        /* insere elemento na próxima posição livre */
        fim = (f->ini + f->n) % N;
        f->vet[fim] = v;
        f->n++;
    }
}
float fila_retirar( Fila* f ){
    float v;
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        return 0;
    }else{
        /* retira elemento do início*/
        v = f->vet[f->ini];
        f->ini = (f->ini + 1)%N;
        f->n--;
        return v;
    }
}
Fila* fila_invert( Fila* f ){
    Fila* aux = fila_criar();
    if(fila_vazia(f)){
        printf("Fila vazia.\n\n");
    }else{
        while(f->n > 0){
            aux->vet[aux->n] = f->vet[(f->n)-1];
            aux->n++;
            f->n--;
        }
    }
    fila_liberar(f);
    return aux;
}

// Fila estática
void enfileirar( int vet[], int valor ){
    if(valor != 0){
        int i=0;
        while((vet[i] != 0)&&(i<N)){
            i++;
        }
        if(i == N){
            printf("fila cheia.\n\n");
        }else{
            vet[i] = valor;
        }
    }else{
        printf("valor deve ser diferente de 0.\n\n");
    }
}
int remover( int vet[] ){
    if(vazia(vet)){
        printf("Fila vazia.\n\n");
        return 0;
    }else{
        int valor = vet[0];
        for(int i=0; i<(N-1); i++){
            vet[i] = vet[i+1];
        }
        vet[N-1] = 0;
        return valor;
    }
}
int buscar( int vet[], int valor ){
    if(vazia(vet)){
        printf("Fila vazia.\n\n");
        return -1;
    }else{
        int i=0;
        while((vet[i] != valor)&&(i<N)){
            i++;
        }
        if(i != N){
            return i;
        }else{
            printf("Valor nao encontrado.\n\n");
            return -1;
        }
    }
}
void imprimir( int vet[] ){
    printf("<--[");
    for(int i=0; i<N; i++){
        if(vet[i] != 0){
            printf(" %d",vet[i]);
        }
    }
    printf(" ]<--\n\n");
}
int vazia( int vet[] ){
    if(vet[0] == 0){
        return 1;
    }else{
        return 0;
    }
}
void inverter( int vet[] ){
    if(vazia(vet)){
        printf("Fila vazia.\n\n");
    }else{
        int aux[N];
        int i;
        for(i=0; i<N; i++){
            aux[i] = vet[N-1-i];
        }
        for(i=0; i<N; i++){
            vet[i] = aux[i];
        }
    }
}

// Pilha
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
        printf(" %.2f",s->vet[i]);
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
Stack* stack_invert(Stack* s){
    Stack* aux = stack_create();
    if(stack_empty(s)){
        printf("Pilha vazia.\n\n");
    }else{
        while(s->n>0){
            aux->vet[aux->n] = s->vet[(s->n)-1];
            s->n--;
            aux->n++;
        }
    }
    stack_destroy(s);
    return(aux);
}
