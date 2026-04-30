#ifndef PACOTE_H
#define PACOTE_H
#include <stdio.h>

typedef struct Pacote
{
    int id;
    char conteudo;
} Pacote;

Pacote criarPacote(int id, char conteudo);
int compararPacotes(Pacote pacote1, Pacote pacote2);
void gravarPacoteEmArquivo(Pacote pacote, FILE *arquivo);


#endif 