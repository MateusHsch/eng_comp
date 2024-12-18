#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void deltaCalc(float a,float b,float c);
int main (){
    float a,b,c;
    printf("Insira os coeficientes da equacao.\n");
    printf("a:\n");
    scanf("%f",&a);
    printf("b:\n");
    scanf("%f",&b);
    printf("c:\n");
    scanf("%f",&c);
    deltaCalc(a,b,c);
    return 0;
}
void deltaCalc(float a,float b,float c){
    float delta=0.0;
    delta = (float)(pow(b,2.0)-4*a*c);
    printf("delta: %.2f\n",delta);
}
