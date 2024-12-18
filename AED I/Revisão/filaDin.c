#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct proc{
    int id;
    char name[20];
    int pri;
    int wait;
}Proc;
typedef struct no{
    Proc info;
    struct no *prox;
}No;
typedef struct fila{
    int n;
    No *cab;
}Fila;

Fila* criar_fila( void );
void liberar_fila( Fila* f );
void inserir_fila( Fila* f, Proc info);
void imprimir_lista( Fila *f );

int main(){
    Fila *f = criar_fila();
    printf("%p \n",f->cab);
    Proc p1;
    p1.id = 1;
    strcpy(p1.name,"Chrome");
    p1.pri = 20;
    p1.wait = 5;
    inserir_fila(f,p1);
    printf("%p \n",f->cab);
    
    Proc p2;
    p2.id = 2;
    strcpy(p2.name,"Explorer");
    p2.pri = 50;
    p2.wait = 2;
    inserir_fila(f,p2);

    Proc p3;
    p3.id = 3;
    strcpy(p3.name,"Java");
    p3.pri = 10;
    p3.wait = 4;
    inserir_fila(f,p3);
    printf("oi\n");

    imprimir_lista(f);
    printf("oi\n");

    liberar_fila(f);
    return 0;
}
Fila* criar_fila( void ){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL){
        printf("Malloc devolveu NULL.\n\n");
        exit(1);
    }
    alocacoes++;
    f->n = 0;
    f->cab = NULL;
    return f;
}
void liberar_fila( Fila* f ){
    No *t = f->cab, *aux;
    while(t != NULL){
        aux = t;
        t = t->prox;
        free(aux);
        desalocacoes++;
    }
    free(f);
    desalocacoes++;
}
void inserir_fila( Fila* f, Proc info){
    No *t = f->cab;
    while((t != NULL)&&(t->info.id != info.id)){
        t = t->prox;
    }
    if(t == NULL){
        t = (No*) malloc(sizeof(No));
        if(t == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        t->info.id = info.id;
        strcpy(t->info.name,info.name);
        t->info.pri = info.pri;
        t->info.wait = info.wait;
    }else{
        printf("Processo ja existe.\n\n");
    }
}
void imprimir_lista( Fila *f ){
    No *t = f->cab;
    while(t != NULL){
        printf("id = %d\n",t->info.id);
        printf("name = %s\n",t->info.name);
        printf("pri = %d\n",t->info.pri);
        printf("wait = %d\n\n",t->info.wait);
    }
}
