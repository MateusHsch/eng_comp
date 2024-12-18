#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,h1=0,m1=0,s1=0,h2=0,m2=0,s2=0;
    char hor1[9],hor2[9],temp[3];
    printf("Insira o primeiro horario no formato HH:MM:SS\n");
    fgets(hor1,9,stdin);
    temp[0]=hor1[0];
    temp[1]=hor1[1];
    h1 = atoi(temp);
    temp[0]=hor1[3];
    temp[1]=hor1[4];
    m1 = atoi(temp);
    temp[0]=hor1[6];
    temp[1]=hor1[7];
    s1 = atoi(temp);
    if (h1<=23 && h1>=0 && m1<=60 && m1>=0 && s1<=60 && s1>=0){
        printf("Insira o segundo horario no formato HH:MM:SS\n");
        fflush(stdin);
        fgets(hor2,9,stdin);
        temp[0]=hor2[0];
        temp[1]=hor2[1];
        h2 = atoi(temp);
        temp[0]=hor2[3];
        temp[1]=hor2[4];
        m2 = atoi(temp);
        temp[0]=hor2[6];
        temp[1]=hor2[7];
        s2 = atoi(temp);
        for (i=0;i<+(9-1);i++){
        hor1[i] = "";
        }
        if (h2<=23 && h2>=0 && m2<=60 && m2>=0 && s2<=60 && s2>=0){
            s1 += (m1*60 + h1*3600);
            s2 += (m2*60 + h2*3600);
            h1=0,h2=0,m1=0,m2=0;
            if (s1>=s2){
                s1 = s1-s2;
            } else{
                s1 = s2-s1;
            }
            if (s1>=3600){
                h1 = s1/3600;
                s1 -= (h1*3600);
            }
            if (s1>=60){
                m1 = s1/60;
                s1 -= (m1*60);
            }
            printf ("A diferenca entre os horarios e de %d hora(s), %d minuto(s) e %d segundo(s).\n",h1,m1,s1);
        }
    }
}