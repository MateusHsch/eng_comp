#include <stdio.h>
#include <stdlib.h>
void verificar(int n);
int main (){
    int n;
    printf("Insira um numero:\n");
    scanf("%d",&n);
    verificar(n);
    return 0;
}
void verificar(int n){
    if (n%2 == 0){
        printf("O numero e par.\n");
    } else{  
        printf("O numero e impar.\n");
    }
}