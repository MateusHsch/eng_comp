#include <stdio.h>
#include <stdlib.h>
typedef struct{
int x;
int y;
} Ponto;
int main(){
    int i;
    Ponto pontos[3];
    for (i=0;i<3;i++){
        printf("Pontos 1 e 3 formam o retangulo e o ponto 3 e o independente.\n");
        printf("Coordenada x do ponto %d:\n",i+1);
        scanf("%d",&pontos[i].x);
        printf("Coordenada y do ponto %d:\n",i+1);
        scanf("%d",&pontos[i].y);
    }
    if (pontos[0].x<pontos[1].x && pontos[0].y<pontos[1].y){
        if (pontos[2].x>=pontos[0].x && pontos[2].x<=pontos[1].x){
            //printf("x ok\n");
            if (pontos[2].y>=pontos[0].y && pontos[2].y<=pontos[1].y){
                //printf("y ok\n");
                printf("O ponto esta dentro desse retangulo.\n");
            }else {
                printf("O ponto nao esta dentro desse retangulo.\n");
            }
        } else{
            printf("O ponto nao esta dentro desse retangulo.\n");
        }
    } else{
        if (pontos[2].x<=pontos[0].x && pontos[2].x>=pontos[1].x){
            //printf("x ok\n");
            if (pontos[2].y<=pontos[0].y && pontos[2].y>=pontos[1].y){
                //printf("y ok\n");
                printf("O ponto esta dentro desse retangulo.\n");
            }else {
                printf("O ponto nao esta dentro desse retangulo.\n");
            }
        } else{
            printf("O ponto nao esta dentro desse retangulo.\n");
        }
    }
    return 0;
}