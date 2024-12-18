#include <stdio.h>
#include <math.h>
//Faça um programa que leia a altura e diâmetro de uma lata de óleo, calcule e exiba o volume e a área lateral da lata.
int main(){
    double h,d,v,a,r2; //declara altura, diamentro, volume, area, raio e raio^2
    double pi = 3.14159265358979323846; 
    printf("Insira a altura da lata de oleo:\n");
    scanf("%lf",&h);
    printf("Insira o diametro da lata de oleo:\n");
    scanf("%lf",&d);
    r2 = pow((d/2),2.0);
    v = pi * r2 * h;
    a = 2 * pi * (d/2) * h;
    printf("O volume da lata e %.4lf u.v.\n",v);
    printf("A area lateral da lata e %.4lf u.a.\n",a);
}