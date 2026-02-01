#include <stdio.h>

#define LINHASTABULEIRO 10
#define COLUNASTABULEIRO 10
#define TAMANHONAVIO 3

int main() {
    // Nível Novato - Posicionamento dos Navios
    //1- cabeçalho do tabuleiro
    char cabeçalho[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //2- criando o tabuleiro
    int tabuleiro[10][10];
    for (int i = 0; i < LINHASTABULEIRO; i++)
    {
        for (int j=0; j< COLUNASTABULEIRO; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //3- incluindo navios vertical e horizontal no tabuleiro
    //3.1- navio vertical em B3-B4-B5 {(2,1), (3,1), (4,1)}
    for (int i = 0; i < TAMANHONAVIO; i++)
    {
        tabuleiro[i+2][1] = 3;
    }
    
    //3.2- navio horizontal em C5{(5,2), (5,3), (5,4)}
    for (int i = 0; i < TAMANHONAVIO; i++)
    {
        tabuleiro[4][i+2] = 3;
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // 1- incluindo dois navios na diagonal
    //1.1- navio diagonal1 em F2-G3-H4 {(1,5), (2,6), (3,7)}
    for (int i=0; i< TAMANHONAVIO; i++)
    {
        //1.1.1- criando validação para imprimir mensagem caso exista peça !=0 na posição
        if (tabuleiro[i+1][i+5] != 0)
        {
            printf("Já existe uma peça na linha %d, coluna %d \n", i+1, i+5);
            break;
        }
        //1.1.2- incluindo validação para saber se peça está dentro dos limites do tabuleiro
        else if (i+1 > LINHASTABULEIRO || 5+i > COLUNASTABULEIRO)
        {
            printf("Linha %d, coluna %d excede o tamnaho do tabuleiro. \n", i+1, i+5);
            break;
        }
        //1.1.3- inclusão do navio caso não tenha peça na posição
        else {
            tabuleiro[i+1][i+5] = 3;
        }
    }
    
    //1.2- navio diagonal2 em F9-G8-H7 {(8,5), (7,6), (6,7)}
    for (int i=0; i< TAMANHONAVIO; i++)
    {
        //1.2.1- criando validação para imprimir mensagem caso exista peça !=0 na posição
        if (tabuleiro[8-i][5+i] != 0)
        {
            printf("Já existe uma peça na linha %d, coluna %d \n", 8-i, 5+i);
            break;
        }
        //1.2.2- incluindo validação para saber se peça está dentro dos limites do tabuleiro
        else if (8-i > LINHASTABULEIRO || 5+i > COLUNASTABULEIRO)
        {
            printf("Linha %d, coluna %d excede o tamnaho do tabuleiro. \n", 8-i, 5+i);
            break;
        }
        //1.2.3- inclusão do navio caso não tenha peça na posição
        else {
            tabuleiro[8-i][5+i] = 3;
        }
    }
     
    //2.1- imprimindo cabeçalho
    printf("-- ");
    for (int i=0; i<COLUNASTABULEIRO; i++)
    {
        printf("%c ", cabeçalho[i]);
    }
    printf("\n");

    //2.2- imiprimindo tabuleiro
    for (int i=0; i<LINHASTABULEIRO; i++)
    {
        //if-else para que a numeração das linhas fique estetica, com 2 espaços de 1-9 e um espaço na linha 10
        if(i==9){ printf("%d ", i+1);}
        else {printf("%d  ", i+1);}
        for (int j=0; j<COLUNASTABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
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

    return 0;
}
