#include <stdio.h>
// Uma cidade classifica um índice de poluição menor que 35 como agradável; de 35 até 60
//desagradável e acima de 60 perigoso. Escreva um programa que leia um número real representando o
//índice de poluição e imprime a classificação adequada para ele.
int main(){
    double indice;
    printf("Insira o indice de poluicao:\n");
    scanf("%lf",&indice);
    if(indice<35){
        printf("Ese indice e agradavel");
    }else if(indice>=35 && indice<=60){
        printf("Ese indice e desagradavel");
    }else if(indice>60){
        printf("Ese indice e perigoso");
    }
}