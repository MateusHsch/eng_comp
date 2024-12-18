#include <stdio.h>
#include <stdlib.h>
float pot(float x,int n);
int main (){
    float r,x = 8.0;
    int n = 3;
    r = pot(x,n);
    printf("%.2f^%d = %.2f\n",x,n,r);
    return 0;
}
float pot(float x,int n){
    if (n == 0){
        return 1;
    }else if (n == 1){
        return x;
    }else{
        n--;
        return (x * pot(x,n));
    }
}