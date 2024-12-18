#include <stdio.h>
#include <stdlib.h>
void imprimir(int a,int b);
int main(){
    int a,b;
    printf("Insira a:\n");
    scanf("%d",&a);
    printf("Insira b:\n");
    scanf("%d",&b);
    imprimir(a,b);
    return 0;
}
void imprimir(int a,int b){
    int dif;
    dif = abs(a-b);
    printf("Diferenca de a e b: %d\n",dif);
}