#include <stdio.h>
#include "AVL.h"

No* criarNo(int valor) {
    No *aux;
    aux = (No *) malloc(sizeof(No));
    aux->dado = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->altura = 0;
}

short fatorDeBalanceamento(No *no) {
    return no->esq->altura - no->dir->altura;
}

void criarAVL(AVL *arv) {
    arv->raiz = NULL;
}

short alturaDoNo(No *no) {
    if(no->esq && no->dir) {
        return (no->esq->altura > no->dir->altura)? no->esq->altura:no->dir->altura;
    } 
    else if(no->dir == NULL) {return no->esq->altura;}

    return no->dir->altura;
}

void inserirEsqAVL(No *no, int valor) {
    if(no != NULL) {
        if(valor < no->esq->dado) {inserirEsqAVL(no->esq, valor);}
        else {inserirDirAVL(no->dir, valor);}
        no->altura = alturaDoNo(no);
    } else {
        no->esq = criarNo(valor);
    }
}

void inserirDirAVL(No *no, int valor) {
    if(no != NULL) {
        if(valor < no->dir->dado) {inserirEsqAVL(no->dir, valor);}
        else {inserirDirAVL(no->dir, valor);}
        no->altura = alturaDoNo(no);
    } else {
        no->dir = criarNo(valor);
    }
}

void inserirAVL(AVL *arv, int valor) {
    if(arv->raiz != NULL) {
        if(valor < arv->raiz->dado) {inserirEsqAVL(arv->raiz, valor);}
        else {inserirDirAVL(arv->raiz, valor);}
        arv->raiz->altura = alturaDoNo(arv->raiz->altura);
    } else {
        arv->raiz = criarNo(valor);
    }
    if(fatorDeBalanceamento(arv->raiz) > 1) {
        if(valor < arv->raiz->esq->dado) {rotacionarADireita(arv);}
        else {rotacionarAEsquerda(arv); rotacionarADireita(arv);}
    } else if(fatorDeBalanceamento(arv->raiz) < -1) {
        if(valor < arv->raiz->dir->dado) {rotacionarADireita(arv); rotacionarAEsquerda(arv);}
        else {rotacionarAEsquerda(arv);}
    }
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