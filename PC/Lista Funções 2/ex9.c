#include <stdio.h>
#include <stdlib.h>
float somat(int n);
int fat(int n);
int main (){
    int n;
    float s;
    printf("S = 1 + 1/(1!) + 1/(2!) + 1/(3!) + 1 /(N!)\n");
    printf("Insira o inteiro positivo N:\n");
    scanf("%d",&n);
    s = somat(n);
    printf("S: %.4f",s);
    return 0;
}
float somat(int n){
    int i;
    float s = 1.0;
    for (i=1;i<=n;i++){
        s+= (float) 1/fat(i);
    }
    return (s);
}
int fat(int n){
    if (n == 1){
        return 1;
    }else {
        return n*fat(n-1);
    }
}