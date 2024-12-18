#include <stdio.h>
//Crie um programa que leia quantos minutos um atleta correu e exiba o tempo em horas e minutos
int main(){
    int minutos;
    int horas;
    printf("Quantos minutos o atleta correu?\n");
    scanf("%d",&minutos);
    horas = minutos/60;
    minutos = minutos % 60;
    printf("O atleta correu %d horas e %d minutos.\n",horas,minutos);
}