#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct arraylist {
    int* vetor;
    int qtdade;
    int capacidade;
};

struct arraylist* inicializarAL(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

void duplicarCapacidade(struct arraylist* lista) {
    lista->vetor = (int*)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
    lista->capacidade = 2 * lista->capacidade;
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
    if (lista->qtdade == lista->capacidade) {
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) {
        return lista->vetor[posicao];
    }
}

void inverterArrayList(struct arraylist* lista) {
    int inicio = 0;
    int fim = lista->qtdade;
    int temp;

    for (int reps = inicio; reps < fim; reps++) {
        for (int pos = inicio; pos < (fim - 1 - reps); pos++) {
            temp = lista->vetor[pos];
            lista->vetor[pos] = lista->vetor[pos + 1];
            lista->vetor[pos + 1] = temp;
        }
    }

    //inverte um struct arraylist* in-place
    //in-place significa que n�o poder� ser usado 
    //nenhum array ou lista adicional, al�m do original
}

struct no {
    struct no* ant;
    int val;
    struct no* prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializarDLL() {
    struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = 0;
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo;
    novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->ant = NULL;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor) {
    //aloca espa�o na mem�ria e popula novoNo
    struct no* novoNo = alocarNovoNo(valor);

    if (lista->cabeca == NULL) {
        //quando a lista � vazia, basta apontar o cabeca e cauda para o novoNo
        lista->cabeca = novoNo;
    }
    else {
        //atualizamos o ponteiro novoNo->ant para o antigo �ltimo n�
        novoNo->ant = lista->cauda;
        //ponteiro prox do antigo �ltimo n� para o novoNo
        lista->cauda->prox = novoNo;
    }
    //uma certeza: inserindo no fim, a cauda apontar� para o novoNo
    lista->cauda = novoNo;
    lista->qtdade++;
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    struct no* aux = lista->cabeca;
    for (int i = 0; i < posicao && aux->prox != NULL; i++) {
        aux = aux->prox;
    }
    return aux->val;
}

void inverterDoublyLinkedList(struct doublylinkedlist* lista) {
    struct no* temp1 = lista->cabeca;
    struct no* temp2 = temp1->prox;

    temp1->prox = NULL;
    temp1->ant = temp2;

    while (temp2 != NULL) {
        temp2->ant = temp2->prox;
        temp2->prox = temp1;
        temp1 = temp2;
        temp2 = temp2->ant;
    }

    lista->cabeca = temp1;

    //inverte uma struct doublylinkedlist* in-place
    //in-place significa que n�o poder� ser usado 
    //nenhum array ou lista adicional, al�m da original
}

void insereOrdenado(struct arraylist* lista, int val) {
    int inicio = 0;
    int fim = lista->qtdade - 1;
    int tam = lista->qtdade;
    int meio;

    while (tam >= 1) {
        meio = ceil((fim + inicio) / 2.0);

        if (lista->vetor[meio] == val) {
            break;
        }
        else if (val < lista->vetor[meio]) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;

            if (inicio > meio) {
                meio = inicio;
                break;
            }
        }
        tam = fim - inicio + 1;
    }

    for (int i = lista->qtdade; i > meio; i--) {
        lista->vetor[i] = lista->vetor[i - 1];
    }

    lista->vetor[meio] = val;
    lista->qtdade++;

    //deve usar o algoritmo de busca binaria para encontrar o indice
    //dps, abre espaco no array, e insere no local encontrado
}
