#include <stdio.h>
int main(){
    int num_max=15, c,i;

    for(c = 1; c<=num_max ; c++){
        for (i = 1; i <= (num_max-c); i++)
          printf(" ");
        for (i = 1; i <= (c*2-1); i+=1)
          printf("*");
        printf("n");  
    }
    for(c = 1; c<=2 ; c++){
        for (i = 1; i <= (num_max-1); i++)
          printf(" ");
        printf("#n");  
    }    
    printf("BOAS FESTAS E UM BAITA 2024");
}