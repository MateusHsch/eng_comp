#include <stdio.h>
//Faça um programa que leia o salário bruto de um funcionário e exiba o seu salário liquido descontando 15% do salário bruto.
int main(){
    float sbruto, sliquid;
    printf("Qual o salario bruto do funcionario?\n");
    scanf("%f",&sbruto);
    sliquid = sbruto * 0.85;
    printf("O salario liquido do funcionaro e %.2f\n",sliquid);
}