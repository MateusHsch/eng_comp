#include <stdio.h>
#include <stdlib.h>
char media(float n1,float n2);
int main (){
    float n1,n2;
    char grade;
    printf("Insira as notas.\n");
    printf("Nota 1:\n");
    scanf("%f",&n1);
    printf("Nota 2:\n");
    scanf("%f",&n2);
    grade = media(n1,n2);
    printf("A conceito do aluno e %c\n",grade);
    return 0;
}
char media(float n1,float n2){
    float media = (float) (n1+n2)/2;
    char grade;
    if (media>=0 && media<5){
        grade = 'D';
    }else if (media>=5 && media<7){
        grade = 'C';
    }else if (media>=7 && media<9){
        grade = 'B';
    }else if (media>=9 && media<=10){
        grade = 'A';
    }
    return (grade);
}