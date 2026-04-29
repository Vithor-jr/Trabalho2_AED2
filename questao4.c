#include <stdio.h>
#include <time.h>

#include "AVL/AVL.h"

#define tam 1000000

clock_t Timer_start() {
    return clock();
}

double Timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

int main() {

    for(int j = 0; j < 10; j++) {
        AVL avl;
        Timer_start();
        criarAVL(&avl);


        for(int i = 1; i <= tam; i++) {
            int valor = rand() % tam;

            inserirAVL(&avl, valor);
        }
    }


}