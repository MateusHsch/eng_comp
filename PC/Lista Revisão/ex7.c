#include <stdio.h>
//Elabore um programa que leia dois valores inteiros e escreva estes valores com uma das seguintes
//mensagens: “X é múltiplo de Y” ou “X não é múltiplo de Y”.
int main(){
    int x,y,resto;
    printf("Valor de X:\n");
    scanf("%d",&x);
    printf("Valor de Y:\n");
    scanf("%d",&y);
    resto = x % y;
    if (resto == 0){
        printf("%d e multiplo de %d",x,y);
    }else {
        printf("%d nao e multiplo de %d",x,y);
    }
}