# 🚢 Batalha Naval em C (Simulação com Matrizes)

Programa em linguagem C que simula um tabuleiro de **Batalha Naval** utilizando matrizes bidimensionais, com posicionamento fixo de navios e aplicação de **habilidades especiais** baseadas em padrões matriciais.

O foco do projeto é demonstrar domínio de **vetores e matrizes**, **loops aninhados** e **lógica de sobreposição em grids**.

---

## Visão Geral

O programa cria um tabuleiro 10x10 representando um jogo de Batalha Naval e executa as seguintes etapas:

- Inicialização do tabuleiro
- Posicionamento de navios em diferentes direções
- Criação de matrizes de habilidades especiais
- Aplicação dessas habilidades sobre os navios
- Exibição final do tabuleiro no terminal

Não há entrada de dados do usuário — todas as posições são definidas no código.

---

## Representação do Tabuleiro

- `0` → Água  
- `3` → Navio  
- `5` → Navio atingido por habilidade  

O tabuleiro é exibido com identificação de linhas e colunas para facilitar a leitura.

---

## Posicionamento dos Navios

O tabuleiro possui **quatro navios**, todos com tamanho 3:

- Navio horizontal
- Navio vertical
- Navio na diagonal principal
- Navio na diagonal secundária

Os navios são posicionados diretamente por coordenadas no código, utilizando laços de repetição.

---

## Habilidades Especiais

O programa implementa três habilidades especiais, cada uma representada por uma matriz 5x5:

### Cone
- Área de efeito em formato triangular
- Preenchida com lógica condicional baseada em índices

### Cruz
- Área de efeito em formato de cruz
- Afeta linha e coluna centrais da matriz

### Octaedro (Losango)
- Área de efeito em formato de losango
- Implementada utilizando distância de Manhattan

Cada habilidade é aplicada ao tabuleiro a partir de uma posição de origem e **só afeta células onde há navio**.

---

## Lógica de Aplicação das Habilidades

- As matrizes de habilidade são sobrepostas ao tabuleiro
- Apenas posições válidas dentro dos limites do tabuleiro são consideradas
- Caso a habilidade atinja uma célula com navio (`3`), ela é marcada como `5`

---

## Tecnologias Utilizadas

- Linguagem C
- Compilador GCC
- Terminal (CLI)
- Git e GitHub

---

## Conceitos Demonstrados

- Matrizes bidimensionais
- Loops aninhados
- Controle de limites de matriz
- Lógica de sobreposição em grids
- Organização e clareza de código

---

## Como Executar

```bash
gcc batalha_naval.c -o batalha_naval
./batalha_naval
