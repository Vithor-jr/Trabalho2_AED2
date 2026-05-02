#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ArvBin/arvBin.h"
#include "AVL/AVL.h"

#define TAM 1000000

clock_t Timer_start() {
    return clock();
}

double Timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

int main() {
    double tempoCriacaoBin[10], tempoCriacaoAVL[10], tempoMedioBuscaBin[10], tempoMedioBuscaAVL[10];

    for(int j = 0; j < 10; j++) {
        arvBin bin;
        AVL avl;
        double tempoBin, tempoAVL;

        clock_t inicio = Timer_start();
        inicializarArvore(&bin);
        tempoBin = Timer_stop(inicio);
        inicio = Timer_start();
        criarAVL(&avl);
        tempoAVL = Timer_stop(inicio);

        for(int i = 1; i <= TAM; i++) {
            int valor = rand() % TAM;

            inicio = Timer_start();
            inserirElemento(&bin, valor);
            tempoBin += Timer_stop(inicio);
            inicio = Timer_start();
            inserirAVL(&avl, valor);
            tempoAVL += Timer_stop(inicio);
        }
        tempoCriacaoBin[j] = tempoBin;
        tempoCriacaoAVL[j] = tempoAVL;

        printf("---------------RODADA %d------------------: \n", j+1);
        printf("TEMPO DE CRIAÇÃO DA ABP: %f s\n", tempoBin);
        printf("TEMPO DE CRIAÇÃO DA AVL: %f s\n", tempoAVL);
        printf("ALTURA DA ABP: %d \n", altura(bin.raiz));
        printf("ALTURA DA AVL: %d \n", alturaDoNo(avl.raiz));

        tempoBin = 0; tempoAVL = 0;

        for(int i = 1; i <= 30; i++) {
            int valor = rand() % TAM;

            inicio = Timer_start();
            unsigned buscaBin = buscarElemento(&bin, valor);
            tempoBin += Timer_stop(inicio);

            inicio = Timer_start();
            char buscaAVL = buscarAVL(&avl, valor);
            tempoAVL += Timer_stop(inicio);
        }
        tempoMedioBuscaBin[j] = tempoBin/30;
        tempoMedioBuscaAVL[j] = tempoAVL/30;
        printf("TEMPO MÉDIO DE BUSCA NA ABP: %f s \n", tempoMedioBuscaBin[j]);
        printf("TEMPO MÉDIO DE BUSCA NA AVL: %f s \n", tempoMedioBuscaAVL[j]);
    }

    printf("RESULTADOS FINAIS: \n");
    double criacaoBin = 0, criacaoAVL = 0, buscaBin = 0, buscaAVL = 0;
    for(int i = 0; i < 10; i++) {
        criacaoBin += tempoCriacaoBin[i];
        criacaoAVL += tempoCriacaoAVL[i];
        buscaBin += tempoMedioBuscaBin[i];
        buscaAVL += tempoMedioBuscaAVL[i];
    }
    criacaoBin /= 10; criacaoAVL /= 10; buscaBin /= 10; buscaAVL /= 10;
    printf("TEMPO MÉDIO DE CRIAÇÃO DA ABP: %f s \n", criacaoBin);
    printf("TEMPO MÉDIO DE CRIAÇÃO DA AVL: %f s \n", criacaoAVL);
    printf("TEMPO MÉDIO DE BUSCA NA ABP: %f s \n", buscaBin);
    printf("TEMPO MÉDIO DE BUSCA NA AVL: %f s \n", buscaAVL);
}