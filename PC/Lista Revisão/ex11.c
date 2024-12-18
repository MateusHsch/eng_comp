#include <stdio.h>
#include <string.h>
/*Escreva um programa que leia o número de dias gastos no hospital, um caractere representando o
tipo de quarto utilizado (P, C ou E), um caractere indicando se usou ou não o telefone (S ou N), um
caractere indicando se usou ou não a televisão (S ou N) e produza a seguinte saída:*/
int main(){
    int dias;
    double diaria,valor,desc,valorpg,vtelev,vtelef;
    char tipo,telef,telev;
    char tipoex[] = "",p[] = "PARTICULAR",c[] = "CONJUNTO",e[] = "ENFERMARIA";
    printf("Os dias gastos no hospital.\n");
    scanf("%d",&dias);
    printf("O tipo de quarto, P para particular, C para conjunto e E para enfermaria.\n");
    scanf("%c",&tipo);
    printf("Uso do telefone S para sim e N para nao.\n");
    scanf("%c",&telef);
    printf("Uso da televisao S para sim e N para nao.\n");
    scanf("%c",&telev);
    if (tipo == "P"){
        strcpy(tipoex,p);
        diaria = 125.00 * dias;
    }else if (tipo == "C"){
        strcpy(tipoex,c);
        diaria = 95.00 * dias;
    }else if (tipo == "E"){
        strcpy(tipoex,e);
        diaria = 75.00 * dias;
    }else {
        printf("Tipo de quarto invalido.\n");
    }

    if (telev == "S"){
        vtelev = 3.50;
        valor = diaria + vtelev;
    }else if (telev == "N"){
        vtelev = 0.00;
        valor = diaria;
    }else {
        printf("Uso de televisao invalido.\n");
    }
    if (telef == "S"){
        vtelef = 1.75;
        valor = valor + vtelef;
    }else if (telef == "N"){
        vtelef = 0.00;
    }else {
        printf("Uso de telefone invalido.\n");
    }
    
    if (valor<500){
        desc = valor * 0.05;
    }else if(valor>=500 && valor<1000){
        desc = valor * 0.10;
    }else{
        desc = valor * 0.15;
    }

    valorpg = valor - desc;
    printf("Hospital Exemplo S/A\n");
    printf("Diarias:        %d\n",dias);
    printf("Tipo quarto:    %s\n",tipoex);
    printf("Diarias:        R$ %.2lf\n",diaria);
    printf("Telefone:       R$ %.2lf\n",vtelef);
    printf("Televisao:      R$ %.2lf\n",vtelev);
    printf("Total:          R$ %.2lf\n",valor);
    printf("Descontos:      R$ %.2lf\n",desc);
    printf("Valor pago:     R$ %.2lf\n",valorpg);
}