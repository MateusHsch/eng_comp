#include <stdio.h>
#include <stdlib.h>
int binSearch(int* vet,int n,int x);
int main(){
    int vet[] = {10,20,30,40,50,60};
    int n = 6;
    int idx = binSearch(vet,n,50);
    if(idx == -1){
        printf("valor nao encontrado\n");
    }else{
        printf("%d esta na posicao: %d\n",50,idx);
    }
    return 0;
}
int binSearch(int* vet,int n,int x){
    int mid,left = 0,right = n-1;
    while(left <= right){
        mid = left+(right-left)/2;
        if (vet[mid] == x){
            return mid;
        }else if(vet[mid] < x){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}
    