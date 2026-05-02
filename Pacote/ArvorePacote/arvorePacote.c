#include <stdlib.h>
#include "stdio.h"
#include "arvorePacote.h"

NoPacote* criarNoPacote(Pacote pacote) {
    NoPacote* novoNo = (NoPacote*)malloc(sizeof(NoPacote));
    if (novoNo) {
        novoNo->pacote = pacote;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    }
    return novoNo;
}

NoPacote* inserirNoPacote(NoPacote* raiz, Pacote pacote){

    if(raiz == NULL){
        return criarNoPacote(pacote);
    }

    int resultadoComparacao = compararPacotes(pacote, raiz->pacote);

    if(resultadoComparacao < 0){
        //ID for menor, ele vai pra esquerda
        raiz->esq = inserirNoPacote(raiz->esq, pacote);
    }
    else if(resultadoComparacao > 0){
        //ID for maior, ele vai pra direita
        raiz->dir = inserirNoPacote(raiz->dir, pacote);
    }
    return raiz;
}

// montando o arquivo fisico
void percursoCentral(NoPacote* raiz, FILE *arquivo) {
    if (raiz != NULL) {
        
        percursoCentral(raiz->esq, arquivo);
        gravarPacoteEmArquivo(raiz->pacote, arquivo);
        percursoCentral(raiz->dir, arquivo);
    }
}

void liberarArvorePacote(NoPacote* raiz) {

    if(raiz == NULL){
        return;
    }
        liberarArvorePacote(raiz->esq);
        liberarArvorePacote(raiz->dir);
        free(raiz);
}