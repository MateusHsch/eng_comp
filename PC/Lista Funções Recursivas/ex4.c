#include <stdio.h>
#include <stdlib.h>
int potencia(int k, int n);
int main() {
    int k,n,s;
    printf("Insira a base k:\n");
    scanf("%d",&k);
    printf("Insira a potencia n:\n");
    scanf("%d",&n);
    s = potencia(k,n);
    printf("k elevado na potencia n: %d\n",s);
    return 0;
}
int potencia(int k, int n){
    if (n == 0){
        return 1;
    }else {
        return(k * potencia(k,n-1));
    }
}