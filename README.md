# Thread Counter Competition

Este é um programa de contagem que cria uma competição entre várias threads, onde cada thread tenta ser a primeira a atingir uma contagem de `100`. O programa foi desenvolvido em C para rodar em sistemas Windows e demonstra o uso de threads, variáveis compartilhadas e sincronização.

## Descrição do Programa

O programa cria `10` threads (configurável), e cada thread possui sua própria contagem interna. Cada thread incrementa seu valor de contagem até atingir `100`, e o objetivo é identificar qual thread consegue atingir esse valor primeiro. Uma vez que a primeira thread atinge `100`, ela é registrada como vencedora, mas todas as threads continuam incrementando até completar `100` para mostrar o progresso.

### Recursos

- **Competição entre Threads**: Cada thread conta independentemente até `100`.
- **Identificação do Vencedor**: O programa marca qual thread foi a primeira a atingir `100`.
- **Medição de Tempo**: O tempo gasto pela thread vencedora para alcançar `100` é registrado e exibido.
- **Exibição do Progresso**: Cada thread exibe sua contagem a cada incremento para que o usuário acompanhe o progresso.

## Estrutura dos Arquivos

- **main.c**: Arquivo principal que inicializa a contagem e chama as funções do módulo `counter`.
- **counter.c**: Implementa as funções de contagem e a lógica de competição entre threads.
- **counter.h**: Cabeçalho que declara as funções de `counter.c`.

## Como Compilar e Rodar o Programa

Para compilar o programa em um sistema Windows com `gcc`, use o seguinte comando no PowerShell:

```powershell
gcc main.c counter.c -o counter_app -lwinmm

Para executar o programa em um sistema Windows com 'gcc', use o seguinte comando no PowerShell:

./counter_app
