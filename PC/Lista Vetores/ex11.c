#include <stdio.h>
#define TAM 5
int main(){
    char opcao = "";
    int lista[TAM];
    int i,var=0,cons=0,posicao=0;
    char cres="";
    while (opcao != 115){
        printf("a - Para preencher o vetor.\n");
        printf("b - Para encontrar um valor inteiro no vetor e imprime a sua respectiva posição.\n");
        printf("c - Para calcular o produto de todos os elementos do vetor por uma constante.\n");
        printf("d - Para contar a quantidade de vezes que aparece um valor.\n");
        printf("e - Para verificar se os elementos do vetor estão em ordem crescente.\n");
        printf("s - Para sair.\n");
        scanf("%c",&opcao);
        if (opcao == 97 || opcao == 65){
            for (i=0;i<(TAM-1);i++){
                printf("Insira valores inteiros para preencher o vetor.\n");
                scanf("%d",&lista[i]);
            }
            printf("O vetor foi Preenchido.\n\n");
        }
        if (opcao == 98 || opcao == 66){
            printf("Insira o valor que deseja encontrar:\n");
            scanf("%d",&var);
            for (i=0;i<(TAM-1);i++){
                if(lista[i] == var){
                    posicao=i;
                }
            }
            if (posicao == 0){
                printf("O valor nao foi encontrado.\n\n");
            }else{
                printf("O valor esta na posicao %d do vetor.\n\n",posicao);
            }
            posicao=0;
            var=0;
        }
        if (opcao == 99 || opcao == 67){
            printf("Insira a constante:\n");
            scanf("%d",&cons);
            for (i=0;i<(TAM-1);i++){
                lista[i] = cons*lista[i];
            }
            printf("O vetor foi multiplicado.\n\n");
            cons=0;
        }
        if (opcao == 100 || opcao == 68){
            printf("Insira o valor:\n");
            scanf("%d",&cons);
            for (i=0;i<(TAM-1);i++){
                if (lista[i] == cons){
                    var++;
                }
            }
            printf("O valor aparece %d vezes no vetor.\n\n",var);
            cons=0;
            var=0;
        }
        if (opcao == 101 || opcao == 69){
            for (i=1;i<(TAM-1);i++){
                if (lista[i-1] < lista[i]){
                    cres = "s";
                }
            }
            if (cres == 115){
                printf("Vetor ordenado.\n\n");
            }else{
                printf("Vetor nao ordenado.\n\n"); 
            }
            cres = "";
        }
        printf("ok\n");
    } 
}