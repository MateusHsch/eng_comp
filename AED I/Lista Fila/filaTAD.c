#include <stdio.h>
#include <stdlib.h>
typedef struct fila{
    int valor;
    struct fila* proximo;
}Fila;

Fila* fila_criar( void );
Fila* fila_menu( Fila* f,int *exit );
Fila* fila_inserir( Fila *f,int valor );
Fila* fila_remover( Fila *f,int *valor );
void fila_destruir( Fila *f );
int fila_vazia( Fila* f );
void fila_imprimir( Fila *f );

int main(){
    Fila *f = fila_criar();
    int exit=0;
    do{
        f = fila_menu(f,&exit);
    }while(exit != 1);
    fila_destruir(f);
    return 0;
}
Fila* fila_menu( Fila* f,int *exit ){
    int op=0,valor=0;
    system("cls");
    printf("x--------------------------x\n");
    printf("1 => Insere um elemento.\n");
    printf("2 => Remove um elemento.\n");
    printf("3 => Iprime a fila.\n");
    printf("4 => Sair.\n");
    printf("x--------------------------x\n");
    printf("Insira a opcao desejada: ");
    scanf("%d",&op);
    getchar();
    system("cls");
    switch (op){
        case 1:
            printf("Insira o valor que deseja inserir: ");
            scanf("%d",&valor);
            getchar();
            printf("\n");
            f = fila_inserir(f,valor);
            break;
        case 2:
            f = fila_remover(f,&valor);
            printf("O valor removido e: %d\n",valor);
            getchar();
            break;
        case 3:
            fila_imprimir(f);
            getchar();
            break;
        default:
            printf("Saindo do programa.\n");
            *exit = 1;
            break;
    }
    return f;
}
Fila* fila_criar( void ){
    Fila* f = NULL;
    return f;
}
Fila* fila_inserir( Fila *f,int valor ){
    Fila *novo = (Fila*) malloc(sizeof(Fila));
    novo->valor = valor;
    novo->proximo = NULL;
    if (f != NULL){
        Fila *atual = f;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
        return f;
    }else{
        return novo;
    }
}
Fila* fila_remover( Fila *f,int *valor ){
    if (f != NULL){
        Fila *atual = f;
        *valor = f->valor;
        f = f->proximo;
        free(atual);
        return f;
    }else{
        printf("Nada mais na fila.\n");
        *valor = 0;
        return f;
    }
}
void fila_destruir( Fila *f ){
    if(f != NULL){
        Fila *anterior,*atual = f;
        while(atual->proximo != NULL){
            anterior = atual;
            atual = atual->proximo;
            free(anterior);
        }
        free(atual);
    }
}
int fila_vazia( Fila* f ){
    if(f != NULL){
        return 1;
    }else{
        return 0;
    }
}
void fila_imprimir( Fila *f ){
    if(f != NULL){
        Fila *atual = f;
        while(atual->proximo != NULL){
            printf("%d\n",atual->valor);
            atual = atual->proximo;
        }
        printf("%d\n",atual->valor);
    }else{
        printf("Nada para imprimir.\n");
    }
}
