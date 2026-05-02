#ifndef ARVOREPACOTE_H
#define ARVOREPACOTE_H
#include "../pacote.h"

// este é um no que guarda um tipo Pacote
typedef struct NoPacote{
    Pacote pacote;
    struct NoPacote* esq;
    struct NoPacote* dir;
}NoPacote;

NoPacote* criarNoPacote(Pacote pacote);
NoPacote* inserirNoPacote(NoPacote* raiz, Pacote pacote);
void percursoCentral(NoPacote* raiz, FILE *arquivo);
void liberarArvorePacote(NoPacote* raiz);

#endif