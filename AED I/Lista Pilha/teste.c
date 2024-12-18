#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para um nó da lista
struct lista {
    char nome[81];
    int matricula;
    char turma;
    float p1;
    float p2;
    struct lista* prox; // Próximo
    struct lista* ant;  // Anterior
};
typedef struct lista Lista;

// Função para criar um novo nó
Lista* cria_no(char* nome, int matricula, char turma, float p1, float p2) {
    Lista* novo_no = (Lista*)malloc(sizeof(Lista));
    if (novo_no != NULL) {
        strcpy(novo_no->nome, nome);
        novo_no->matricula = matricula;
        novo_no->turma = turma;
        novo_no->p1 = p1;
        novo_no->p2 = p2;
        novo_no->prox = NULL;
        novo_no->ant = NULL;
    }
    return novo_no;
}

// Função para inserir um novo nó na lista em ordem crescente de média
Lista* insere_ord(Lista* l, char* nome, int matricula, char turma, float p1, float p2) {
    Lista* novo_no = cria_no(nome, matricula, turma, p1, p2);
    if (novo_no == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        return l;
    }

    if (l == NULL) {
        return novo_no; // Se a lista estiver vazia, retorna o novo nó
    }

    Lista* atual = l;
    while (atual != NULL && (p1 + p2) / 2 >= (atual->p1 + atual->p2) / 2) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        // Insere o novo nó no final da lista
        l->ant = novo_no;
        novo_no->prox = l;
        return novo_no;
    } else {
        // Insere o novo nó antes do nó atual
        if (atual->ant != NULL) {
            atual->ant->prox = novo_no;
        }
        novo_no->ant = atual->ant;
        novo_no->prox = atual;
        atual->ant = novo_no;
        return l;
    }
}

// Função para destruir a lista e liberar a memória
void list_destroy(Lista* l) {
    while (l != NULL) {
        Lista* temp = l;
        l = l->prox;
        free(temp);
    }
}

int main() {
    Lista* lista_alunos = NULL;

    // Insere alunos na lista em ordem crescente de média
    lista_alunos = insere_ord(lista_alunos, "Alice", 123, 'A', 9.5, 8.7);
    lista_alunos = insere_ord(lista_alunos, "Bob", 456, 'B', 7.8, 9.0);
    lista_alunos = insere_ord(lista_alunos, "Carlos", 789, 'A', 6.0, 7.2);

    // Imprime a lista de alunos
    Lista* atual = lista_alunos;
    while (atual != NULL) {
        printf("Nome: %s, Média: %.2f\n", atual->nome, (atual->p1 + atual->p2) / 2);
        atual = atual->prox;
    }

    // Libera a memória da lista
    list_destroy(lista_alunos);

    return 0;
}