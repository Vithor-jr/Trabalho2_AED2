#include "stdio.h"
#include "pacote.h"

Pacote criarPacote(int id, char conteudo) {
    Pacote pacote;
    pacote.id = id;
    pacote.conteudo = conteudo;
    return pacote;
}

int compararPacotes(Pacote pacote1, Pacote pacote2){

    if( pacote1.id <pacote2.id){

        return -1;
    }
    else if( pacote1.id >pacote2.id){

        return 1;
    }
    else{

        return 0;
    }
}

void gravarPacoteEmArquivo(Pacote pacote, FILE *arquivo) {
    
    if(arquivo != NULL){
        fputc(pacote.conteudo, arquivo);
    }
}
