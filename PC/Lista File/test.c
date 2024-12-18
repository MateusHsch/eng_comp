#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    FILE *fr = fopen("teste.txt","r");
    if (fr == NULL){
        perror("teste.txt");
        return 1;
    }
    int i,j,n,id,pos;
    float vet[10];
    char pessoa[30];
    char temp[4];
    float mat[2][3];
    while (fscanf(fr,"%s",&pessoa) != EOF){
        for (i=0;i<4;i++){
            temp[i] = pessoa[i];
        }
        id = atoi(temp);
        n = atoi(pessoa[5]);
        for (j=0;j<n;j++){
            i= n*2 + (j+1);
            while (pessoa[i]!= ' '){
                temp[i-(n*2 + (j+1))] = pessoa[i];
                i++;
            }
            vet[i-(n*2 + (j+1))] = atof(temp);
        }
    }
    return 0;
}