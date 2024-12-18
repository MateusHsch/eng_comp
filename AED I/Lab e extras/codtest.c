#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    FILE *fw = fopen("numbers.txt","w");
    if (fw == NULL){
        perror("numbers.txt");
        return 1;
    }
    int i,n;
    for (i=0;i<100;i++){
        n = rand()%100+1;
        fprintf(fw,"%d ",n);
    }
    fclose(fw);
    return 0;
}