#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printVet(int* v,int n);
void mergeSort(int* v,int com,int fim);
void merge(int* v,int com,int meio,int fim);
int main(){
    clock_t inicio,fim;
    double tempo_decorrido;
    int v[] = {42, 17, 89, 31, 76, 50, 7, 63, 93, 27, 12, 4, 58, 71, 65, 21, 84, 98, 2, 36, 6, 54, 29, 96, 79, 19, 85, 9, 60, 74, 13, 44, 91, 25, 3, 37, 55, 22, 81, 16, 48, 88, 69, 47, 38, 68, 72, 34, 95, 8, 66, 59, 14, 87, 45, 97, 26, 5, 64, 18, 30, 67, 23, 80, 41, 92, 33, 77, 11, 70, 52, 15, 40, 75, 53, 94, 61, 46, 86, 39, 73, 10, 56, 35, 1, 28, 83, 62, 20, 49, 24, 32, 90, 51, 82, 57, 99, 78, 43};
    int n = 100;
    printf("Array original:\n");
    printVet(v,n);
    inicio = clock();
    mergeSort(v,0,n-1);
    fim = clock();
    printf("Array ordenado:\n");
    printVet(v,n);
    tempo_decorrido =(double) (fim=inicio)/CLOCKS_PER_SEC;
    printf("tempo de ordenacao: %f\n",tempo_decorrido);
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
void mergeSort(int* v,int com,int fim){
    if (com < fim){
        int meio = (fim+com)/2;
        mergeSort(v,com,meio);
        mergeSort(v,meio+1,fim);
        merge(v,com,meio,fim);
    }
}
void merge(int* v,int com,int meio,int fim){
    int i,j,k;
    int n1 = meio-com+1;
    int n2 = fim-meio;
    int esq[n1],dir[n2];
    for(i=0;i<n1;i++){
        esq[i] = v[com+i];
    }
    for(j=0;j<n2;j++){
        dir[j] = v[meio+1+j];
    }
    i=0;
    j=0;
    k=com;
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            v[k] = esq[i];
            i++;
        } else {
            v[k] = dir[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = esq[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = dir[j];
        j++;
        k++;
    }
}
