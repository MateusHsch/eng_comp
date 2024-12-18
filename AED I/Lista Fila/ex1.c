#include <stdio.h>
#include <stdlib.h>
#define N 5

void enfileirar( int vet[], int valor );
int remover( int vet[] );
int buscar( int vet[], int valor );
void imprimir( int vet[] );
int vazia( int vet[] );

int main(){
    int vet[N] = {};
    enfileirar(vet,5);
    enfileirar(vet,7);
    enfileirar(vet,10);
    enfileirar(vet,4);
    enfileirar(vet,1);
    imprimir(vet);
    printf("valor removido: %d\n\n",remover(vet));
    enfileirar(vet,2);
    imprimir(vet);
    int valor;
    printf("Insira o valor que deseja encontar.\n\n");
    scanf("%d",&valor);
    printf("idx do valor: %d\n\n",buscar(vet,valor));
    return 0;
}
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
    printf(" %d",vet[i]);
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