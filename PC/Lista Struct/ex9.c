#include <stdio.h>
#include <stdlib.h>
#define TAM 2
typedef struct Eletro{
    int nfab,tempa;
    float pot;
} Eletro;
int main(){
    Eletro eletros[TAM];
    int i,t;
    float cont;
    for (i=0;i<TAM;i++){
        printf("N. de fabricacao do eletrodomestico %d:\n",i+1);
        scanf("%d",&eletros[i].nfab);
        printf("Potencia em kW do eletrodomestico %d:\n",i+1);
        scanf("%f",&eletros[i].pot);
        printf("Tempo ativo (em horas por dia) do eletrodomestico %d:\n",i+1);
        scanf("%d",&eletros[i].tempa);
        fflush(stdin);
    }
    printf("Dias de consumo:\n");
    scanf("%d",&t);
    fflush(stdin);
    for (i=0;i<TAM;i++){
        cont += t*eletros[i].tempa*eletros[i].pot;
    }
    printf("Consumo total da casa em %d dias: %.2f kW\n",t,cont);
    for (i=0;i<TAM;i++){
        printf("O eletrodomestico %d coresponde a %.2f por cento do cosumo total.\n",eletros[i].nfab,((t*eletros[i].tempa*eletros[i].pot)/cont)*100);
    }
    return 0;
}