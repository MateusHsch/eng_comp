#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergeSort(int vet[],int comeco,int fim);
void merge(int vet[], int comeco, int meio, int fim);
int main(){
    srand(time(NULL));
    FILE *fr = fopen("numbers.txt","r");
    if (fr == NULL){
        perror("numbers.txt");
        return 1;
    }
    int i=0,n,vet[100];
    while(fscanf(fr,"%d ",&n) != EOF){
        vet[i] = n;
        i++;
    }

    fclose(fr);
    return 0;
}
void mergeSort(int vet[],int comeco,int fim){
    if (comeco<fim){
        int meio = (fim+comeco)/2;
        mergeSort(vet,comeco,meio);
        mergeSort(vet,meio+1,fim);
        merge(vet,comeco,meio,fim);
    }
}
void merge(int vet[], int comeco, int meio, int fim){

}