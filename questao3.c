#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvBin/arvBin.h"
#include "Vetor/Vetor.h"

#define TAM 1000000

clock_t Timer_start() {
    return clock();
}

double Timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
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
        valoresBusca[i] = ElementoPresenteVetor(vet, TAM);
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
        BuscaBinaria(vet, valoresBusca[i], TAM);
        tempos[i] = Timer_stop(inicio);
        somaTempos += tempos[i];
    }

    printf("\nmédia das 30 buscas no vetor: %.12f segundos\n", somaTempos / 30.0);

    free(vet);
}