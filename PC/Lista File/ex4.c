#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    FILE *fr = fopen("entrada.txt","r");
    int fig,cont=0;
    float p1,p2,somat=0.0;
    if (fr == NULL){
        perror("ERRO");
        return 1;
    }
    while (fscanf(fr,"%d %f %f",&fig,&p1,&p2) != EOF){
        switch (fig){
            case 1:
                somat += p1*p2;
                cont++;
                break;
            case 2:
                somat += (p1*p2)/2;
                cont++;
                break;
            case 3:
                somat += 3.1415*pow(p1,2);
                cont++;
                break;
            default:    
                break;
        }
    }
    fclose(fr);
    if (somat == 0.0){
        printf("VAZIO\n");
    }else {
        printf("A media da area das figuras e: %.2f\n",somat/cont);
    }
    return 0;
}