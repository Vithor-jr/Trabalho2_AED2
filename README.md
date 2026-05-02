# Trabalho 2 - Algoritmos e Estruturas de Dados 2

## Descrição

Este trabalho, proposto pela disciplina de Algoritmos e Estruturas de Dados 2 da Universidade Federal do Amazonas (UFAM), tem como objetivo consolidar os conhecimentos sobre árvores binárias, incluindo árvores binárias de pesquisa (BST) e árvores AVL.

O projeto envolve a implementação de diferentes estruturas de dados utilizando o conceito de Tipos Abstratos de Dados (TAD), além da análise de desempenho em operações de inserção e busca.

## Estrutura
O projeto está organizado em módulos, seguindo o conceito de TAD (Tipo Abstrato de Dados):

```
bash

Trabalho2_AED2
|   main.c
|   README.md
|
+---ArvBin
|       arvBin.c
|       arvBin.h
|
+---AVL
|       AVL.c
|       AVL.h
|
+---Pacote
|   |   pacote.c
|   |   pacote.h
|   |
|   \---ArvorePacote
|           arvorePacote.c
|           arvorePacote.h
|
+---Timer
|       timer.c
|       timer.h
|
\---Vetor
        Vetor.c
        Vetor.h
```

Descrição dos módulos

- **ArvBin/**  
  Implementação da Árvore Binária de Pesquisa (BST), incluindo inserção, busca e caminhamentos.

- **AVL/**  
  Implementação da Árvore AVL (árvore balanceada), com operações de rotação, inserção e busca.

- **Pacote/**  
  Estruturas e funções relacionadas à simulação de pacotes de rede.

- **Pacote/ArvorePacote/**  
  Implementação de uma árvore binária para organização dos pacotes recebidos.

- **Timer/**  
  Responsável pela medição de tempo de execução dos algoritmos.

- **Vetor/**  
  Implementação de vetor com suporte à busca binária (reaproveitado do Trabalho 1).

- **main.c**  
  Arquivo principal que executa os testes e integra todos os módulos.

---

## Como executar

### Pré-requisitos

- Compilador C (GCC recomendado)
- Sistema operacional Windows, Linux ou WSL

### Compilação

No terminal, navegue até a pasta do projeto e execute:

```bash
gcc main.c ArvBin/arvBin.c AVL/AVL.c Pacote/pacote.c Pacote/ArvorePacote/arvorePacote.c Timer/timer.c Vetor/Vetor.c -o trabalho2
```
### Exexcução

```bash
./trabalho2
```

### Autor(es)

Luiggy Augusto Lima Alves

Manfred Lima Veiga

Maria Flach da Costa

Vithor Júnior da Encarnação Vitório