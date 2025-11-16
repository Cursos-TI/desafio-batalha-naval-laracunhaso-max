#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10];
    int i, j;
    
    // Inicializar tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    printf("=== BATALHA NAVAL - POSICIONAMENTO DE NAVIOS ===\n\n");
    
    // 1. POSICIONAR NAVIO HORIZONTAL (linha 2, coluna 1)
    printf("Posicionando navio horizontal na linha 2, coluna 1...\n");
    int posicaoValida = 1;
    
    // Verificar se cabe no tabuleiro
    if (1 + 3 <= 10) { // coluna inicial + tamanho navio
        // Verificar sobreposição
        for (j = 1; j < 4; j++) {
            if (tabuleiro[2][j] != 0) {
                posicaoValida = 0;
                break;
            }
        }
        
        // Posicionar navio
        if (posicaoValida) {
            for (j = 1; j < 4; j++) {
                tabuleiro[2][j] = 3;
            }
            printf("Navio horizontal posicionado com sucesso!\n");
        } else {
            printf("Erro: Sobreposição de navios!\n");
        }
    } else {
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
    }
    
    // 2. POSICIONAR NAVIO VERTICAL (linha 0, coluna 8)
    printf("Posicionando navio vertical na linha 0, coluna 8...\n");
    posicaoValida = 1;
    
    // Verificar se cabe no tabuleiro
    if (0 + 3 <= 10) { // linha inicial + tamanho navio
        // Verificar sobreposição
        for (i = 0; i < 3; i++) {
            if (tabuleiro[i][8] != 0) {
                posicaoValida = 0;
                break;
            }
        }
        
        // Posicionar navio
        if (posicaoValida) {
            for (i = 0; i < 3; i++) {
                tabuleiro[i][8] = 3;
            }
            printf("Navio vertical posicionado com sucesso!\n");
        } else {
            printf("Erro: Sobreposição de navios!\n");
        }
    } else {
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
    }
    
    // 3. POSICIONAR NAVIO DIAGONAL PRINCIPAL (linha 5, coluna 5)
    printf("Posicionando navio diagonal principal na linha 5, coluna 5...\n");
    posicaoValida = 1;
    
    // Verificar se cabe no tabuleiro (linha e coluna aumentam juntas)
    if (5 + 3 <= 10 && 5 + 3 <= 10) {
        // Verificar sobreposição
        for (i = 0; i < 3; i++) {
            if (tabuleiro[5 + i][5 + i] != 0) {
                posicaoValida = 0;
                break;
            }
        }
        
        // Posicionar navio
        if (posicaoValida) {
            for (i = 0; i < 3; i++) {
                tabuleiro[5 + i][5 + i] = 3;
            }
            printf("Navio diagonal principal posicionado com sucesso!\n");
        } else {
            printf("Erro: Sobreposição de navios!\n");
        }
    } else {
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
    }
    
    // 4. POSICIONAR NAVIO DIAGONAL SECUNDÁRIA (linha 1, coluna 8)
    printf("Posicionando navio diagonal secundaria na linha 1, coluna 8...\n");
    posicaoValida = 1;
    
    // Verificar se cabe no tabuleiro (linha aumenta, coluna diminui)
    if (1 + 3 <= 10 && 8 - 2 >= 0) {
        // Verificar sobreposição
        for (i = 0; i < 3; i++) {
            if (tabuleiro[1 + i][8 - i] != 0) {
                posicaoValida = 0;
                break;
            }
        }
        
        // Posicionar navio
        if (posicaoValida) {
            for (i = 0; i < 3; i++) {
                tabuleiro[1 + i][8 - i] = 3;
            }
            printf("Navio diagonal secundaria posicionado com sucesso!\n");
        } else {
            printf("Erro: Sobreposição de navios!\n");
        }
    } else {
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
    }
    
    // EXIBIR TABULEIRO FINAL
    printf("\n=== TABULEIRO FINAL ===\n");
    
    // Cabeçalho com números das colunas
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Linha separadora
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("---");
    }
    printf("\n");
    
    // Conteúdo do tabuleiro com números das linhas
    for (i = 0; i < 10; i++) {
        printf("%2d|", i);
        for (j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    // Legenda
    printf("\nLegenda:\n");
    printf("0 - Água\n");
    printf("3 - Navio\n");
    

    return 0;
}
