#include <stdio.h>
#include <stdlib.h>

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
    
    //3.2- navio horizontal em C5-D5-E5 {(5,2), (5,3), (5,4)}
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
     
    
    // Nível Mestre - Habilidades Especiais com Matrizes
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

    // 1- criar 3 matrizes de habilidades
    int centro = 2; //centro das habilidades
    //1.1- CONE
    int cone[3][5];
    for (int i=0; i<3; i++){
        for (int j=0; j<5; j++){
            //formula para cone = abs(j-centro) <= i && i<3
            if (abs(j-centro) <= i && i<3){
                cone[i][j] = 1;
            } 
            else {
                cone[i][j] = 0;
            }
        } 
    }

    //1.2- CRUZ
    int cruz[5][5];
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            //formula para cruz = i == centro || j == centro
            if (i == centro || j == centro){
                cruz[i][j] = 1;
            } 
            else {
                cruz[i][j] = 0;
            }
        } 
    }
    
    
    //1.3- OCTAEDRO
    int octaedro[5][5];
    int raioDoOctaedro = 2;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            //formula para octaedro = abs(i - centro) + abs(j - centro) <= raioDoOctaedro
            if (abs(i - centro) + abs(j - centro) <= raioDoOctaedro){
                octaedro[i][j] = 1;
            } 
            else {
                octaedro[i][j] = 0;
            }
        } 
    }
    
    //2- exibir tabuleiro APENAS NAVIOS
    printf("===== TABULEIRO COM NAVIOS ===== \n");
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

    //3- integrar habilidades no tabuleiro
    int coneL = 3;
    int coneC = 1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int l = coneL + i;
                int c = coneC + j - centro;
                
                if (l >= 0 && l < LINHASTABULEIRO &&
                    c >= 0 && c < COLUNASTABULEIRO &&
                    tabuleiro[l][c] == 0) {
                        tabuleiro[l][c] = 5;
                    }
                }
            }
        }
        
    //3.1- CONE em B4 -> (linha 3, coluna 1)
    printf("\n===== TABULEIRO COM HABILIDADES ===== \n");
    printf("===== CONE EM B4 ===== \n");

    //3.1.1- imprimindo cabeçalho
    printf("-- ");
    for (int i=0; i<COLUNASTABULEIRO; i++)
    {
        printf("%c ", cabeçalho[i]);
    }
    printf("\n");

    //3.1.2- imiprimindo tabuleiro
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

    //3.2- CRUZ em D6 -> (linha 5, coluna 3)
    int cruzL = 5;
    int cruzC = 3;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int l = cruzL + i - centro;
                int c = cruzC + j - centro;

                if (l >= 0 && l < LINHASTABULEIRO &&
                    c >= 0 && c < COLUNASTABULEIRO &&
                    tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 5;
                }
            }
        }
    }
    
    printf("\n===== CRUZ EM D6 ===== \n");
    //3.2.1- imprimindo cabeçalho
    printf("-- ");
    for (int i=0; i<COLUNASTABULEIRO; i++)
    {
        printf("%c ", cabeçalho[i]);
    }
    printf("\n");
    
    //3.2.2- imiprimindo tabuleiro
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
    
    //3.3- OCTAEDRO em E4 -> (linha 3, coluna 4)
    int octL = 3;
    int octC = 4;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int l = octL + i - centro;
                int c = octC + j - centro;
                
                if (l >= 0 && l < LINHASTABULEIRO &&
                    c >= 0 && c < COLUNASTABULEIRO &&
                    tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 5;
                }
            }
        }
    }
    
    printf("\n===== OCTAEDRO EM E4 ===== \n");
    //3.2.1- imprimindo cabeçalho
    printf("-- ");
    for (int i=0; i<COLUNASTABULEIRO; i++)
    {
        printf("%c ", cabeçalho[i]);
    }
    printf("\n");
    
    //3.2.2- imiprimindo tabuleiro
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
    
    //4- exibir tabuleiro DEPOIS DAS HABILIDADES
    //4.1- imprimindo cabeçalho
    printf("\n\n===== TABULEIRO DEPOIS DAS HABILIDADES ===== \n");
    printf("-- ");
    for (int i=0; i<COLUNASTABULEIRO; i++)
    {
        printf("%c ", cabeçalho[i]);
    }
    printf("\n");

    //4.2- imiprimindo tabuleiro
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

    return 0;
}
