#include <stdio.h>
#include <stdlib.h>
typedef struct Data{
    int d,m,a;
} Data;
int main(){
    Data datas[2];
    int i,dias=0,d1=0,d2=0,var=0;
    for (i=0;i<2;i++){
        printf("Insira o dia da data %d:\n",i+1);
        scanf("%d",&var);
        if (var>=1 && var<=30){
            datas[i].d = var;
        }else {
            printf("Dia invalido");
            break;
        }
        printf("Insira o mes da data %d:\n",i+1);
        scanf("%d",&var);
        if (var>=1 && var<=12){
            datas[i].m = var-1;
        }else {
            printf("mes invalido");
            break;
        }
        printf("Insira o ano da data %d:\n",i+1);
        scanf("%d",&var);
        if (var>0){
            datas[i].a = var-1;
        }else {
            printf("ano invalido");
            break;
        }
    }
    d1 = datas[0].a*365 + datas[0].m*30 + datas[0].d;
    d2 = datas[1].a*365 + datas[1].m*30 + datas[1].d;
    dias = abs(d1-d2);
    printf("dias entre as datas: %d",dias);
    return 0;
}