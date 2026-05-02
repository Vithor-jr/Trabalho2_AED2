#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"

void inicializarArvore(arvBin* Arvore) {
    Arvore->raiz = NULL;
}

void inserirElemento(arvBin* Arvore, int elemento) {
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

void visita(tipoNo* no){
    printf("%d ", no->chave);
}

void preOrdem(tipoNo* raiz){
    if (raiz){
        visita(raiz);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(tipoNo* raiz){
    if (raiz){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        visita(raiz);
    }
}

void emOrdem(tipoNo* raiz){
    if (raiz){
        emOrdem(raiz->esq);
        visita(raiz);
        emOrdem(raiz->dir);
    }
}

unsigned buscarElemento(arvBin* Arvore, int elemento) {
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

int altura(tipoNo *raiz) {
    if (raiz == NULL) {
        return -1; // Árvore vazia, altura -1
    } else {
        int altEsq = altura(raiz->esq);
        int altDir = altura(raiz->dir);
        
        // Retorna a maior altura + 1
        if (altEsq > altDir)
            return (altEsq + 1);
        else
            return (altDir + 1);
    }
}