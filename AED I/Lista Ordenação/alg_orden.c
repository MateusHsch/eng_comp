#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* genVet(int n);
void destVet(int* v);
void printVet(int* v,int n);
void bubbleSort(int* v,int n);
void insertionSort(int* v,int n);
void selectionSort(int* v ,int n);
void reverseBubble(int* v, int n);
void reverseInsertion(int* v,int n);
void reverseSelection(int* v,int n);
int main(){
    srand(time(NULL));
    int n;
    printf("Tamaho do vetor: "); 
    scanf("%d",&n);
    int* v = genVet(n);
    printVet(v,n);

    //bubbleSort(v,n);
    //insertionSort(v,n);
    selectionSort(v,n);
    printVet(v,n);
    //reverseBubble(v,n);
    //reverseInsertion(v,n);
    reverseSelection(v,n);
    printVet(v,n);

    destVet(v);
    return 0;
}
int* genVet(int n){
    int i;
    int* v = (int*) malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        v[i] = rand()%100+1;
    }
    return v;
}
void destVet(int* v){
    free(v);
}
void printVet(int* v,int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        printf(" %d",v[i]);
    }
    printf(" ]\n\n");
}
void bubbleSort(int* v,int n){
    int i,continua,aux;
    do{
        continua = 0;
        for(i=0;i<n-1;i++){
            if(v[i] > v[i+1]){
                aux = v[i+1];
                v[i+1] = v[i];
                v[i] = aux;
                continua = i;
            }
        }
        n--;
    }while (continua != 0);
}
void insertionSort(int* v,int n){
    int i,j,atual;
    for(i=1;i<n;i++){
        atual = v[i];
        for(j=i;(j>0) && (atual<v[j-1]);j--){
            v[j] = v[j-1];
        }
        v[j] = atual;
    }
}
void selectionSort(int* v ,int n){
    int i,j,aux,menor;
    for(i=0;i<n-1;i++){
        menor = i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}
void reverseBubble(int* v, int n){
    int i,aux,continua;
    do{
        continua = 0;
        for (i=0;i<n-1;i++){
            if(v[i]<v[i+1]){
                aux = v[i+1];
                v[i+1] = v[i];
                v[i] = aux;
                continua = i;
            }
        }
        n--;
    }while (continua != 0);
}
void reverseInsertion(int* v,int n){
    int i,j,atual;
    for(i=1;i<n;i++){
        atual = v[i];
        for(j=i;(j>0) && (atual>v[j-1]);j--){
            v[j] = v[j-1];
        }
        v[j] = atual;
    }
}
void reverseSelection(int* v,int n){
    int i,j,aux,maior;
    for(i=0;i<n-1;i++){
        maior = i;
        for(j=i+1;j<n;j++){
            if(v[maior] < v[j]){
                maior = j;
            }
        }
        if(maior != i){
            aux = v[i];
            v[i] = v[maior];
            v[maior] = aux;
        }
    }
}