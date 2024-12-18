#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct noa{
    int valor,fb;
    struct noa *esq,*dir;
}Noa;

Noa* criar_avl( void );
void liberar_avl( Noa *no );
Noa* inserir_avl( Noa* no, int valor );
Noa* remover_avl( Noa* no, int valor );
int altura_avl( Noa *no );
Noa* balancear_avl( Noa *no );
Noa* simplesDir( Noa* no );
Noa* duplaDir( Noa* no );
Noa* simplesEsq( Noa* no );
Noa* duplaEsq( Noa* no );


void imprimir_avl( Noa *no, int tab );

int main(){
    Noa* raiz = criar_avl();
    printf("altura: %d\n",altura_avl(raiz));
    raiz = inserir_avl(raiz,5);
    raiz = inserir_avl(raiz,3);
    raiz = inserir_avl(raiz,7);
    raiz = inserir_avl(raiz,2);
    printf("altura: %d\n",altura_avl(raiz));
    imprimir_avl(raiz,2);
    printf("\n\n");

    
    raiz = inserir_avl(raiz,1);
    imprimir_avl(raiz,2);
    printf("\n\n");

    raiz = inserir_avl(raiz,4);
    imprimir_avl(raiz,2);
    printf("\n\n");

    raiz = inserir_avl(raiz,9);
    imprimir_avl(raiz,2);
    printf("\n\n");

    raiz = remover_avl(raiz,4);
    imprimir_avl(raiz,2);
    printf("\n\n");

    liberar_avl(raiz);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}
Noa* criar_avl( void ){
    return NULL;
}
void liberar_avl( Noa *no ){
    if(no != NULL){
        liberar_avl(no->esq);
        liberar_avl(no->dir);
        free(no);
        desalocacoes++;
    }
}
Noa* inserir_avl( Noa* no, int valor ){
    if(no == NULL){
        Noa *novo = (Noa*) malloc(sizeof(Noa));
        if(novo == NULL){
            printf("Malloc devolveu Null.\n\n");
            exit(1);
        }
        alocacoes++;
        novo->valor = valor;
        novo->fb = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        //Balanceamento
        return novo;
    }else if(valor < no->valor){
        no->esq = inserir_avl(no->esq,valor);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        no = balancear_avl(no);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        return no;
    }else if(valor > no->valor){
        no->dir = inserir_avl(no->dir,valor);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        no = balancear_avl(no);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        return no;
    }else{
        printf("valor ja inserido");
        return no;
    }
}
Noa* remover_avl( Noa* no, int valor ){
    if(no == NULL){
        printf("Nada a remover\n\n");
        return no;
    }else if(valor < no->valor){
        no->esq = remover_avl(no->esq,valor);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        no = balancear_avl(no);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        return no;
    }else if(valor > no->valor){
        no->dir = remover_avl(no->dir,valor);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        no = balancear_avl(no);
        no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
        return no;
    }else{
        if((no->esq == NULL)&&(no->dir == NULL)){
            free(no);
            desalocacoes++;
            return NULL;
        }else if(no->dir == NULL){
            Noa* temp = no;
            no = no->esq;
            free(temp);
            desalocacoes++;
            return no;
        }else if(no->esq == NULL){
            Noa* temp = no;
            no = no->dir;
            free(temp);
            desalocacoes++;
            return no;
        }else{
            Noa* temp = no->esq;
            while(temp->dir != NULL){
                temp = temp->dir;
            }
            no->valor = temp->valor;
            temp->valor = valor;
            no->esq = remover_avl(no->esq,valor);
            no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
            return no;
        }
    }
}
int altura_avl( Noa *no ){
    if(no == NULL){
        return -1;
    }else{
        int hesq = 0,hdir = 0;
        hesq = altura_avl(no->esq) +1;
        hdir = altura_avl(no->dir) +1;
        return (hesq > hdir ? hesq : hdir);
    }
}
Noa* balancear_avl( Noa *no ){
    if(no->fb == 2){
        if(no->esq->fb == 1){
            no = simplesDir(no);
        }else{
            no = duplaDir(no);
        }
    }else if(no->fb == -2){
        if(no->dir->fb == -1){
            no = simplesEsq(no);
        }else{
            no = duplaEsq(no);
        }
    }
    return no;
}
Noa* simplesDir( Noa* no ){
    Noa* temp = no->esq;
    no->esq = temp->dir;
    temp->dir = no;
    no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
    return temp;
}
Noa* duplaDir( Noa* no ){
    Noa* temp1 = no->esq;
    Noa* temp2 = temp1->dir;
    temp1->dir = temp2->esq;
    temp2->esq = temp1;
    no->esq = temp2->dir;
    temp2->dir = no;
    temp1->fb = (altura_avl(temp1->esq) - altura_avl(temp1->dir));
    no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
    return temp2;
}
Noa* simplesEsq( Noa* no ){
    Noa* temp = no->dir;
    no->dir = temp->esq;
    temp->esq = no;
    no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
    return temp;
}
Noa* duplaEsq( Noa* no ){
    Noa* temp1 = no->dir;
    Noa* temp2 = temp1->esq;
    temp1->esq = temp2->dir;
    temp2->dir = temp1;
    no->dir = temp2->esq;
    temp2->esq = no;
    temp1->fb = (altura_avl(temp1->esq) - altura_avl(temp1->dir));
    no->fb = (altura_avl(no->esq) - altura_avl(no->dir));
    return temp2;
}
void imprimir_avl( Noa *no, int tab ){
    for(int i=0;i<tab;i++){
        printf("-");
    }
    if(no == NULL){
        printf(" vazio");
    }else{
        printf(" %d, fb: %d\n",no->valor,no->fb);
        imprimir_avl(no->esq,tab+2);
        printf("\n");
        imprimir_avl(no->dir,tab+2);
    }
}

