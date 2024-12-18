#include <stdio.h>

int main(){
    int arr[5] = { 30, 20, 50, 70, 10 };
    int *parr = &arr[4];
    int inx = 0;
    printf("%d\n",*parr);
    printf("%x\n",parr);
    inx = *parr++;
    printf("%d\n",*parr);
    printf("%x\n",parr);
    printf("%d\n",inx);
    return 0;
}