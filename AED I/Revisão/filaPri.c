#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define N 51

typedef struct filapri{
    int n;
    float vet[N];
}FilaPri;

FilaPri* fila_criar( void );
void fila_liberar( FilaPri *f );
void fila_inserir( FilaPri *f, float v );
void increase( FilaPri *f, int i, float v);
float fila_remover( FilaPri *f );
void rebuild( FilaPri *f );
float fila_espiar( FilaPri *f );
void fila_imprimir( FilaPri *f );

int main(){
    FilaPri *f = fila_criar();
    fila_inserir(f,5.5);
    fila_inserir(f,1.2);
    fila_inserir(f,7.8);
    fila_inserir(f,3.9);
    fila_inserir(f,3.199);
    fila_imprimir(f);
    printf("Valor removido: %.2f\n\n",fila_remover(f));
    fila_imprimir(f);
    fila_liberar(f);
    return 0;
}

FilaPri* fila_criar( void ){
    FilaPri *f = (FilaPri*) malloc(sizeof(FilaPri));
    f->n = 0;
    return f;
}
void fila_liberar( FilaPri *f ){
    free(f);
}
void fila_inserir( FilaPri *f, float v ){
    if(f->n == N){
        printf("Capacidade da fila Estorou.\n\n");
    }else{
        f->n++;
        f->vet[f->n] = -FLT_MAX;
        increase(f,f->n,v);
    }
}
void increase( FilaPri *f, int i, float v){
    while((i > 1)&&(v >= f->vet[i/2])){
        f->vet[i] = f->vet[i/2];
        i /= 2;
    }
    f->vet[i] = v;
}
float fila_remover( FilaPri *f ){
    if(f->n == 0){
        printf("Fila vazia.\n\n");
        return 0.0;
    }else{
        float v = f->vet[1];
        f->vet[1] = f->vet[f->n];
        f->n--;
        rebuild(f);
        return v;
    }
}
void rebuild( FilaPri *f ){
    int esq = 1,j = esq*2;
    float v = f->vet[esq];
    while(j <= f->n){
        if((j < f->n)&&(f->vet[j] < f->vet[j+1])){
            j++;
        }
        if(v >= f->vet[j]){
            break;
        }
        f->vet[esq] = f->vet[j];
        esq = j;
        j *= 2;
    }
    f->vet[esq] = v;
}
float fila_espiar( FilaPri *f ){
    if(f->n == 0){
        printf("Fila vazia.\n\n");
        return 0.0;
    }else{
        return f->vet[1];
    }
}
void fila_imprimir( FilaPri *f ){
    printf(" <--[");
    for(int i=1; i<(f->n+1); i++){
        printf(" %.2f",f->vet[i]);
    }
    printf(" ]<--\n\n");
}
