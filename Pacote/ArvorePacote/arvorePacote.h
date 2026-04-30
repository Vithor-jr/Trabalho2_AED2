#ifndef ARVOREPACOTE_H
#define ARVOREPACOTE_H
#include "pacote.h"

// este é um no que guarda um tipo Pacote
typedef struct tipoNo{
    Pacote pacote;
    struct tipoNo* esq;
    struct tipoNo* dir;
}tipoNo;

tipoNo* criarNo(Pacote pacote);
tipoNo* inserirNo(tipoNo* raiz, Pacote pacote);
void percursoCentral(tipoNo* raiz, FILE *arquivo);

#endif