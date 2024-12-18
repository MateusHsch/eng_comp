#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int menorN(int a,int b,int c);
int main (){
    int a,b,c,menor;
    printf("Insira os numeros.\n");
    printf("a:\n");
    scanf("%d",&a);
    printf("b:\n");
    scanf("%d",&b);
    printf("c:\n");
    scanf("%d",&c);
    menor = menorN(a,b,c);
    printf("menor: %d\n",menor);
    return 0;
}
int menorN(int a,int b,int c){
    int menor=0;
    if (a<b && a<c){
        menor = a;
    }else if (b<a && b<c){
        menor = b;
    }else {
        menor = c;
    }
    return menor;
}
