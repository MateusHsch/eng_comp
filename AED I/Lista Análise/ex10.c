/*
10.(Sequência de Palavras Fibonacci*) Tome a sequência de palavras
Fibonacci, definida da seguinte forma:
    a, i=0
    b, i=1
    F(i-1)*F(i-2), n>1
Isto é, as duas primeiras palavras desta sequência são a e b e as demais
podem ser construídas concatenando as duas anteriores. Baseando-se
nisso, as cinco primeiras palavras de Fibonacci são: a, ab, aab, abaab e
aababaab.
Tome F∞ como a palavra infinita gerada utilizando estas regras, isto é: F∞ =
aababaab . . .
Elabore um algoritmo (recursivo ou iterativo) que leve tempo o(n) para
dizer qual o n-ésimo caractere de F∞;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char fibChar(int n);
int main(){
    int n;
    printf("Insira o valor n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("entrada invlida. n deve ser um inteiro positivo.\n");
    } else {
        char nchar = fibChar(n);
        printf("O termo %d da sequencia e: %c\n", n, nchar);
    }

    return 0;
}
char fibChar(int n){
    int i;
    char str1[n+1]; 
    char str2[n+1];
    char str3[n+1];
    strcpy(str1,"a");
    strcpy(str2,"b");
    if (n == 1){
        return str1[0];
    }
    if (n == 2){
        return str2[0];
    }
    for (i=3;i<=n;i++){
        strcat(str1,str2); // ab b
        strcpy(str3,str1); // ab ab
        strcpy(str1,str2); // b  b
        strcpy(str2,str3); // ab ab
    }
    return str2[n-2];
}