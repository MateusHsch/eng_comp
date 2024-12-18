#include <stdio.h>
#include <stdlib.h>
int somatorio(int n);
int main (){
    int n, s;
    printf("Insira um inteiro n:\n");
    scanf("%d",&n);
    s = somatorio(n);
    printf("O somatorio de 1 a n: %d\n",s);
    return 0;
}
int somatorio(int n){
    if (n == 0){
        return 0;
    } else{
        return (n + somatorio(n-1));
    }
}