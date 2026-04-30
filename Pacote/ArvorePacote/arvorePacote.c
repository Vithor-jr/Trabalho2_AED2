#include <stdlib.h>
#include "stdio.h"
#include "arvorePacote.h"

tipoNo* criarNo(Pacote pacote) {
    tipoNo* novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if (novoNo) {
        novoNo->pacote = pacote;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    }
    return novoNo;
}

tipoNo* inserirNo(tipoNo* raiz, Pacote pacote){

    if(raiz == NULL){
        return criarNo(pacote);
    }

    int resultadoComparacao = compararPacotes(pacote, raiz->pacote);

    if(resultadoComparacao < 0){
        //ID for menor, ele vai pra esquerda
        raiz->esq = inserirNo(raiz->esq, pacote);
    }
    else if(resultadoComparacao > 0){
        //ID for maior, ele vai pra direita
        raiz->dir = inserirNo(raiz->dir, pacote);
    }
    return raiz;
}

// montando o arquivo fisico
void percursoCentral(tipoNo* raiz, FILE *arquivo) {
    if (raiz != NULL) {
        
        percursoCentral(raiz->esq, arquivo);
        gravarPacoteEmArquivo(raiz->pacote, arquivo);
        percursoCentral(raiz->dir, arquivo);
    }
}