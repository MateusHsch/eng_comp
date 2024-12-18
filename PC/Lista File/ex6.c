#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    char lista[4][50];
    char str[10];
    int i=0,j,ok=0,idx=0;
    float somamin=0.0,somat=0.0;
    FILE *fr = fopen("ci.txt","r");
    if (fr == NULL){
        perror("ci.txt");
        return 1;
    }
    while (fscanf(fr,"s",&lista[i]) != EOF){
        i++;
    }
    fclose(fr);
    FILE *fw = fopen("totais.txt","w");
    if (fw == NULL){
        perror("totais.txt");
        return 1;
    }
    for (i=0;i<4;i++){
        j=0;
        while (lista[i][j] != ' '){
            str[j] = lista[i][j];
            j++;
        }
        fprintf(fw,"%s ",str);
        j++;
        while (lista[i][j] != ' '){
            str[j] = lista[i][j];
            j++;
        }

        
    }

    fclose(fw);
    return 0;
}

