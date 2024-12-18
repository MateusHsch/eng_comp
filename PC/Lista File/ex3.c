#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x);
int main (){
    int x;
    float s;
    FILE *fw = fopen("saida.txt","w");
    if (fw == NULL){
        perror("saida.txt");
        return 1;
    }
    for (x=1;x<=100;x++){
        s = (float) f(x);
        fprintf(fw,"%d\t%.5f\n",x,s);
    }
    fclose(fw);
    return 0;
}
float f(float x){
    float s;
    s = (float) 2 + cos(2*sqrt(x));
    return s;
}