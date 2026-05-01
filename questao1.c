#include <stdio.h>
#include <stdlib.h>
#include "ArvBin/arvBin.h"

int main(){
    tipoArv Arvore;
    inicializarArvore(&Arvore);
    int vet[20] = {10, 1, 87, 34, 98, 76,12, 11, 24, 93, 13, 22, 14, 15, 71, 135, 765, 193, 1537, 1345};
    
    for (int i=0; i<20; i++){
        inserirElemento(&Arvore, vet[i]);
    }
    tipoNo* aux = Arvore.raiz;
    printf("Pré Ordem: ");
    preOrdem(aux);
    printf("\n");
    printf("Pós Ordem: ");
    posOrdem(aux);
    printf("\n");
    printf("Em Ordem: ");
    emOrdem(aux);
}