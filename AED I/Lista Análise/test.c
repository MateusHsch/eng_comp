#include <stdio.h>

int main(){
    int arr[5] = { 30, 20, 50, 70, 10 };
    int *parr = &arr[4];
    *parr = *parr +1;
    printf("%d\n",*parr);
    return 0;
}