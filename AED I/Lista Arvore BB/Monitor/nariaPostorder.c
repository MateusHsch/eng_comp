#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore {
    int info;
    int numFilhos;
    struct NoArvore** filhos;
} TNoA;

TNoA* criarNo(int v);
TNoA* adicionarFilho(TNoA* pai, int v);
void imprimirArvore(TNoA* raiz, int nivel);
void liberar( TNoA *no );

void postordertravel(TNoA* root, int* returnSize,int* ptr);
int* postorder(TNoA* root, int* returnSize);

int main() {
    TNoA* raiz = criarNo(1);
    adicionarFilho(raiz, 3);
    adicionarFilho(raiz, 2);
    adicionarFilho(raiz, 4);
    TNoA* primeiroFilho = raiz->filhos[0];
    adicionarFilho(primeiroFilho, 5);
    adicionarFilho(primeiroFilho, 6);

    imprimirArvore(raiz, 2);
    printf("\n\n");
    int returnSize=0;
    int *arr = postorder(raiz,&returnSize);
    printf("[");
    for(int i=0;i<returnSize;i++){
        printf(" %d",arr[i]);
    }
    printf(" ]\n");
    free(arr);

    liberar(raiz);
    return 0;
}
TNoA* criarNo(int v) {
    TNoA* novo = (TNoA*)malloc(sizeof(TNoA));
    novo->info = v;
    novo->numFilhos = 0;
    novo->filhos = NULL;
    return novo;
}
TNoA* adicionarFilho(TNoA* pai, int v) {
    if (pai == NULL) {
        return NULL;
    }
    TNoA* novoFilho = criarNo(v);
    pai->numFilhos++;
    pai->filhos = (TNoA**)realloc(pai->filhos, pai->numFilhos * sizeof(TNoA*));
    pai->filhos[pai->numFilhos - 1] = novoFilho;
    return pai;
}
void imprimirArvore(TNoA* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }
    for (int i = 0; i < nivel; i++) {
        printf("-");
    }
    printf(" %d\n", raiz->info);
    for (int i = 0; i < raiz->numFilhos; i++) {
        imprimirArvore(raiz->filhos[i], nivel + 2);
    }
}
void liberar( TNoA *no ){
    int i = 0;
    while(no->numFilhos != 0){
        liberar(no->filhos[i]);
        i++;
        no->numFilhos--;
    }
    free(no);
}

void postordertravel(TNoA* root, int* returnSize,int* ptr){
    if(!root){
        return;
    }
    for(int i=0;i<root->numFilhos;i++){
        postordertravel(root->filhos[i], returnSize,ptr);
    }
    ptr[(*returnSize)++]=root->info;
}
int* postorder(TNoA* root, int* returnSize) {
    *returnSize=0;
    int *ptr=(int*)malloc(sizeof(int)*10000);
    postordertravel(root, returnSize,ptr);
    return ptr;
}