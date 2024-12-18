#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct fila{
    int n;
    int ini;
    int vet[N];
}Fila;

Fila* fila_criar( void );
void fila_liberar( Fila* f );
void fila_inserir( Fila* f, int v );
int fila_remover( Fila* f );
int fila_vazia( Fila* f );
void fila_imprimir( Fila* f );

void combina_fila( Fila *f_res, Fila *f1, Fila *f2);

int main(){
    Fila *f1 = fila_criar();
    fila_inserir(f1,1);
    fila_inserir(f1,2);
    fila_inserir(f1,3);
    fila_inserir(f1,4);
    fila_imprimir(f1);

    Fila *f2 = fila_criar();
    fila_inserir(f2,1);
    fila_inserir(f2,2);
    fila_inserir(f2,3);
    fila_inserir(f2,4);
    fila_inserir(f2,6);
    fila_inserir(f2,10);
    fila_imprimir(f2);

    Fila *f_res = fila_criar();
    fila_inserir(f_res,99);
    fila_inserir(f_res,1);
    fila_imprimir(f_res);

    combina_fila(f_res,f1,f2);
    fila_imprimir(f1);
    fila_imprimir(f2);
    fila_imprimir(f_res);

    fila_liberar(f1);
    fila_liberar(f2);
    fila_liberar(f_res);
    return 0;
}
Fila* fila_criar( void ){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = 0;
    f->n = 0;
    return f;
}
void fila_liberar( Fila* f ){
    free(f);
}
void fila_inserir( Fila* f, int v ){
    if(f->n == N){
        printf("Fila cheia.\n\n");
    }else{
        int fim = (f->ini + f->n)%N;
        f->vet[fim] = v;
        f->n++;
    }
}
int fila_remover( Fila* f ){
    if(fila_vazia(f)){
        printf("Nada a remover.\n\n");
        return 0;
    }else{
        int v = f->vet[f->ini];
        f->n--;
        f->ini = (f->ini + 1)%N;
        return v;
    }
}
int fila_vazia( Fila* f ){
    return (f->n == 0 ? 1 : 0);
}
void fila_imprimir( Fila* f ){
    int tam = f->n;
    printf(" <--[");
    for(int i = f->ini; tam>0; tam--){
        printf(" %d",f->vet[i]);
        i = (i+1)%N;
    }
    printf(" ]<--\n\n");
}

void combina_fila( Fila *f_res, Fila *f1, Fila *f2){
    while(!fila_vazia(f_res)){
        fila_remover(f_res);
    }
    int temp;
    while((!fila_vazia(f1))||(!fila_vazia(f2))){
        if(!fila_vazia(f1)){
            temp = fila_remover(f1);
            fila_inserir(f_res,temp);
        }
        if(!fila_vazia(f1)){
            fila_remover(f1);
        }
        if(!fila_vazia(f2)){
            fila_remover(f2);
        }
        if(!fila_vazia(f2)){
            temp = fila_remover(f2);
            fila_inserir(f_res,temp);
        }
    }
}
