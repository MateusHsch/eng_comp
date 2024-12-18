#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Carro{
    char modelo[10];
    float consumo;
    float lkm;
} Carro;
int main (){
    Carro carros[5];
    int i,mi;
    float me=0;
    for (i=0;i<5;i++){
        printf("Insira o modelo do carro %d:\n",i+1);
        gets(carros[i].modelo);
        printf("Insira o consumo do carro %d:\n",i+1);
        scanf("%f",&carros[i].consumo);
        fflush(stdin);
    }
    for (i=0;i<5;i++){
        if (carros[i].consumo > me){
            me = carros[i].consumo;
            mi = i;
        }
    }
    for (i=0;i<5;i++){
        carros[i].lkm = 1000/carros[i].consumo;
    }
    printf("O modelo mais economico é o %s.\n",carros[mi].modelo);
    printf("Quantos litros gasta para fazer 1000 km:\n");
    for (i=0;i<5;i++){
        printf("%s gasta %.2f litros.\n",carros[i].modelo,carros[i].lkm);
    }
}