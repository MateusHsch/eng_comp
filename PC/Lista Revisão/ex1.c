#include <stdio.h>
int main(){
    int n1;
    int n2;
    int dif;
    printf("Digite o primeiro numero:\n");
    scanf("%d",&n1);
    printf("Digite o segundo numero:\n");
    scanf("%d",&n2);
    if(n1 > n2){
        dif = n1 - n2;
        printf("a diferenca entre os numeros e %d\n",dif);
    }else {
        dif = n2 - n1;
        printf("a diferenca entre os numeros e %d\n",dif);
    }
return 0;
}
