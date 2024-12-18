#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#define N 51
typedef struct info{
    int id; /* Id do elemento */
    char nome[50]; /* Nome do elemento */
    float prioridade; /* Prioridade do elemento */
    int espera; /* Tempo de espera do elemento */
}Info;
typedef struct fila{
    int n; /* Número de elementos na fila */
    Info vet[N]; /* Informações do elemento */
}Fila;

Fila* fila_criar( void );
void fila_liberar( Fila *f );
int fila_vazia( Fila *f );
void fila_inserir( Fila *f, Info p );
void increase( Fila *f, int n, Info p );
Info fila_remover( Fila *f );
void rebuild( Fila *f );
void fila_imprimir( Fila *f );

int main(){
    Fila *f = fila_criar();
    Info p;
    p.espera = 10;
    p.id = 1;
    strcpy(p.nome,"explorer");
    p.prioridade = 30;
    printf("oi\n");
    fila_inserir(f,p);
    printf("oi\n");
    p.espera = 40;
    p.id = 2;
    strcpy(p.nome,"java");
    p.prioridade = 50;
    fila_inserir(f,p);
    p.espera = 20;
    p.id = 3;
    strcpy(p.nome,"chrome");
    p.prioridade = 10;
    fila_inserir(f,p);
    fila_imprimir(f);
    p = fila_remover(f);
    printf("tarefa removida = %d.\n\n",p.id);
    fila_imprimir(f);
    fila_liberar(f);
    return 0;
}
Fila* fila_criar( void ){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    return f;
}
void fila_liberar( Fila *f ){
    free(f);
}
void fila_inserir( Fila *f, Info p ){
    if(f->n == N){
        printf("Fila esta cheia.\n\n");
    }else{
        f->n++;
        f->vet[f->n].prioridade = -FLT_MAX;
        increase(f,f->n,p);
    }
}
void increase( Fila *f, int n, Info p ){
    while((n > 1)&&(p.prioridade >= f->vet[n/2].prioridade)){
        f->vet[n] = f->vet[n/2];
        n /= 2;
    }
    f->vet[n].espera = p.espera;
    f->vet[n].id = p.id;
    strcpy(f->vet[n].nome,p.nome);
    f->vet[n].prioridade = p.prioridade;
}
Info fila_remover( Fila *f ){
    Info p;
    if(fila_vazia(f)){
        printf("Fila vazia.\n\n");
        p.espera = 0;
        p.id = 0; 
        strcpy(p.nome," ");
        p.prioridade = 0;
        return p;
    }else{
        p.espera = f->vet[1].espera;
        p.id = f->vet[1].id; 
        strcpy(p.nome,f->vet[1].nome);
        p.prioridade = f->vet[1].prioridade; 
        f->vet[1] = f->vet[f->n--];
        rebuild(f);
        return p;
    }
}
void rebuild( Fila *f ){
    int esq = 1;
    int j = esq*2;
    Info p = f->vet[esq];
    while(j <= f->n){
        if((j < f->n)&&(f->vet[j].prioridade < f->vet[j+1].prioridade)){
            j++;
        }
        if(p.prioridade >= f->vet[j].prioridade){
            break;
        }
        f->vet[esq] = f->vet[j];
        esq = j;
        j = esq*2;
    }
    f->vet[esq] = p;
}
void fila_imprimir( Fila *f ){
    if(fila_vazia(f)){
        printf("Nada a imprimir.\n\n");
    }else{
        printf("<--[");
        for(int i=1; i<=f->n; i++){
            printf(" %d",f->vet[i].id);
        }
        printf(" ]<--\n\n");
    }
}
int fila_vazia( Fila* f ){
    if(f->n < 1){
        return 1;
    }else{
        return 0;
    }
}