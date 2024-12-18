#include <stdio.h>
#include <stdlib.h>
int alocacoes = 0;
int desalocacoes = 0;

typedef struct Aresta{
    int destino;
    int peso;
    struct Aresta* next;
}Aresta;

typedef struct Vertice{
    int id;
    struct Vertice* next;
    Aresta* aresta;
}Vertice;

typedef struct Grafo{
    Vertice* head;
    int qnt;
}Grafo;

Grafo* criar_grafo();
void liberar_grafo( Grafo *g );
void adicionar_vertice( Grafo *g );
void adicionar_aresta( Grafo *g );
void imprimir_grafo( Grafo *g );
void imprimir_vertices( Grafo *g );
Vertice* buscar_vertice( Grafo *g, int id );

void menor_caminho( Grafo *g );

int main(){

    Grafo *g = criar_grafo();
    int op = 0;
    do{
        system("cls");
        printf("0 - Sair.\n");
        printf("1 - Adicionar vertice.\n");
        printf("2 - Adicionar aresta.\n");
        printf("3 - Imprimir informacoes do grafo.\n");
        printf("4 - Encontrar menor caminho.\n");
        printf("Insira a opcao que deseja: ");
        scanf("%d",&op);
        getchar();
        switch (op){
            case 0:
                break;
            case 1:
                adicionar_vertice(g);
                break;
            case 2:
                adicionar_aresta(g);
                break;
            case 3:
                imprimir_grafo(g);
                break;
            case 4:
                menor_caminho(g);
                break;
            default:
                printf("Opcao Invalida.\n");
                system("pause");
                break;
        }
    }while(op != 0);
    liberar_grafo(g);
    printf("%d alocacoes.\n",alocacoes);
    printf("%d desalocacoes.\n",desalocacoes);
    return 0;
}
Grafo* criar_grafo(){
    Grafo *novo = (Grafo*) malloc(sizeof(Grafo));
    if (novo == NULL){
        printf("Malloc devolveu NULL!\n\n");
        exit(1);
    }
    alocacoes++;
    novo->head = NULL;
    novo->qnt = 0;
    return novo;
}
void liberar_grafo( Grafo *g ){
    if(g->qnt != 0){
        Vertice *atual = g->head;
        Vertice *temp;
        Aresta *a;
        Aresta *t;
        while(atual != NULL){
            a = atual->aresta;
            while(a != NULL){
                t = a;
                a = a->next;
                free(t);
                desalocacoes++;
            }
            temp = atual;
            atual = atual->next;
            free(temp);
            desalocacoes++;
        }
    }
    free(g);
    desalocacoes++;
}
void adicionar_vertice(Grafo *g) {
    system("cls");
    if (g->qnt < 20) {
        Vertice *atual = g->head;
        Vertice *anterior = NULL;
        int id;
        int ok=0;
        do{
            do {
                printf("Insira o valor do vertice (deve ser positivo): ");
                scanf("%d", &id);
                getchar();
            } while (id <= 0);
            while (atual != NULL && id != atual->id) {
                anterior = atual;
                atual = atual->next;
            }
            if (atual == NULL){
                atual = (Vertice*)malloc(sizeof(Vertice));
                if (atual == NULL) {
                    printf("Malloc devolveu NULL!\n\n");
                    exit(1);
                }
                alocacoes++;
                g->qnt++;
                atual->aresta = NULL;
                atual->next = NULL;
                atual->id = id;
                if (anterior != NULL) {
                    anterior->next = atual;
                } else {
                    g->head = atual;
                }
                ok = 1;
            }else{
                printf("Valor do vertice ja inserido.\n");
            }
        }while(ok != 1);
    } else {
        printf("Limite do grafo atingido.\n");
        system("pause");
    }
}
void adicionar_aresta( Grafo *g ){
    system("cls");
    if(g->qnt != 0){
        int vertice;
        imprimir_vertices(g);
        printf("Insira o vertice em que deseja adicionar uma aresta: ");
        scanf("%d",&vertice);
        getchar();
        Vertice *atual = g->head;
        while(atual != NULL && atual->id != vertice){
            atual = atual->next;
        }
        if(atual == NULL){
            printf("Vetice nao encontrado.\n");
            system("pause");
        }else{
            Aresta *a = (Aresta*) malloc(sizeof(Aresta));
            if(a == NULL){
                printf("Malloc devolveu NULL!\n\n");
                exit(1);
            }
            alocacoes++;
            a->next = atual->aresta;
            atual->aresta = a;
            //Verificar destino?
            printf("Insira o destino da aresta: ");
            scanf("%d",&a->destino);
            getchar();
            printf("Insira o peso da aresta: ");
            scanf("%d",&a->peso);
            getchar();
        }
    }else{
        printf("Sem vertices no grafo.\n");
        system("pause");
    }
}
void imprimir_vertices( Grafo *g ){
    if(g->qnt != 0){
        printf("Vertices: ");
        Vertice *atual = g->head;
        while(atual != NULL){
            printf("%d  ",atual->id);
            atual = atual->next;
        }
        printf("\n\n");
    }
}
void imprimir_grafo( Grafo *g ){
    system("cls");
    if(g->qnt != 0){
        printf("Vertice\t| arestas, peso ...\n");
        Vertice *atual = g->head;
        Aresta *a;
        while(atual != NULL){
            printf(" %d\t",atual->id);
            a = atual->aresta;
            while(a != NULL){
                printf("| %d, %d\t",a->destino, a->peso);
                a = a->next;
            }
            printf("\n");
            atual = atual->next;
        }
        printf("\n");
    }else{
        printf("Nenhum vertice para imprimir.\n");
    }
    system("pause");
}
Vertice* buscar_vertice( Grafo *g, int id ){
    Vertice *atual = g->head;
    while(atual != NULL && atual->id != id){
        atual = atual->next;
    }
    if(atual == NULL){
        printf("Vertice nao encontrado!!!\n");
        system("pause");
        return NULL;
    }else{
        return atual;
    }
}
void menor_caminho( Grafo *g ){
    system("cls");
    if (g->qnt < 1){
        printf("Nao ha vertices no grafo\n");
    }else if(g->qnt <2){
        printf("Ha apenar um vertice no grafo\n");
    }else{
        int dados[20][4]; // Atual, anterior, estimativa, fechado
        for(int i=0;i<20;i++){ //Inicializa a estrutura auxiliar
            dados[i][0] = -1;
            dados[i][1] = -1;
            dados[i][2] = __INT32_MAX__;
            dados[i][3] = 1;
        }
        imprimir_vertices(g);
        int inicial, final;
        do { //Pega o vertice inicial
            printf("Insira o vertice inicial (deve ser positivo): ");
            scanf("%d", &inicial);
            getchar();
        } while (inicial <= 0);
        do { //Pega o vertice final
            printf("Insira o vertice final (deve ser positivo): ");
            scanf("%d", &final);
            getchar();
        } while (final <= 0);
        int i=0;
        int j=0;
        Vertice *atual = g->head;
        while(atual != NULL){ //Atualiza os ids da estrutura aux. e seta o inicial
            if(atual->id == inicial){
                dados[i][0] = inicial;
                dados[i][2] = 0;
                dados[i][3] = 0;
            }else{
                dados[i][0] = atual->id;
                dados[i][3] = 0;
            }
            i++;
            atual = atual->next;
        }
        int ok=0;
        // Rever !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        do{ // Laço que acha o menor caminho
            int menor = __INT32_MAX__;
            int id = 0;
            for(i=0; i<20; i++){ // Acha o vertice com menor estimativa e guarda o id
                if(dados[i][2] < menor && dados[i][3] == 0){
                    menor = dados[i][2];
                    id = dados[i][0];
                }
            }
            if(menor != __INT32_MAX__){ // Se há vertices abertos continua
                i=0;
                Vertice *atual = g->head;
                while(atual != NULL && atual->id != id){ // busca o vertice pelo id
                    atual = atual->next;
                    i++;
                }
                if(atual == NULL){ // verifica se o vertice está no grafo
                    printf("Vertice nao encontrado!!!\n");
                    system("pause");
                    break;
                }
                dados[i][3] = 1; // Fecha o vertice
                Aresta *a = atual->aresta;
                while(a != NULL){ // Percorre as arestas
                    j=0;
                    while(a->destino != dados[j][0]){
                        j++;
                    }
                    if(menor+a->peso < dados[j][2]){
                        dados[j][1] = dados[i][0];
                        dados[j][2] = dados[i][2] + a->peso;
                    }
                    a = a->next;
                } // Atual, anterior, estimativa, fechado
            }else{
                ok = 1;
            }
        }while(ok != 1);
        int id = final;
        printf("Menor caminho:");
        while(id != inicial){
            i=0;
            while(dados[i][0] != id){
                i++;
            }
            printf(" %d <--",dados[i][0]);
            id = dados[i][1];
        }
        i=0;
        while(dados[i][0] != id){
            i++;
        }
        printf(" %d\n",dados[i][0]);
        system("pause");
    }
}
