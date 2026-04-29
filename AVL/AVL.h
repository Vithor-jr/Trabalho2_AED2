#ifndef AVL_H
#define AVL_H

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
    short altura;
} No;

typedef struct {
    No *raiz;
} AVL;

No* criarNo(int valor);

void rotacionarAEsquerda(No **no);

void rotacionarADireita(No **no);

short fatorDeBalanceamento(No *no);

void criarAVL(AVL *arv);

short alturaDoNo(No *no);

void balanceador(No **no, int valor);

void inserirRec(No **no, int valor);

void inserirAVL(AVL *arv, int valor);

char buscarAVL(AVL *arv, int valor);

#endif