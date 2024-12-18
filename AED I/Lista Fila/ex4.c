#include <stdio.h>
#include <stdlib.h>
#define N 50
struct fila{
    int n; /* número de elementos na fila */
    int ini; /*posição do próximo elem. a ser retiradoda fila*/
    float vet[N];
};
typedef struct fila Fila;

Fila* fila_criar( void );
void fila_liberar( Fila* f );
int fila_vazia( Fila* f );
void fila_print( Fila* f );
void fila_adicionar( Fila* f, float v );
float fila_retirar( Fila* f );
void fila_furar( Fila* f, float v );

int main(){
    Fila* f = fila_criar();
    fila_adicionar(f,2.3);
    fila_adicionar(f,5.2);
    fila_adicionar(f,1.2);
    fila_adicionar(f,9.0);
    fila_print(f);
    fila_furar(f,7.5);
    fila_print(f);
    float v = fila_retirar(f);
    printf("%.2f\n\n",v);
    fila_print(f);
    v = fila_retirar(f);
    printf("%.2f\n\n",v);
    fila_print(f);
    fila_liberar(f);
    return 0;
}
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
void fila_furar( Fila* f, float v ){
    if(f->n == N){
        printf("Capacidade da fila estorou.\n"); 
    }else{
        if(f->ini != 0){
            f->ini--;
            f->vet[f->ini] = v;
        }else{
            f->ini = N-1;
            f->vet[f->ini] = v;
        }
        f->n++;
    }
}
