#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedqueue {
    struct no* frente;
    struct no* tras;
    int qtdade;
};

struct linkedqueue* inicializar() {
    struct linkedqueue* fila = (struct linkedqueue*)malloc(sizeof(struct linkedqueue));
    fila->qtdade = 0;
    fila->frente = NULL;
    fila->tras = NULL;

    return fila;
}

struct no* alocarNovoNo(int valor) {
    struct no* temp = (no*)malloc(sizeof(no));

    temp->val = valor;
    temp->prox = NULL;

    return temp;
}

bool vazia(struct linkedqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return true;
    }

    return false;
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct linkedqueue**
void enfileirar(struct linkedqueue** fila, int val) {
    if ((*fila) == NULL) {
        (*fila) = inicializar();
    }

    if ((*fila)->qtdade == 0) {
        (*fila)->frente = alocarNovoNo(val);
        (*fila)->qtdade++;
    }
    else {
        struct no* temp = (*fila)->frente;

        while (temp->prox != NULL) {
            temp = temp->prox;
        }

        temp->prox = alocarNovoNo(val);

        (*fila)->tras = temp->prox;
        (*fila)->qtdade++;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o nó removido (free)
int desenfileirar(struct linkedqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return INT_MIN;
    }

    struct no* temp = fila->frente;
    int frenteVal = temp->val;

    if (temp->prox != NULL) {
        fila->frente = temp->prox;
        free(temp);
    }
    else {
        free(temp);
    }

    fila->qtdade--;
    return frenteVal;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct linkedqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return INT_MIN;
    }

    return fila->frente->val;
}
