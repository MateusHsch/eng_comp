/*
6. Desenvolva um TAD que represente um conjunto de inteiros. Para isso, utilize um vetor de inteiros.
O TAD deverá conter as seguintes funções:
*/
#include <stdio.h>
#include <stdlib.h>
/* ----------< struct integers >---------- */
struct integers{
    int* vet;
};
typedef struct integers Inetegers;
/* ----------< integers.h >------------ */
int* integers_voidcreate();
int* integers_union(int* v1,int* v2,int n1,int n2);
int* integers_insert(int* v,int* n,int x);
int* integers_remove(int* v,int* n,int x);
int integers_lenght(int* v);
/* ----------< main.c >----------- */
int main(){
    
    return 0;
}
/* ----------< integers.c >---------- */
int* integers_voidcreate(){
    int vet[0];
    return vet;
}
int* integers_union(int* v1,int* v2,int n1,int n2){
    if(n1>0 && n2>0){
        int i,j,tam=0,add;
        int* vt = (int*) malloc((n1+n2)*sizeof(int));
        for(i=0;i<n1;i++){
            vt[i] = v1[i];
            tam++;
        }
        for(i=0;i<n2;i++){
            add = 1;
            for(j=0;j<n1;j++){
                if(v2[i] != v1[j]){
                    add = 0;
                }
            }
            if(add == 1){
                vt[tam] = v1[i];
                tam++;
            }
        }
        int* vf = (int*) malloc((tam)*sizeof(int));
        for(i=0;i<tam;i++){
            vf[i] = vt[i];
        }
        free(vt);
        return vf;
    }else if (n1>0){
        return n1;
    }else{
        return n2;
    }
}
int* integers_insert(int* v,int* n,int x){
    int i,add=1;
    for(i=0;i<*n;i++){
        if(v[i] == x){
            add=0;
        }
    }
    if(add == 1){
        int* vf = (int*) malloc((*n+1)*sizeof(int));
        for(i=0;i<*n;i++){
            vf[i] = v[i];
        }
        vf[*n] = x;
        *n = *n+1;
        free(v);
        return vf;
    }else{
        return v;
    }
}
int* integers_remove(int* v,int* n,int x){
    int i,rem=0,idx;
    while(rem == 0 && i<*n){
        if(v[i] == x){
            rem=1;
            idx=i;
        }
        i++;
    }
    if(rem == 1){ 
        for(i=idx;i<*n-1;i++){
            v[i] = v[i+1];
        }
        int* vf = (int*) malloc((*n-1)*sizeof(int));
        for(i=0;i<*n-1;i++){
            vf[i] = v[i];
        }
        free(v);
        *n = *n-1;
        return vf;
    }else{
        return v;
    }
}
int integers_lenght(int* v){
    int n = sizeof(v);
    return n;
}