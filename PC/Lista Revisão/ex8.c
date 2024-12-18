#include <stdio.h>
//Escreva um programa que leia 3 números inteiros e mostre o menor deles e todos que são positivos. 
int main(){
    int n1,n2,n3,menor;
    printf("insira um numero inteiro: \n");
    scanf("%d",&n1);
    printf("insira outro numero inteiro: \n");
    scanf("%d",&n2);
    printf("insira mais um numero inteiro: \n");
    scanf("%d",&n3);
    if(n3>n2 && n3>n1){ //testa se n3 é o maior
        if(n2>n1){
            menor = n1;
        }else{
            menor = n2;
        }
    }else if(n2>n3 && n2>n1){ //testa se n2 é o maior
        if(n3>n1){
            menor = n1;
        }else{
            menor = n3;
        }
    }else{ //Caso n1 for o maior
        if(n3>n2){
            menor = n2;
        }else{
            menor = n3;
        }
    }
    if(n1>0){
       printf("%d e positivo.\n",n1); 
    }if(n2>0){
       printf("%d e positivo.\n",n2); 
    }if(n3>0){
       printf("%d e positivo.\n",n3); 
    }
    printf("O menor numero e %d.\n",menor);
}