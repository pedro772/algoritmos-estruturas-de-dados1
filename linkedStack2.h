
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedstack {
    struct no* topo;
    int qtdade;
};

struct linkedstack* inicializar() {
    struct linkedstack* pilha = (struct linkedstack*)malloc(sizeof(struct linkedstack));
    pilha->qtdade = 0;
    pilha->topo = NULL;

    return pilha;
}

struct no* alocarNovoNo(int valor) {
    struct no* temp = (no*)malloc(sizeof(no));

    temp->val = valor;
    temp->prox = NULL;

    return temp;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct linkedstack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return true;
    }

    return false;
}

//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedstack**
void empilhar(struct linkedstack** pilha, int valor) {
    if (*pilha == NULL) {
        *pilha = inicializar();
    }

    struct no* temp = (*pilha)->topo;

    (*pilha)->topo = alocarNovoNo(valor);
    (*pilha)->qtdade++;
    (*pilha)->topo->prox = temp;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
    if (pilha != NULL && pilha->qtdade > 0) {
        if (pilha->topo->prox != NULL) {
            pilha->topo = pilha->topo->prox;
        }

        pilha->qtdade--;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return INT_MIN;
    }
    else {
        desempilhar(pilha);
        return pilha->topo->val;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return INT_MIN;
    }

    return pilha->topo->val;
}

void exibirPilha(struct linkedstack* pilha) {
    //usamos o aux para percorrer a lista
    if (!vazia(pilha)) {
        struct no* aux = pilha->topo;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}
