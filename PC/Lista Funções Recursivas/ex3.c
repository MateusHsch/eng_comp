#include <stdio.h>
#include <stdlib.h>
int fib(int n);
int main (){
    int n,s;
    printf("Insira um inteiro n:\n");
    scanf("%d",&n);
    s = fib(n);
    printf("O N-esimo numero da sequencia de fibonacci: %d\n",s);
    return 0;
}
int fib(int n){
    if (n == 0){
        return 0;
    }else if (n == 1){
        return 1;
    }else {
        return(fib(n-1)+fib(n-2));
    }
}