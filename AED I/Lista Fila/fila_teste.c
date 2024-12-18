#include <stdio.h>
#include <stdlib.h>
typedef struct fila{
    float valor;
    struct fila* proximo;
    struct fila* anterior;
}Fila;

Fila* fila_criar( void );
void fila_liberar( Fila* f );
Fila* fila_adiciona( Fila* f, float v );
Fila* fila_remove( Fila* f, float* v );
void fila_printf( Fila* f );

int main(){
    float v;
    Fila* f = fila_criar();
    fila_printf(f);
    f = fila_adiciona(f,2.0);
    f = fila_adiciona(f,4.3);
    f = fila_adiciona(f,8.5);
    f = fila_adiciona(f,1.1);
    fila_printf(f);
    f = fila_remove(f,&v);
    printf("v: %.2f\n",v);
    fila_printf(f);
    fila_liberar(f);
    return 0;
}
Fila* fila_criar(){
    Fila* f = NULL;
    return f;
}
void fila_liberar( Fila* f ){
    if (f != NULL){
        Fila *anterior, *atual = f;
        while(atual->proximo != NULL){
            anterior = atual;
            atual = atual->proximo;
            free(anterior);
            printf("No desalocado.\n");
        }
        free(atual);
        printf("No desalocado.\n");
    }
}
Fila* fila_adiciona( Fila* f, float v ){
    Fila* novo = (Fila*) malloc(sizeof(Fila));
    printf("No alocado.\n");
    if (novo == NULL){
        printf("Malloc devolveu NULL.\n");
        exit(1);
    }
    novo->valor = v;
    novo->anterior = NULL;
    novo->proximo = NULL;
    if(f == NULL){
        return novo;
    }else{
        Fila* atual = f;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->anterior = atual;
        return f;
    }
}
Fila* fila_remove( Fila* f, float* v ){
    if(f == NULL){
        printf("fila vazia.\n");
        return f;
    }else{ 
        Fila* atual = f;
        *v = atual->valor;
        f = atual->proximo;
        if(f != NULL){
            f->anterior = NULL;
        }
        free(atual);
        printf("No desalocado.\n");
        return f;
    }
}
void fila_printf( Fila* f ){
    printf(" <--[");
    if(f != NULL){
        Fila* atual = f;
        while(atual->proximo != NULL){
            printf(" %.2f",atual->valor);
            atual = atual->proximo;
        }
        printf(" %.2f",atual->valor);
    }
    printf(" ]<--\n\n");
}
