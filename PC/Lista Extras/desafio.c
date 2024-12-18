#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int i;
    int chose;
    int number = rand()%10;
    printf("Tente adivinhar o numero de 0 a 9.\n");
    for(i=1;i<=3;i++){
        printf("O numero:\n");
        scanf("%d",&chose);
        if (chose < number){
            printf("Numero errado, tente um numero maior.\n");
        }else if (chose > number){
            printf("Numero errado, tente um numero menor.\n");
        }else {
            printf("Parabens esse e o numero.\n");
            break;
        }
        
    }
    return 0;
}
