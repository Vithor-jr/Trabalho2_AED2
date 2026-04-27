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

void criarAVL(AVL *arv);

void inserirAVL(AVL *arv, int valor);

char buscarAVL(AVL *arv, int valor);

short fatorDeBalanceamento(No *no);

short alturaDoNo(No *no);

void rotacionarAEsquerda(AVL *arv);

void rotacionarADireita(AVL *arv);

#endif