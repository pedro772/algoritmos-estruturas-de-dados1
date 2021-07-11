#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct arraystack {
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arraystack* inicializar(int tamArray) {
    struct arraystack* pilha = (struct arraystack*)malloc(sizeof(struct arraystack));
    
    if (tamArray < 0) {
        return NULL;
    }

    pilha->elementos = (int*)calloc(tamArray, sizeof(int));
    pilha->qtdade = 0;
    pilha->tamanho = tamArray;

    return pilha;
}

void duplicarCapacidade(struct arraystack* pilha) {
    pilha->tamanho *= 2;
    pilha->elementos = (int*)realloc(pilha->elementos, pilha->tamanho * sizeof(int));
}

//se a pilha estiver nula, instancie a pilha com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arraystack**
//se a pilha encher, duplique a capacidade do array
void empilhar(struct arraystack** pilha, int valor) {
    if (*pilha == NULL) {
        *pilha = inicializar(10);
    }
    
    if ((*pilha)->qtdade >= (*pilha)->tamanho) {
        duplicarCapacidade(*pilha);
    }

    (*pilha)->elementos[(*pilha)->qtdade] = valor;
    (*pilha)->qtdade++;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct arraystack* pilha) {
    if (pilha == NULL || pilha->qtdade <= 0) {
        return true;
    }
    
    return false;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct arraystack* pilha) {
    if (pilha != NULL && pilha->qtdade > 0) {
        pilha->qtdade--;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct arraystack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return INT_MIN;
    }
    
    int temp = pilha->elementos[pilha->qtdade - 1];
    desempilhar(pilha);
    return temp;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct arraystack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return INT_MIN;
    }

    return pilha->elementos[pilha->qtdade - 1];
}

void imprimir(struct arraystack* pilha) {
    printf("_\n");
    for (int i = pilha->qtdade - 1; i >= 0; i--) {
        printf("%d\n", pilha->elementos[i]);
    }
    printf("_\n\n");
}
