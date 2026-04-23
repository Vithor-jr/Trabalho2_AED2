#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000000

typedef struct tipoNo {
    int chave;
    struct tipoNo* esq;
    struct tipoNo* dir;
} tipoNo;

typedef struct tipoArv {
    tipoNo* raiz;
} tipoArv;

clock_t Timer_start() {
    return clock();
}

double Timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

void inicializarArvore(tipoArv* Arvore) {
    Arvore->raiz = NULL;
}

void inserirElemento(tipoArv* Arvore, int elemento) {
    tipoNo* aux = malloc(sizeof(tipoNo));
    aux->esq = NULL;
    aux->dir = NULL;
    aux->chave = elemento;
    if (!Arvore->raiz) {
        Arvore->raiz = aux;
    } else {
        tipoNo* pai = NULL;
        tipoNo* folha = Arvore->raiz;
        while (folha != NULL) {
            pai = folha;
            if (elemento > folha->chave)
                folha = folha->dir;
            else
                folha = folha->esq;
        }
        if (elemento > pai->chave)
            pai->dir = aux;
        else
            pai->esq = aux;
    }
}

int BuscaBinaria(int *v, int chave) {
    int i = 0, j = TAM - 1, meio;
    while (i <= j) {
        meio = (i + j) / 2;
        if (v[meio] == chave)
            return 1;
        else if (chave > v[meio])
            i = meio + 1;
        else
            j = meio - 1;
    }
    return 0;
}

unsigned buscarElemento(tipoArv* Arvore, int elemento) {
    tipoNo* aux = Arvore->raiz;
    while (aux != NULL) {
        if (aux->chave == elemento)
            return 1;
        else if (elemento > aux->chave)
            aux = aux->dir;
        else
            aux = aux->esq;
    }
    return 0;
}

void PreencherVetorDesordenado(int vet[]) {
    for (int i = 0; i < TAM; i++) {
        vet[i] = rand() % TAM;
    }
}

int ElementoPresenteVetor(int vet[]) {
    int posicao = rand() % TAM;
    return vet[posicao];
}

int main() {
    srand(time(NULL));

    tipoArv Arvore;
    int* vet = malloc(TAM * sizeof(int));

    int valoresBusca[30];

    inicializarArvore(&Arvore);
    PreencherVetorDesordenado(vet);

    for (int i = 0; i < TAM; i++) {
        inserirElemento(&Arvore, vet[i]);
    }

    for (int i = 0; i < 15; i++) {
        valoresBusca[i] = ElementoPresenteVetor(vet);
        valoresBusca[i + 15] = rand() % TAM;          
    }

    double tempos[30];
    double somaTempos;

    for (int i = 0; i < 30; i++) {
        clock_t inicio = Timer_start();
        buscarElemento(&Arvore, valoresBusca[i]);
        tempos[i] = Timer_stop(inicio);
        somaTempos += tempos[i];
    }

    printf("\nmédia das 30 buscas na árvore: %.12f segundos\n", somaTempos / 30.0);

    somaTempos = 0;

    for (int i = 0; i < 30; i++) {
        clock_t inicio = Timer_start();
        BuscaBinaria(vet, valoresBusca[i]);
        tempos[i] = Timer_stop(inicio);
        somaTempos += tempos[i];
    }

    printf("\nmédia das 30 buscas no vetor: %.12f segundos\n", somaTempos / 30.0);

    free(vet);
}