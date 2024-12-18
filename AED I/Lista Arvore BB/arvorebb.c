#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct ab{
    int info;
    struct ab *esq;
    struct ab *dir;
}AB;

AB* ab_createNode( int info );
AB* ab_create( void );
void ab_destroy( AB* node );
void ab_print( AB* node, int tab );
AB* ab_insert( AB *node, int info );
AB* ab_remove( AB *node, int info );
AB* ab_copy( AB* node );
AB* ab_mirror( AB* node );
AB* ab_high( AB* node );
AB* ab_low( AB* node );
int ab_equal( AB* node1, AB* node2 );
int ab_ni( AB* node );
int ab_ne( AB* node );
int ab_estBin( AB* node );
int ab_highValue( AB* node );
int ab_higherx( AB* node, int x );
int ab_verificaABB( AB* node );
AB* ab_createVet(int* v, int n);
AB* ab_createVet2(int* v, int ini, int fim );

int main (){
    /*
    AB *root = ab_create();
    root = ab_insert(root,8);
    root = ab_insert(root,3);
    root = ab_insert(root,1);
    root = ab_insert(root,6);
    root = ab_insert(root,4);
    root = ab_insert(root,7);
    root = ab_insert(root,10);
    root = ab_insert(root,14);
    root = ab_insert(root,13);
    ab_print(root,2);
    printf("\n\n");
    */
    int v[9] = {1,2,3,4,5,6,7,8,9};
    AB* root = ab_createVet(v,9);
    ab_print(root,2);
    printf("\n\n");

    ab_destroy(root);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}
AB* ab_createNode( int info ){
    AB *novo = (AB*) malloc(sizeof(AB));
    if(novo == NULL){
        printf("Malloc devolveu NULL.\n\n");
        exit(1);
    }
    alocacoes++;
    novo->info = info;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}
AB* ab_create( void ){
    return NULL;
}
void ab_destroy( AB* node ){
    if(node != NULL){
        ab_destroy(node->esq);
        ab_destroy(node->dir);
        free(node);
        desalocacoes++;
    }
}
void ab_print( AB* node, int tab ){
    for(int i=0;i<tab;i++){
        printf("-");
    }
    if(node != NULL){
        printf(" %d\n",node->info);
        ab_print(node->esq,tab+2);
        printf("\n");
        ab_print(node->dir,tab+2);
    }else{
        printf(" vazio");
    }
}
AB* ab_insert( AB* node, int info ){
    if(node == NULL){
        node = (AB*) malloc(sizeof(AB));
        if(node == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        node->info = info;
        node->dir = NULL;
        node->esq = NULL;
    }else if(info < node->info){
        node->esq = ab_insert(node->esq,info);
    }else if(info > node->info){
        node->dir = ab_insert(node->dir,info);
    }else{
        printf("Elemento ja existe na arvore.\n\n");
    }
    return node;
}
AB* ab_remove( AB *node, int info ){
    if(node == NULL){
        printf("nada a remover.\n");
    }else if(info < node->info){
        node->esq = ab_remove(node->esq,info);
    }else if(info > node->info){
        node->dir = ab_remove(node->dir,info);
    }else{
        if((node->dir == NULL)&&(node->esq == NULL)){
            free(node);
            node = NULL;
        }else if(node->dir == NULL){
            AB* temp = node;
            node = node->esq;
            free(temp);
        }else if(node->esq == NULL){
            AB* temp = node;
            node = node->dir;
            free(temp);
        }else{
            AB* temp = node->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }
            node->info = temp->info;
            temp->info = info;
            node->esq = ab_remove(node->esq,info);
        }
    }
    return node;
}
AB* ab_copy( AB* node ){
    if(node == NULL){
        return NULL;
    }else{
        AB* novo = (AB*) malloc(sizeof(AB));
        if(novo == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        novo->info = node->info;
        novo->esq = ab_copy(node->esq);
        novo->dir = ab_copy(node->dir);
        return novo;
    }
}
AB* ab_mirror( AB* node ){
    if(node == NULL){
        return NULL;
    }else{
        AB* novo = (AB*) malloc(sizeof(AB));
        if(novo == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        novo->info = node->info;
        novo->dir = ab_mirror(node->esq);
        novo->esq = ab_mirror(node->dir);
        return novo;
    }
}
AB* ab_high( AB* node ){
    if (node == NULL){
        return NULL;
    }else{
        AB* high = ab_high(node->dir);
        if(high == NULL){
            high = node;
        }else{
            int maior = node->info;
            if(maior > high->info){
                high = node;
            }
        }
        return high;
    }
}
AB* ab_low( AB* node ){
    if (node == NULL){
        return NULL;
    }else{
        AB* low = ab_low(node->esq);
        if(low == NULL){
            low = node;
        }else{
            int menor = node->info;
            if(menor < low->info){
                low = node;
            }
        }
        return low;
    }
}
int ab_equal( AB* node1, AB* node2 ){
    if((node1 == NULL)&&(node2 == NULL)){
        return 1;
    }else if((node1 == NULL)||(node2 == NULL)){
        return 0;
    }else{
        int equal;
        if(node1->info == node2->info){
            equal = 1;
        }else{
            return 0;
        }
        equal = ab_equal(node1->esq,node2->esq);
        if(equal != 0){
            equal = ab_equal(node1->dir,node2->dir);
        }
        return equal;
    }
}
int ab_ni( AB* node ){
    if(node == NULL){
        return 0;
    }else{
        int nis = 0;
        nis += ab_ni(node->esq);
        nis += ab_ni(node->dir);
        if((node->esq != NULL)&&(node->dir != NULL)){
            nis += 1;
        }
        return nis;
    }
}
int ab_ne( AB* node ){
    if (node == NULL){
        return 0;
    }else{
        int nes = 0;
        nes += ab_ne(node->esq);
        nes += ab_ne(node->dir);
        if((node->esq == NULL)||(node->dir == NULL)){
            nes++;
        }
        return nes;
    }
}
int ab_estBin( AB* node ){ // XX
    if (node == NULL){
        return 0;
    }else{
        int ebinEsq,ebinDir;
        ebinEsq = ab_estBin(node->esq);
        ebinDir = ab_estBin(node->dir);
        if((ebinEsq == 0 && ebinDir == 0)||(ebinEsq != 0 && ebinDir != 0)){
            printf("passei\n");
            return 1;
        }else{
            return 0;
        }
    }
}
int ab_highValue( AB* node ){
    if (node == NULL){
        return -1;
    }else{
        int maior = node->info;
        int maiorEsq = ab_highValue(node->esq);
        if(maiorEsq > maior){
            maior = maiorEsq;
        }
        int maiorDir = ab_highValue(node->dir);
        if(maiorDir > maior){
            maior = maiorDir;
        }
        return maior;
    }
}
int ab_higherx( AB* node, int x ){
    if(node == NULL){
        return 0;
    }else{
        int maiores = 0;
        maiores += ab_higherx(node->esq,x);
        maiores += ab_higherx(node->dir,x);
        if(node->info > x){
            maiores++;
        }
        return maiores;
    }
}
int ab_verificaABB( AB* node ){
    if(node == NULL){
        return 1;
    }else if((node->dir == NULL)&&(node->esq == NULL)){
        return 1;
    }else if(node->dir == NULL){
        if(node->esq->info < node->info){
            return (1 && ab_verificaABB(node->esq));
        }else{
            return 0;
        }
    }else if(node->esq == NULL){
        if(node->dir->info > node->info){
            return (1 && ab_verificaABB(node->dir));
        }else{
            return 0;
        }
    }else{
        if((node->esq->info < node->info)&&(node->dir->info > node->info)){
            return (ab_verificaABB(node->esq) && ab_verificaABB(node->dir));
        }else{
            return 0;
        }
    }
}
AB* ab_createVet(int* v, int n){
    if(n == 0){
        return NULL;
    }else{
        return ab_createVet2(v,0,n-1);
    }
}
AB* ab_createVet2(int* v, int ini, int fim ){
    if(ini>fim){
        return NULL;
    }else{
        int meio = (fim + ini)/2;
        AB* novo = (AB*) malloc(sizeof(AB));
        if(novo == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        novo->info = v[meio];
        novo->esq = ab_createVet2(v,ini,meio-1);
        novo->dir = ab_createVet2(v,meio+1,fim);
        return novo;
    }
}
