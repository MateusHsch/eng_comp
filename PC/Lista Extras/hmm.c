#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int faltam(char dia[],int n);
int main (){
    char dia[10];
    printf("Insira o dia: \n");
    fgets(dia,10,stdin);
    return 0;
}
int faltam(char dia[],int n){
    if(strcmp(dia,"segunda") == 0){
        n = 4;
    }
}