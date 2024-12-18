#include <stdio.h>
int main (){
    int i,j;
    char nome[10];
    printf("Insira algo:\n");
    scanf("%d",&i);
    fflush(stdin); // getchar(); também funciona
    fgets(nome,10,stdin);
    //scanf("%d",&j);
    return 0;
}