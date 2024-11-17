# Contador de Threads em C

Este projeto é um exemplo de contagem utilizando threads em C, com objetivo de demonstrar a modularização do código com alta coesão e baixo acoplamento. O programa cria múltiplas threads para incrementar uma contagem até um valor máximo definido pelo usuário.

## Estrutura do Projeto

- **main.c**: Arquivo principal que configura e inicia a contagem.
- **counter.c**: Contém a implementação das funções responsáveis pela contagem e gerenciamento de threads.
- **counter.h**: Cabeçalho que declara as funções públicas do módulo `counter`.
- **Makefile**: Define os comandos de compilação e limpeza do projeto.

## Como Compilar

Para compilar o projeto, você precisará do `gcc` e de suporte à biblioteca `pthread`.

1. Abra o terminal na pasta do projeto.
2. Execute o comando `make` para compilar o programa.

```bash
make
