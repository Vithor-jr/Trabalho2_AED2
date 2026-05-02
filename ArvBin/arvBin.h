#ifndef ARVBIN_H
#define ARVBIN_H

typedef struct tipoNo{
    int chave;
    struct tipoNo* esq;
    struct tipoNo* dir;
}tipoNo;

typedef struct arvArv{
    tipoNo* raiz;
}arvBin;

void inicializarArvore(arvBin* Arvore);

void inserirElemento(arvBin * Arvore, int elemento);

unsigned buscarElemento(arvBin* Arvore, int elemento);

void visita(tipoNo* no);

void preOrdem(tipoNo* raiz);

void posOrdem(tipoNo* raiz);

void emOrdem(tipoNo* raiz);

void imprimeBonito(tipoNo* no, char* prefixo, int isEsq);

int alturaABP(tipoNo *raiz);

void mostrarArvore(arvBin* arv);

#endif