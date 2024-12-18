//vetor de números aleatórios com menu de maipulação
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherVet(int vet[],int n);
int menu(int vet[],int n);
void encontrar(int vet[],int n);
void produto(int vet[],int n);
void contar(int vet[],int n);
void testarOrdem(int vet[],int n);
void maiorMed(int vet[],int n);
void printVet(int vet[],int n);
int main(){
  srand(time(NULL));
  int sair=0;
  int vet[25];
  preencherVet(vet,25);
  do{
    sair = menu(vet,25);
  }while (sair != 1);
  return 0;
}
void preencherVet(int vet[],int n){
  int i;
  for(i=0;i<n;i++){
    vet[i] = rand()%100+1;
  }
}
int menu(int vet[],int n){
  int sair;
  char op;
  printf("Bem vindo ao editor de vetor v0.00001\n");
  printf("a - Encontar valor.\n");
  printf("b - Calcular o produto dos elementos do vetor\n");
  printf("c - Contar ocorrencias de um valor\n");
  printf("d - Verifica se o vetor esta em ordem crescente\n");
  printf("e - Mostre todos os numeros que são maiores que a media\n");
  printf("f - Imprime o vetor\n");
  printf("Qual opcao deseja: ");
  scanf("%c",&op);
  fflush(stdin);
  switch (op){
  case 'a':
    encontrar(vet,n);
    break;
  case 'b':
    produto(vet,n);
    break;
  case 'c':
    contar(vet,n);
    break;
  case 'd':
    testarOrdem(vet,n);
    break;
  case 'e':
    maiorMed(vet,n);
    break;
  case 'f':
    printVet(vet,n);
    break;
  default:
    printf("opcao invalida!!!\n");
    printf("saindo do programa!!!\n");
    sair = 1;
    break;
  }
  return sair;
}
void encontrar(int vet[],int n){
  int i,x;
  printf("Insira o valor que deseja encontrar: ");
  scanf("%d",&x);
  fflush(stdin);
  printf("O valor esta nas posicoes:\n");
  printf("\n");
  for(i=0;i<n;i++){
    if(vet[i] == x){
        printf("vet[%d]\n",i);
    }
  }
  printf("\n");
}
void produto(int vet[],int n){
  int i,produto=1;
  for(i=0;i<n;i++){
    produto = produto * vet[i];
  }
  printf("O produto dos elementos do vetor e: %d\n\n",produto);
}
void contar(int vet[],int n){
  int i,v,ocorrencias=0;
  printf("Insira o valor que deseja contar as ocorrencias: ");
  scanf("%d",&v);
  fflush(stdin);
  printf("\n");
  for(i=0;i<n;i++){
    if(v == vet[i]){
        ocorrencias++;
    }
  }
  printf("O valor aparece %d vezes\n\n",ocorrencias);
}
void testarOrdem(int vet[],int n){
  int i,j,aux,ordem=1;
  for(i=1;i<n;i++){
    if(vet[0] > vet[i]){
      ordem = 0;
    }
  }
  if(ordem == 0){
    printf("O vetor esta desordenado...\n");
    for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
        if(vet[i]>vet[j]){
          aux = vet[i];
          vet[i] = vet[j];
          vet[j] = aux;
        }
      }
    }
    printf("Vetor ordenado\n");
  }
  printf("\n");
}
void maiorMed(int vet[],int n){
  int i,soma=0;
  float media;
  for(i=0;i<n;i++){
    soma += vet[i];
  }
  media = (float) soma/n;
  printf("Os numeros maiores que a media sao:\n");
  printf("[");
  for(i=0;i<n;i++){
    if(vet[i]>media){
      printf(" %d",vet[i]);
    }
  }
  printf(" ]\n\n");
}
void printVet(int vet[],int n){
  int i;
  printf("[");
  for(i=0;i<n;i++){
    printf(" %d",vet[i]);
  }
  printf(" ]\n\n");
}