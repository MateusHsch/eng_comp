#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main() {
    int d1,d2,d3;
    printf("Insira a data de nacimento.\n");
    scanf("%d",&d1);
    scanf("%d",&d2);
    scanf("%d",&d3);
    fflush(stdin);
    printf("Data: %d/%d/%d",d1,d2,d3);
}