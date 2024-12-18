#include <stdio.h>
#include <stdlib.h>
int multRec(int n1,int n2);
int main (){
    int n1,n2,s;
    printf("Insira n1:\n");
    scanf("%d",&n1);
    printf("Insira n2:\n");
    scanf("%d",&n2);
    s = multRec(n1,n2);
    printf("n1 x n2: %d\n",s);
    return 0;
}
int multRec(int n1,int n2){
    if (n2 == 0){
        return 0;
    }else if (n2 == 1){
        return n1;
    }else {
        return(n1 + multRec(n1,n2-1));
    }
}