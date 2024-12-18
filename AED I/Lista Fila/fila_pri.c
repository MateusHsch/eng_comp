#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define N 101
typedef struct fila{
    int n;
    float vet[N];
}Fila;


Fila* fila_criar( void );
void fila_destruir( Fila *f );
void fila_inserir( Fila *f,float valor );
void fila_increase( Fila *f, int n, float valor );
float fila_remover( Fila *f );
void fila_rebuild( Fila *f );
float fila_peek( Fila *f );
int fila_vazia( Fila *f );
void fila_imprimir( Fila *f );

int main(){
    Fila *f = fila_criar();
    fila_inserir(f,3.2);
    fila_inserir(f,4.3);
    fila_inserir(f,5.5);
    fila_inserir(f,1.1);
    fila_imprimir(f);
    printf("valor espiado: %.2f\n\n",fila_peek(f));
    float valor = fila_remover(f);
    printf("valor removido: %.2f\n\n",valor);
    fila_imprimir(f);
    fila_destruir(f);
    return 0;
}
Fila* fila_criar( void ){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    return f;
}
void fila_destruir( Fila* f ){
    free(f);
}
void fila_inserir( Fila *f,float valor ){
    if (f->n == N){
        printf("Capacidade da fila estourou.\n\n");
    }else{
        f->n++;
        f->vet[f->n] = -FLT_MAX;
        fila_increase(f,f->n,valor);
    }
}
void fila_increase( Fila *f, int n, float valor ){
    while((n > 1)&&(valor >= f->vet[n/2])){
        f->vet[n] = f->vet[n/2];
        n/=2;
    }
    f->vet[n] = valor;
}
float fila_remover( Fila *f ){
    if(fila_vazia(f)){
        printf("Fila esta vazia.\n\n");
        return 0;
    }else{
        int valor = f->vet[1];
        f->vet[1] = f->vet[f->n--];
        fila_rebuild(f);
        return valor;
    }
}
void fila_rebuild( Fila *f ){
    int esq=1;
    int j=esq*2;
    float valor = f->vet[esq];
    while(j <= f->n){
        if((j < f->n)&&(f->vet[j] < f->vet[j+1])){
            j++;
        }
        if(valor >= f->vet[j]){
            break;
        }
        f->vet[esq] = f->vet[j];
        esq=j;
        j=esq*2;
    }
    f->vet[esq] = valor;
}
float fila_peek( Fila *f ){
    if(fila_vazia(f)){
        printf("Fila esta vazia.\n");
        return 0;
    }else{
        return f->vet[1];
    }
}
int fila_vazia( Fila* f ){
    if(f->n < 1){
        return 1;
    }else{
        return 0;
    }
}
void fila_imprimir( Fila *f ){
    if(fila_vazia(f)){
        printf("Nada a imprimir.\n\n");
    }else{
        printf("<--[");
        for(int i=1; i<=f->n; i++){
            printf(" %.2f",f->vet[i]);
        }
        printf(" ]<--\n\n");
    }
}

