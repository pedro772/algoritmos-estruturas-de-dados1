#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct noBst {
    int val;
    struct noBst* esq;
    struct noBst* dir;
};

/**
 * Funcao que aloca um novo noBst, e
 * ajusta os ponteiros esq e dir para NULL.
 **/
struct noBst* alocarNovoNo(int valor) {
    struct noBst* temp = (struct noBst*)malloc(sizeof(struct noBst));
    if (temp) {
        temp->val = valor;
        temp->esq = temp->dir = NULL;
        return temp;
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * insere um novo valor na BST. Tamanho deve
 * ser incrementado.
 * Ambos tamanho e raiz são passados por referência.
 **/
void inserir(struct noBst** raiz, int valor, int* tamanho) {
    tamanho++;
    if ((*raiz) == NULL) {
        (*raiz) = alocarNovoNo(valor);
    }
    else {
        if (valor < (*raiz)->val) {
            inserir(&(*raiz)->esq, valor, tamanho);
        }
        else {
            inserir(&(*raiz)->dir, valor, tamanho);
        }
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * verifica se a mesma contém um dado valor.
 **/
bool buscar(struct noBst* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    } 
    else if(raiz->val == valor) {
        return true;
    }
    
    if (valor > raiz->val) {
        return buscar(raiz->dir, valor);
    }
    else {
        return buscar(raiz->esq, valor);
    }
}

/**
 * Funcao que retorna o maior valor de uma BST.
 **/
int max(struct noBst* raiz) {
    struct noBst* valorAtual = raiz;

    while (valorAtual && valorAtual->dir != NULL) {
        valorAtual = valorAtual->dir;
    }

    if (valorAtual) {
        int valorMax = valorAtual->val;

        return valorMax;
    }
}

/**
 * Funcao que retorna o menor valor de uma BST.
 **/
int min(struct noBst* raiz) {
    struct noBst* valorAtual = raiz;

    while (valorAtual && valorAtual->esq != NULL) {
        valorAtual = valorAtual->esq;
    }

    if (valorAtual) {
        int valorMin = valorAtual->val;

        return valorMin;
    }
}

/**
 * Funcao que retorna a altura de uma BST.
 * A altura de uma BST é dada pela quantidade
 * de arestas entre a raiz e a folha mais distante.
 **/
int altura(struct noBst* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        int alturaEsquerda = altura(raiz->esq);
        int alturaDireita = altura(raiz->dir);

        if (alturaEsquerda > alturaDireita) {
            return (alturaEsquerda + 1);
        }
        else {
            return (alturaDireita + 1);
        }
    }
}

/**
 * Funcao que navega em-ordem na BST e
 * imprime seus elementos.
 **/
void emOrdem(struct noBst* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d", raiz->val);
        emOrdem(raiz->dir);
    }
}

/**
 * Funcao que navega pre-ordem na BST e
 * imprime seus elementos.
 **/
void preOrdem(struct noBst* raiz) {
    if (raiz != NULL) {
        printf("%d", raiz->val);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

/**
 * Funcao que navega pos-ordem na BST e
 * imprime seus elementos.
 **/
void posOrdem(struct noBst* raiz) {
    if (raiz != NULL) {
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
        printf("%d", raiz->val);
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * remove o no que contem o valor passado como
 * argumento. Tamanho deve ser decrementado.
 * Tamanho é passado por referência.
 **/
struct noBst* remover(struct noBst* raiz, int valor, int* tamanho) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->val) {
        raiz->esq = remover(raiz->esq, valor, --tamanho);
    }
    else if (valor > raiz->val) {
        raiz->dir = remover(raiz->dir, valor, --tamanho);
    }

    else {
        if (raiz->esq == NULL) {
            struct noBst* temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL) {
            struct noBst* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        struct noBst* temp = raiz->dir;

        while (temp && temp->esq != NULL) {
            temp = temp->esq;
        }

        raiz->val = temp->val;
        raiz->dir = remover(raiz->dir, temp->val, --tamanho);
    }

    return raiz;
}