#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct no{
    int valor;
    int fb;
    struct no* esq;
    struct no* dir;
}NO;

NO* avl_criar();
void avl_liberar( NO* no );
NO* avl_inserir( NO* no, int valor );
NO* avl_remover( NO *no,int valor );
NO* avl_buscar( NO* no, int valor );
NO* avl_balancear( NO* no );
NO* abb_rotsimplesDir( NO *no );
NO* abb_rotduplaDir( NO *no );
NO* abb_rotsimplesEsq( NO *no );
NO* abb_rotduplaEsq( NO *no );
int avl_altura( NO* no );

void avl_imprimir( NO* no, int tab );

int main (){
    NO* raiz = avl_criar();
    raiz = avl_inserir(raiz,5);
    raiz = avl_inserir(raiz,7);
    raiz = avl_inserir(raiz,6);
    raiz = avl_inserir(raiz,9);
    raiz = avl_inserir(raiz,1);
    raiz = avl_inserir(raiz,2);
    raiz = avl_inserir(raiz,3);
    avl_imprimir(raiz,2);
    printf("\n\n");

    avl_liberar(raiz);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}

NO* avl_criar(){
    return NULL;
}
void avl_liberar( NO* no ){
    if(no != NULL){
        avl_liberar(no->esq);
        avl_liberar(no->dir);
        free(no);
        desalocacoes++;
    }
}
NO* avl_inserir( NO* no, int valor ){
    if(no == NULL){
        NO* novo = (NO*) malloc(sizeof(NO));
        if(novo == NULL){
            printf("Malloc devolveu NULL.\n\n");
            exit(1);
        }
        alocacoes++;
        novo->valor = valor;
        novo->fb = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }else if(valor < no->valor){
        no->esq = avl_inserir(no->esq,valor);
        no->esq->fb = avl_altura(no->esq->esq)-avl_altura(no->esq->dir);
        if((no->esq->fb == 2)||(no->esq->fb == -2)){
            no = avl_balancear(no->esq);
        }
    }else if(valor > no->valor){
        no->dir = avl_inserir(no->dir,valor);
        no->dir->fb = avl_altura(no->dir->esq)-avl_altura(no->dir->dir);
        if((no->dir->fb == 2)||(no->dir->fb == -2)){
            no = avl_balancear(no->dir);
        }
    }else{
        printf("Elemento ja adicionado.\n\n");
    }
    no->fb = avl_altura(no->esq)-avl_altura(no->dir);
    if((no->fb == 2)||(no->fb == -2)){
        no = avl_balancear(no);
    }
    return no;
}
NO* avl_remover( NO *no,int valor ){
    if(no == NULL){
        return NULL;
    }else if(no->valor > valor){
        no->esq = avl_remover(no->esq,valor);
        no->esq->fb = avl_altura(no->esq->esq)-avl_altura(no->esq->dir);
        if((no->esq->fb == 2)||(no->esq->fb == -2)){
            no = avl_balancear(no->esq);
        }
    }else if(no->valor < valor){
        no->dir = avl_remover(no->dir,valor);
        no->dir->fb = avl_altura(no->dir->esq)-avl_altura(no->dir->dir);
        if((no->dir->fb == 2)||(no->dir->fb == -2)){
            no = avl_balancear(no->dir);
        }
    }else{ // Achou o nó a remover
        if((no->esq == NULL)&&(no->dir == NULL)){
            free(no);
            no = NULL;
        }else if(no->dir == NULL){
            NO *temp = no;
            no = no->esq;
            free(temp);
        }else if(no->esq == NULL){
            NO *temp = no;
            no = no->dir;
            free(temp);
        }else{
            NO *temp = no->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }
            no->valor = temp->valor;
            temp->valor = valor;
            no->esq = avl_remover(no->esq,valor);
        }
    }
    no->fb = avl_altura(no->esq)-avl_altura(no->dir);
    if((no->fb == 2)||(no->fb == -2)){
        no = avl_balancear(no);
    }
    return no;
}

int avl_altura( NO* no ){
    if(no == NULL){
        return -1;
    }else{
        int hesq = 0,hdir = 0;
        hesq = avl_altura(no->esq);
        hdir = avl_altura(no->dir);
        return 1+(hesq>hdir?hesq:hdir);

    }
}
NO* avl_balancear( NO* no ){
    printf("oi\n");
    if(no->fb == 2){
        if(no->esq->fb == 1){
            printf("simDir\n");
            no = abb_rotsimplesDir(no);
            no->fb = avl_altura(no->esq)-avl_altura(no->dir);
        }else{
            printf("dupDir\n");
            no = abb_rotduplaDir(no);
            no->fb = avl_altura(no->esq)-avl_altura(no->dir);
        }
    }else{
        if(no->dir->fb == -1){
            printf("simEsq\n");
            no = abb_rotsimplesEsq(no);
            no->fb = avl_altura(no->esq)-avl_altura(no->dir);
        }else{
            printf("dupEsq\n");
            no = abb_rotduplaEsq(no);
            no->fb = avl_altura(no->esq)-avl_altura(no->dir);
        }
    }
    return no;
}
NO* abb_rotsimplesDir( NO *no ){
    NO *temp = no->esq;
    no->esq = temp->dir;
    temp->dir = no;
    no->fb = avl_altura(no->esq)-avl_altura(no->dir);
    return temp;
}
NO* abb_rotduplaDir( NO *no ){
    NO *temp1 = no->esq;
    NO *temp2 = temp1->dir;
    temp1->dir = temp2->esq;
    temp2->esq = temp1;
    no->esq = temp2;
    temp2->dir = no;
    no->esq = NULL;
    temp1->fb = avl_altura(temp1->esq)-avl_altura(temp1->dir);
    no->fb = avl_altura(no->esq)-avl_altura(no->dir);
    return temp2;
}
NO* abb_rotsimplesEsq( NO *no ){
    NO *temp = no->dir;
    no->dir = temp->esq;
    temp->esq = no;
    no->fb = avl_altura(no->esq)-avl_altura(no->dir);
    return temp;
}
NO* abb_rotduplaEsq( NO *no ){
    NO *temp1 = no->dir;
    NO *temp2 = temp1->esq;
    temp1->esq = temp2->dir;
    temp2->dir = temp1;
    no->dir = temp2;
    temp2->esq = no;
    no->dir = NULL;
    temp1->fb = avl_altura(temp1->esq)-avl_altura(temp1->dir);
    no->fb = avl_altura(no->esq)-avl_altura(no->dir);
    return temp2;
}
void avl_imprimir( NO* no, int tab ){
    for(int i=0;i<tab;i++){
        printf("-");
    }
    if(no != NULL){
        printf(" %d, fb: %d\n",no->valor,no->fb);
        avl_imprimir(no->esq,tab+2);
        printf("\n");
        avl_imprimir(no->dir,tab+2);
    }else{
        printf(" vazio");
    }
}
