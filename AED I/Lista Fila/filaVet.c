#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct fila{
    int n;
    int ini;
    float vet[N];
}Fila;

Fila* fila_criar( void );
void fila_destruir( Fila *f );
void fila_inserir( Fila *f,float valor );
float fila_remover( Fila *f );
int fila_vazia( Fila* f );
void fila_imprimir( Fila *f );

int main(){
    Fila *f = fila_criar();
    fila_inserir(f,3.2);
    fila_inserir(f,4.3);
    fila_inserir(f,5.5);
    fila_inserir(f,1.1);
    fila_imprimir(f);
    float valor = fila_remover(f);
    printf("valor removido: %.2f\n\n",valor);
    fila_imprimir(f);
    fila_destruir(f);
    return 0;
}
Fila* fila_criar( void ){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL){
        printf("Malloc devolveu NULL!!\n");
        exit(1);
    }
    f->n = 0;
    f->ini = 0;
    return f;
}
void fila_destruir( Fila *f ){
    free(f);
}
void fila_inserir( Fila *f,float valor ){
    int fim;
    if(f->n == N){
        printf("Capacidade da fila estorou.\n");
    }else{
        fim = (f->ini + f->n)%N;
        f->vet[fim] = valor;
        f->n++;
    }
}
float fila_remover( Fila *f ){
    float valor;
    if(fila_vazia(f)){
        printf("Nada a remover.\n");
        return 0;
    }else{
        valor = f->vet[f->ini];
        f->ini = (f->ini + 1)%N;
        f->n--;
        return valor;
    }
}
void fila_imprimir( Fila *f ){
    if(fila_vazia(f)){
        printf("Nada a imprimir.\n\n");
    }else{
        printf("<--[");
        int i,fim;
        fim = (f->n + f->ini)%N;
        for(i=f->ini; i<fim; i=(i+1)%N){
            printf(" %.2f",f->vet[i]);
        }
        printf(" ]<--\n\n");
    }
}

int fila_vazia( Fila* f ){
    if(f->n == 0){
        return 1;
    }else{
        return 0;
    }
}

