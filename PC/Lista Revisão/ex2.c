#include <stdio.h>
int main(){
    int n1 = 10;
    int n2 = 8;
    int n3 = 5;
    float med = (n1+n2+n3)/3;
    printf("A media e %.2f\n",med);
    if (med>=7){
        printf("Aprovado\n");
    }else {
        printf("Reprovado\n");
    }

}