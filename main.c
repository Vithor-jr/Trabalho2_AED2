#include <stdio.h>
#include <stdlib.h>

#include "ArvBin/arvBin.h"
#include "Vetor/Vetor.h"
#include "Timer/timer.h"
#include "ArvBin/arvBin.h"
#include "AVL/AVL.h"

#include <time.h>
#define TAM 1000000

void questao1 () {
		tipoArv Arvore;
		Vetor vet;

		vet = CriarVetor(20);
		
		inicializarArvore(&Arvore);
		PreencherVetorDesordenado(&vet);
		for (int i=0; i<20; i++){
				inserirElemento(&Arvore, vet.conteudo[i]);
		}
		
		printf("\n======== Estrutura da Arvore ========\n");

	  mostrarArvore(&Arvore);

		tipoNo* aux = Arvore.raiz;
		printf("\n\n======== Caminhamento ========\n");
		printf("Pre-Ordem: ");
		preOrdem(aux);
		printf("\n");
		printf("Em-Ordem: ");
		emOrdem(aux);
		printf("\n");
		printf("Pos-Ordem: ");
		posOrdem(aux);
		printf("\n\n");

		LiberarVetor(&vet);
}

void questao2 () {
}

void questao3 () {
	tipoArv Arvore;
	Vetor vet;
	Vetor valoresBusca;

	vet = CriarVetor(TAM);
	valoresBusca = CriarVetor(30);

	inicializarArvore(&Arvore);
	PreencherVetorDesordenado(&vet);

	for (int i = 0; i < TAM; i++) {
			inserirElemento(&Arvore, vet.conteudo[i]);
	}
	
	for (int i = 0; i < 15; i++) {
			valoresBusca.conteudo[i] = ElementoPresenteVetor(&vet);
			valoresBusca.conteudo[i + 15] = rand() % (TAM*10);          
	}
	for (int i = 0; i < 15; i++) {
    valoresBusca.conteudo[i] = ElementoPresenteVetor(&vet);
    
    if (rand() % 2 == 0) {     
        valoresBusca.conteudo[i + 15] = ElementoPresenteVetor(&vet);
    } else {
        valoresBusca.conteudo[i + 15] = TAM*10 + rand() % 1000; 
    }
}


	QuickSort(&vet);

	double temposVetor[30], temposArv[30];
	double somaTemposVetor, somaTemposArv;
	int statusArvore, statusVetor;

	printf("\n======== RESULTADOS ========\n\n");
	printf("|=============================================================================|\n");
	printf("| Busca |      BUSCA NA ARVORE      |   BUSCA BINARIA NO VETOR   |   STATUS   |\n");
	printf("|=======|===========================|============================|============|\n");
	
	for (int i = 0; i < 30; i++) {
			clock_t inicio = Timer_start();
			statusArvore = buscarElemento(&Arvore, valoresBusca.conteudo[i]);
			temposArv[i] = Timer_stop(inicio);
			somaTemposArv += temposArv[i];

			inicio = Timer_start();
			statusVetor = BuscaBinaria(&vet, valoresBusca.conteudo[i]);
			temposVetor[i] = Timer_stop(inicio);
			somaTemposVetor += temposVetor[i];
			
			if(i<9){
				printf("|   %d   |       %.12lf      |       %.12lf       |      %d     |\n", i+1, temposArv[i], temposVetor[i], statusArvore);	
			} else {
				printf("|  %d   |       %.12lf      |       %.12lf       |      %d     |\n", i+1, temposArv[i], temposVetor[i],statusVetor);	
			}
		}
		printf("|=============================================================================|\n");
		printf("| MEDIA |       %.12lf      |       %.12lf       |            |\n", somaTemposArv/30.0, somaTemposVetor/30.0);
		printf("|=============================================================================|\n");


}

void questao4 () {
	double tempoCriacaoBin[10], tempoCriacaoAVL[10], tempoMedioBuscaBin[10], tempoMedioBuscaAVL[10];

  for(int j = 0; j < 10; j++) {
        tipoArv bin;
        AVL avl;
        double tempoBin, tempoAVL;

        clock_t inicio = Timer_start();
        inicializarArvore(&bin);
        tempoBin = Timer_stop(inicio);
        inicio = Timer_start();
        criarAVL(&avl);
        tempoAVL = Timer_stop(inicio);

        for(int i = 1; i <= TAM; i++) {
            int valor = rand() % TAM;

            inicio = Timer_start();
            inserirElemento(&bin, valor);
            tempoBin += Timer_stop(inicio);
            inicio = Timer_start();
            inserirAVL(&avl, valor);
            tempoAVL += Timer_stop(inicio);
        }
        tempoCriacaoBin[j] = tempoBin;
        tempoCriacaoAVL[j] = tempoAVL;

        printf("---------------RODADA %d------------------: \n", j+1);
        printf("TEMPO DE CRIAÇÃO DA ABP: %f s\n", tempoBin);
        printf("TEMPO DE CRIAÇÃO DA AVL: %f s\n", tempoAVL);
        printf("ALTURA DA ABP: %d \n", alturaABP(bin.raiz));
        printf("ALTURA DA AVL: %d \n", alturaDoNo(avl.raiz));

        tempoBin = 0; tempoAVL = 0;

        for(int i = 1; i <= 30; i++) {
            int valor = rand() % TAM;

            inicio = Timer_start();
            unsigned buscaBin = buscarElemento(&bin, valor);
            tempoBin += Timer_stop(inicio);

            inicio = Timer_start();
            char buscaAVL = buscarAVL(&avl, valor);
            tempoAVL += Timer_stop(inicio);
        }
        tempoMedioBuscaBin[j] = tempoBin/30;
        tempoMedioBuscaAVL[j] = tempoAVL/30;
        printf("TEMPO MÉDIO DE BUSCA NA ABP: %f s \n", tempoMedioBuscaBin[j]);
        printf("TEMPO MÉDIO DE BUSCA NA AVL: %f s \n", tempoMedioBuscaAVL[j]);
    }

	printf("RESULTADOS FINAIS: \n");
	double criacaoBin = 0, criacaoAVL = 0, buscaBin = 0, buscaAVL = 0;
	for(int i = 0; i < 10; i++) {
			criacaoBin += tempoCriacaoBin[i];
			criacaoAVL += tempoCriacaoAVL[i];
			buscaBin += tempoMedioBuscaBin[i];
			buscaAVL += tempoMedioBuscaAVL[i];
	}
	criacaoBin /= 10; criacaoAVL /= 10; buscaBin /= 10; buscaAVL /= 10;
	printf("TEMPO MÉDIO DE CRIAÇÃO DA ABP: %f s \n", criacaoBin);
	printf("TEMPO MÉDIO DE CRIAÇÃO DA AVL: %f s \n", criacaoAVL);
	printf("TEMPO MÉDIO DE BUSCA NA ABP: %f s \n", buscaBin);
	printf("TEMPO MÉDIO DE BUSCA NA AVL: %f s \n", buscaAVL);
}

int main(){
	srand(time(NULL));

	printf("********* QUESTAO 1 *********");
  questao1();

	printf("\n\n********* QUESTAO 3 *********\n");
  questao3();

	printf("\n\n********* QUESTAO 4 *********\n");
  questao4();

	return 0;
}