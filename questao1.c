#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo{
    int chave;
    struct tipoNo* esq;
    struct tipoNo* dir;
}tipoNo;

typedef struct tipoArv{
    tipoNo* raiz;
}tipoArv;

void inicializarArvore(tipoArv* Arvore){
    Arvore -> raiz = NULL;
}

void inserirElemento(tipoArv* Arvore, int elemento ){
    tipoNo* aux = malloc(sizeof(tipoNo));
    aux->esq = NULL;
    aux->dir = NULL;
    aux->chave = elemento;
    if(!Arvore->raiz){
        Arvore->raiz = aux;
    }else{
        tipoNo* pai = NULL;
        tipoNo* folha = Arvore->raiz;
        while(folha!=NULL){
            pai = folha;
            if(elemento  > folha->chave ){
                folha = folha->dir;
            }else{
                folha = folha->esq;
            }
        }
        if (elemento > pai->chave){
            pai->dir = aux;
        }else{
            pai->esq = aux;
        }
    }
}

void visita(tipoNo* no){
    printf("%d ", no->chave);
}

void preOrdem(tipoNo* raiz){
    if (raiz){
        visita(raiz);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(tipoNo* raiz){
    if (raiz){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        visita(raiz);
    }
}

void emOrdem(tipoNo* raiz){
    if (raiz){
        emOrdem(raiz->esq);
        visita(raiz);
        emOrdem(raiz->dir);
    }
}

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