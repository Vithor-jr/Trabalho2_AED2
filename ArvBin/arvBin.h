#ifndef ARVBIN_H
#define ARVBIN_H

typedef struct tipoNo{
    int chave;
    struct tipoNo* esq;
    struct tipoNo* dir;
}tipoNo;

typedef struct tipoArv{
    tipoNo* raiz;
}tipoArv;

void inicializarArvore(tipoArv* Arvore);

void inserirElemento(tipoArv* Arvore, int elemento);

void visita(tipoNo* no);

void preOrdem(tipoNo* raiz);

void posOrdem(tipoNo* raiz);

void emOrdem(tipoNo* raiz);

unsigned buscarElemento(tipoArv* Arvore, int elemento);

#endif