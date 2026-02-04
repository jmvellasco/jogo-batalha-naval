#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1. Inicializar o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Criar e posicionar os navios (valor 3)
    // Navio 1: Horizontal
    int linha = 2, coluna = 4;
    for (i = 0; i < 3; i++)
        tabuleiro[linha][coluna + i] = 3;

    // Navio 2: Vertical
    linha = 5; coluna = 3;
    for (i = 0; i < 3; i++)
        tabuleiro[linha + i][coluna] = 3;

    // Navio 3: Diagonal principal (↘️)
    linha = 1; coluna = 1;
    for (i = 0; i < 3; i++)
        tabuleiro[linha + i][coluna + i] = 3;

    // Navio 4: Diagonal secundária (↙️)
    linha = 4; coluna = 6;
    for (i = 0; i < 3; i++)
        tabuleiro[linha + i][coluna - i] = 3;

    // 3. Criar matrizes de habilidades (0 = fora, 1 = dentro)
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // --- Cone ---
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // --- Cruz ---
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // --- Octaedro (losango) ---
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // 4. Aplicar as habilidades no tabuleiro (somente onde há navio)
    // Definindo posições de origem
    int origemConeLinha = 2, origemConeColuna = 4;
    int origemCruzLinha = 5, origemCruzColuna = 3;
    int origemOctLinha  = 4, origemOctColuna  = 6;

    // Função de sobreposição genérica inline
    for (int tipo = 0; tipo < 3; tipo++) {
        int (*habilidade)[TAM_HAB];
        int origemLinha, origemColuna;

        if (tipo == 0) { habilidade = cone; origemLinha = origemConeLinha; origemColuna = origemConeColuna; }
        else if (tipo == 1) { habilidade = cruz; origemLinha = origemCruzLinha; origemColuna = origemCruzColuna; }
        else { habilidade = octaedro; origemLinha = origemOctLinha; origemColuna = origemOctColuna; }

        for (i = 0; i < TAM_HAB; i++) {
            for (j = 0; j < TAM_HAB; j++) {
                if (habilidade[i][j] == 1) {
                    int linhaTab = origemLinha + (i - TAM_HAB / 2);
                    int colunaTab = origemColuna + (j - TAM_HAB / 2);

                    if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                        if (tabuleiro[linhaTab][colunaTab] == 3)
                            tabuleiro[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }

    // 5. Exibir tabuleiro
    char colunaNome[10] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("   ");
    for (j = 0; j < TAM; j++) printf("%c ", colunaNome[j]);
    printf("\n");

    for (i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

