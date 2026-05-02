#include "Vetor.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

Vetor CriarVetor(int tamanho) {
    Vetor v;
    v.tamanho = tamanho;
    v.conteudo = (int *)malloc(tamanho * sizeof(int));
    return v;
}

void LiberarVetor(Vetor *v) {
    free(v->conteudo);
    v->conteudo = NULL;
    v->tamanho = 0;
}

void embaralhar(Vetor *v) {
    for (int i = v->tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = v->conteudo[i];
        v->conteudo[i] = v->conteudo[j];
        v->conteudo[j] = temp;
    }
}

void PreencherVetorDesordenado(Vetor *v) {
    for (int i = 0; i < v->tamanho; i++) {
        v->conteudo[i] = i + 1;
    }
    embaralhar(v);
}

void PreencherVetorOrdenado(Vetor *v) {
    int aux;
    for (int i = 0; i < v->tamanho; i++) {
        aux = rand() % 100;
        if (i == 0) {
            v->conteudo[i] = aux;
        } else {
            v->conteudo[i] = v->conteudo[i-1] + aux;
        }
    }
}

int GetValue (Vetor *v, int index){
	if (index < v->tamanho && index > 0){
		return v->conteudo[index];
	} else {
		return -1;
	}
}

void SetValue (Vetor *v, int index, int value){
	if (index < v->tamanho && index > 0){
		v->conteudo[index] = value;
	}
}

void MostrarVetor(Vetor *v) {
    printf("[");
    for (int i = 0; i < v->tamanho; i++) {
        if (i != v->tamanho - 1)
            printf("%d ", v->conteudo[i]);
        else
            printf("%d]\n", v->conteudo[i]);
    }
}

void CopiarVetor(Vetor *origem, Vetor *destino) {
    for (int i = 0; i < origem->tamanho; i++) {
        destino->conteudo[i] = origem->conteudo[i];
    }
}

int BuscaBinaria(Vetor *v, int chave) {
    int i = 0, j = v->tamanho - 1, meio;
    while (i <= j) {
        meio = (i + j) / 2;
        if (v->conteudo[meio] == chave)
            return 1;
        else if (chave > v->conteudo[meio])
            i = meio + 1;
        else
            j = meio - 1;
    }
    return 0;
}

int ElementoPresenteVetor(Vetor *vet) {
    int posicao = rand() % vet->tamanho;
    return vet->conteudo[posicao];
}


static void QuickSortR(Vetor *v, int inicio, int fim) {
    if (inicio >= fim) return;

    int i = inicio, j = fim;
    int pivot = v->conteudo[(inicio + fim) / 2];
    int temp;

    while (i <= j) {
        while (v->conteudo[i] < pivot) i++;
        while (v->conteudo[j] > pivot) j--;
        if (i <= j) {
            temp = v->conteudo[i];
            v->conteudo[i] = v->conteudo[j];
            v->conteudo[j] = temp;
            i++;
            j--;
        }
    }
    QuickSortR(v, inicio, j);
    QuickSortR(v, i, fim);
}

void QuickSort(Vetor *v) {
    if (v->tamanho <= 1) return;
    QuickSortR(v, 0, v->tamanho - 1);
}
