#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Vetor{
    int x;
    int y;
    int z;
} Vetor;
int main (){
    Vetor vetores[3];
    int i;
    for (i=0;i<2;i++){
        printf("Insira a coordenada x do vetor %d:\n",i+1);
        scanf("%d",&vetores[i].x);
        printf("Insira a coordenada y do vetor %d:\n",i+1);
        scanf("%d",&vetores[i].y);
        printf("Insira a coordenada z do vetor %d:\n",i+1);
        scanf("%d",&vetores[i].z);
        //printf ("(%d,%d,%d)\n",vetores[i].x,vetores[i].y,vetores[i].z);
    }
    vetores[2].x = vetores[0].x +vetores[1].x;
    vetores[2].y = vetores[0].y +vetores[1].y;
    vetores[2].z = vetores[0].z +vetores[1].z;
    printf ("A soma do vetor 1 com o vetor 2 e o vetor:\n");
    printf ("(%d,%d,%d)\n",vetores[2].x,vetores[2].y,vetores[2].z);
    return 0;
}