#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    lista->cabeca = NULL;
    lista->qtdade = 0;
    
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* temp = (no*)malloc(sizeof(no));
    temp->val = valor;
    temp->prox = NULL;

    return temp;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    if (lista->qtdade == 0) {
        lista->cabeca = alocarNovoNo(valor);
        lista->qtdade++;
    }
    else {
        struct no* temp = lista->cabeca;

        while (temp->prox != NULL) {
            temp = temp->prox;
        }

        temp->prox = alocarNovoNo(valor);
        lista->qtdade++;
    }
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    struct no* temp = alocarNovoNo(valor);

    if (lista->cabeca != NULL) {
        temp->prox = lista->cabeca;
    }

    lista->cabeca = temp;
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    struct no* temp1 = lista->cabeca;

    if (posicao == 0) {
        inserirElementoNoInicio(lista, valor);
    }
    else if (posicao > lista->qtdade - 1) {
        inserirElementoNoFim(lista, valor);
    }
    else {
        for (int i = 0; i < posicao; i++) {
                temp1 = temp1->prox;
        }

        struct no* temp2 = alocarNovoNo(valor);
        lista->qtdade++;
        temp1->prox = temp2;
        temp2->prox = temp2;
    }
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    if (posicao >= 0 && lista->cabeca != NULL) {
        struct no* temp1 = lista->cabeca;

        for (int i = 0; i < posicao; i++) {
            if (temp1->prox == NULL) {
                return temp1->val;
            }

            temp1 = temp1->prox;
        }

        return temp1->val;
    }
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    struct no* temp1 = lista->cabeca;

    if (posicao == 0) {
        lista->cabeca = temp1->prox;
        free(temp1);
        return;
    }

    for (int i = 0; i < posicao - 1; i++) {
        temp1 = temp1->prox;
    }

    struct no* temp2 = temp1->prox;
    temp1->prox = temp2->prox;
    free(temp2);
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}
