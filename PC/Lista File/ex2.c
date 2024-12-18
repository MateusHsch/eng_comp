#include <stdio.h>
#include <stdlib.h>
void lerFile(float notas[]);
void gerarAprov(float notas[],int n);
void gerarReprov(float notas[],int n);
int main (){
    float notas[9];
    lerFile(notas);
    gerarAprov(notas,9);
    gerarReprov(notas,9);
    return 0;
}
void lerFile(float notas[]){
    float n1,n2,n3;
    FILE *fr = fopen("ex2.txt","r");
    int i=0;
    if (fr == NULL){
        perror("ex2.txt");
    }
    while (fscanf(fr,"%f %f %f",&n1,&n2,&n3) != EOF){
        notas[i] = n1;
        notas[i+1] = n2;
        notas[i+2] = n3;
        i+=3;
    }
    fclose(fr);
}
void gerarAprov(float notas[],int n){
    int i;
    FILE *fapr = fopen("aprovados.txt","w");
    if (fapr == NULL){
        perror("aprovados.txt");
    }
    for (i=0;i<n;i++){
        if (notas[i] >= 5){
            fprintf(fapr,"%.2f ",notas[i]);
        }
    }
    fclose(fapr);
}
void gerarReprov(float notas[],int n){
    int i;
    FILE *frepr = fopen("reprovados.txt","w");
    if (frepr == NULL){
        perror("reprovados.txt");
    }
    for (i=0;i<n;i++){
        if (notas[i] < 5){
            fprintf(frepr,"%.2f ",notas[i]);
        }
    }
    fclose(frepr);
}