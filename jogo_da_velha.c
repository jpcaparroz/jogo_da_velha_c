#include <stdio.h>

struct players
{
    int column, line;
} typedef player;

void printBoard(char Hash[3][3], int line, int column)
{

    printf("\n=========================================\n\n");

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

    printf("\nplayer %c, insira a linha de sua jogada: \n", play);
    scanf("%d", &player.line);

    printf("\nAgora a coluna de sua jogada: \n");
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
    for (int line = 0; line < 3; line++)
    {
        if (Hash[line][0] == Hash[line][1] && Hash[line][0] == Hash[line][2])
        {
            return Hash[line][0];
        }
    }
    return '?';
}

char verifyTie(char Hash[3][3])
{ 
    int test, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (Hash[i][j] != '?')
            {
                test++;
            } 
        }
    }
    if (test == 12)
    {
        return Hash[2][2];
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

    winner = verifyTie(Hash);
    if (winner != '?')
    {
        printf("DEU VELHA!!!", winner);
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

    while (count < 5)
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