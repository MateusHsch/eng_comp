#include <stdio.h>
#include <stdlib.h>
void printVet(int* v,int n);
int changesInsertion(int* v,int n);
int changesSelection(int* v,int n); 
int main(){
    int n=50,trocas;
    int v[50] = {874, 532, 187, 906, 345, 743, 988, 263, 612, 410, 789, 218, 601, 237, 819, 582, 751, 904, 361, 522, 946, 124, 648, 379, 295, 667, 572, 955, 178, 853, 669, 321, 592, 763, 235, 417, 821, 496, 143, 509, 709, 841, 682, 760, 632, 941, 788, 123, 470, 574};
    printVet(v,n);
    trocas = changesInsertion(v,n);
    printVet(v,n);
    printf("trocas: %d\n",trocas);

    return 0;
}
void printVet(int* v,int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        printf(" %d",v[i]);
    }
    printf(" ]\n\n");
}
int changesInsertion(int* v,int n){
    int i,j,atual,trocas=0;
    for(i=1;i<n;i++){
        atual = v[i];
        trocas++;
        for(j=i; (j>0) && (atual<v[j-1]); j--){
            v[j] = v[j-1];
            trocas++;
        }
        v[j] = atual;
        trocas++;
    }
    return trocas;
}
int changesSelection(int* v,int n){
    int i,j,aux,menor,trocas=0;
    for(i=0;i<n-1;i++){
        menor = i;
        for(j=i+1;j<n;j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(menor != i){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            trocas+=3;
        }
    }
    return trocas;
}
