#include <stdio.h>

struct players
{
    int column, line;
} typedef player;

void printBoard(char Hash[3][3], int line, int column)
{

    printf("\n=========================================\n");

    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%c\t", Hash[i][j]);
        }
        printf("\n");
    }

    printf("\n=========================================\n");
}

void playerMove(char Hash[3][3], player player, char play)
{

    printf("player %c, insira a linha de sua jogada: \n", play);
    scanf("%d", &player.line);

    printf("Agora a coluna de sua jogada: \n");
    scanf("%d", &player.column);

    if (Hash[player.line][player.column] == '?')
    {
        Hash[player.line][player.column] = play;
    }
    else
    {
        printf("Ja possui uma jogada nessa posicao :(\n");
        printBoard(Hash, 3, 3);
        playerMove(Hash, player, play);
    }
}

char verifyDiagonal(char Hash[3][3])
{
    if (Hash[0][0] == Hash[1][1] && Hash[1][1] == Hash[2][2])
    {
        return Hash[0][0];
    }

    if (Hash[2][0] == Hash[1][1] && Hash[1][1] == Hash[0][2])
    {
        return Hash[2][0];
    }

    return '?';
}

char verifyColumn(char Hash[3][3])
{
    for (int coluna = 0; coluna < 3; coluna++)
    {
        if (Hash[0][coluna] == Hash[1][coluna] && Hash[0][coluna] == Hash[2][coluna])
        {
            return Hash[0][coluna];
        }
    }
    return '?';
}

char verifyLine(char Hash[3][3])
{
    for (int coluna = 0; coluna < 3; coluna++)
    {
        if (Hash[coluna][0] == Hash[coluna][1] && Hash[coluna][0] == Hash[coluna][2])
        {
            return Hash[coluna][0];
        }
    }
    return '?';
}

int verifyWin(char Hash[3][3])
{
    char winner = verifyLine(Hash);

    
    if (winner != '?')
    {
        printf("Jogador %c ganhou! =)", winner);
        return 0;
    }

    winner = verifyColumn(Hash);
    if (winner != '?')
    {
        printf("Jogador %c ganhou! =)", winner);
        return 0;
    }

    winner = verifyDiagonal(Hash);
    if (winner != '?')
    {
        printf("Jogador %c ganhou! =)", winner);
        return 0;
    }

    return 1;
}

int main()
{

    char Hash[3][3];

    player playerX, playerO;

    int count = 0;

    printf("### Comecando o Jogo =) ###\n\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Hash[i][j] = '?';
            printf("%c\t", Hash[i][j]);
        }
        printf("\n");
    }

    printf("\n=========================================\n");

    while (count < 6)
    {
        playerMove(Hash, playerX, 'X');
        printBoard(Hash, 3, 3);
        if (verifyWin(Hash) == 0)
            break;

        playerMove(Hash, playerO, 'O');
        printBoard(Hash, 3, 3);
        if (verifyWin(Hash) == 0)
            break;

        count++;
    }
    return 0;
}