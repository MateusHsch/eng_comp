#include <stdio.h>
#include <stdlib.h>
#include "fat.h"
int main (){
    system("chcp 65001 > NUL");
    int n,s;
    printf("De qual número deseja calcular o fatorial.\n");
    scanf("%d",&n);
    s = fat(n);
    printf("O fatorial de %d é: %d\n",n,s);
    return 0;
}