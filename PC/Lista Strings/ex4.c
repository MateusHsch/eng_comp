#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    int i,qa=0,qe=0,qi=0,qo=0,qu=0;
    char frase[50];
    printf("insira uma palavra:\n");
    fgets(frase,50,stdin);
    for (i=0;i<(strlen(frase));i++){
        if (frase[i]=='a' || frase[i]=='A'){
            qa++;
        }else if (frase[i]=='e' || frase[i]== 'E'){
            qe++;
        }else if (frase[i]=='i' || frase[i]== 'I'){
            qi++;
        }else if (frase[i]=='o' || frase[i]== 'O'){
            qo++;
        }else if (frase[i]=='u' || frase[i]== 'U'){
            qu++;
        }
    }
    printf("Quantidade de vogais que a frase tem.\n");
    printf("a: %d\n",qa);
    printf("e: %d\n",qe);
    printf("i: %d\n",qi);
    printf("o: %d\n",qo);
    printf("u: %d\n",qu);
    return 0;
}
