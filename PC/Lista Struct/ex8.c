#include <stdio.h>
#include <stdlib.h>
typedef struct Horario{
    int h,m,s;
} Horario;
int main(){
    Horario horarios[3];
    int i,s1=0,s2=0,s3=0;
    for (i=0;i<2;i++){
        printf("Insira o horario %d.\n",i+1);
        printf("horas: ");
        scanf("%d",&horarios[i].h);
        printf("minutos: ");
        scanf("%d",&horarios[i].m);
        printf("segundos: ");
        scanf("%d",&horarios[i].s);
        fflush(stdin);
    }
    horarios[2].h = 0;
    horarios[2].m = 0;
    horarios[2].s = 0;
    s1 = horarios[0].h*3600+horarios[0].m*60+horarios[0].s;
    s2 = horarios[1].h*3600+horarios[1].m*60+horarios[1].s;
    s3 = abs(s1-s2);
    horarios[2].h = (int)s3/3600;
    s3 -= horarios[2].h*3600;
    horarios[2].m = (int)s3/60;
    s3 -= horarios[2].m*60;
    horarios[2].s = s3;
    printf("A diferenca entre os horarios e de %d:%d:%d.\n",horarios[2].h,horarios[2].m,horarios[2].s);
    return 0;
}