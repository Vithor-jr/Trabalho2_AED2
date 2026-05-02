#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

No* criarNo(int valor) {
    No *aux;
    aux = (No *)malloc(sizeof(No));
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->altura = 0;

    return aux;
}

void rotacionarAEsquerda(No **no) {
    No *aux, *temp;
    aux = *no;
    temp = (*no)->dir;
    
    aux->dir = temp->esq;
    temp->esq = aux;

    aux->altura = alturaDoNo(aux);
    temp->altura = alturaDoNo(temp);

    *no = temp;
}

void rotacionarADireita(No **no) {
    No *aux, *temp;
    aux = *no;
    temp = (*no)->esq;

    aux->esq = temp->dir;
    temp->dir = aux;

    aux->altura = alturaDoNo(aux);
    temp->altura = alturaDoNo(temp);

    *no = temp;
}

short fatorDeBalanceamento(No *no) {
    short altEsq, altDir;
    altEsq = alturaDoNo(no->esq);
    altDir = alturaDoNo(no->dir);
    return altEsq - altDir;
}

void criarAVL(AVL *arv) {
    arv->raiz = NULL;
}

short alturaDoNo(No *no) {
    if (no == NULL) return -1;
    short altEsq = (no->esq != NULL) ? no->esq->altura : -1;
    short altDir = (no->dir != NULL) ? no->dir->altura : -1;
    return 1 + (altEsq > altDir ? altEsq : altDir);
}

void balanceador(No **no, int valor) {
    if(fatorDeBalanceamento(*no) > 1) {
        if(valor < (*no)->esq->dado) {rotacionarADireita(no);}
        else {rotacionarAEsquerda(&(*no)->esq); rotacionarADireita(no);}
    } else if(fatorDeBalanceamento(*no) < -1) {
        if(valor < (*no)->dir->dado) {rotacionarADireita(&(*no)->dir); rotacionarAEsquerda(no);}
        else {rotacionarAEsquerda(no);}
    }
}

void inserirRec(No **no, int valor) {
    if (*no == NULL) { *no = criarNo(valor); return; }

    if      (valor < (*no)->dado) inserirRec(&(*no)->esq, valor);
    else if (valor > (*no)->dado) inserirRec(&(*no)->dir, valor);

    (*no)->altura = alturaDoNo(*no);
    balanceador(no, valor);
}

void inserirAVL(AVL *arv, int valor) {
    inserirRec(&(arv->raiz), valor);
}

char buscarAVL(AVL *arv, int valor) {
    No *aux;
    aux = arv->raiz;

    while(aux) {
        if(aux->dado == valor) {return 1;} 
        else if(valor < aux->dado) {aux = aux->esq;}
        else {aux = aux->dir;}
    }

    return 0;
}