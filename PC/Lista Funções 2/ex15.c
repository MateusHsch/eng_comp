#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printVet(int vet[],int n);
void preencherVet(int vet[],int n);
void procura(int x,int vet[],int n);
void multiplica(int x,int vet[],int n);
void conta(int x,int vet[],int n);
void emOrdem(int vet[],int n);
int main(){
    srand(time(NULL));
    int vet[25];
    int x;
    preencherVet(vet,25);
    printf("Insira o x que deseja encontrar:\n");
    scanf("%d",&x);
    procura(x,vet,25);
    printf("Insira o x que deseja multiplicar pelo vetor:\n");
    scanf("%d",&x);
    multiplica(x,vet,25);
    printf("Insira o x que deseja contar as ocorrencias:\n");
    scanf("%d",&x);
    conta(x,vet,25);
    emOrdem(vet,25);
    return 0;
}
void printVet(int vet[],int n){
    int i;
    printf("[");
    for (i=0;i<n-1;i++){
        printf("%d ",vet[i]);
    }
    printf("%d]\n",vet[n-1]);
}
void preencherVet(int vet[],int n){
    int i;
    for (i=0;i<n;i++){
        vet[i] = rand()%100 +1;
    }
    printVet(vet,n);
}
void procura(int x,int vet[],int n){
    int i,pos=-1;
    for (i=0;i<n;i++){
        if (vet[i] == x){
            pos = i;
        }
    }
    if(pos != -1){
        printf("O x esta na posicao %d do vetor.\n",pos);
    }else {
        printf("O x nao esta no vetor.\n");
    }
}
void multiplica(int x,int vet[],int n){
    int tvet[n];
    int i;
    for (i=0;i<n;i++){
        tvet[i] = x*vet[i];
    }
    printVet(tvet,n);
}
void conta(int x,int vet[],int n){
    int i,cont=0;
    for (i=0;i<n;i++){
        if (vet[i] == x){
            cont++;
        }
    }
    printf("O x aparece %d vezes no vetor.\n",cont);
}
void emOrdem(int vet[],int n){
    int i,j,bool=1;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (vet[i]>vet[j]){
                bool = 0;
            }
        }
    }
    if (bool == 1){
        printf("Vetor ordenado.\n");
    }else {
        printf("Vetor nao ordenado.\n");
    }
}