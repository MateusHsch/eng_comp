#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strBubble(char* str,int n);
int main (){
    char str[20] = "mateus";
    printf("%s\n",str);
    int n = strlen(str);

    strBubble(str,n);
    printf("%s\n",str);

    return 0;
}
void strBubble(char* str,int n){
    int i,continua;
    char aux;
    do{
        continua=0;
        for(i=0;i<n-1;i++){
            if(str[i]>str[i+1]){
                aux = str[i+1];
                str[i+1] = str[i];
                str[i] = aux;
                continua = i;
            }
        }
        n--;
    }while (continua != 0);
}