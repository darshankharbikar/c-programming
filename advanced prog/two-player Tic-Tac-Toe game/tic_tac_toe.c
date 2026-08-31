#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int makeMove(char board[SIZE][SIZE], char player);
int checkWin(char board[SIZE][SIZE], char player);
int checkDraw(char board[SIZE][SIZE]);
void clearInputBuffer(void);

int main(void)
{
    char board[SIZE][SIZE];
    char player;
    char playAgain;

    do
    {
        initializeBoard(board);
        player = 'X';

        printf("\n===== TIC TAC TOE =====\n");

        while (1)
        {
            displayBoard(board);

            printf("\nPlayer %c's turn\n", player);

            if (!makeMove(board, player))
                continue;

            if (checkWin(board, player))
            {
                displayBoard(board);
                printf("\nPlayer %c wins!\n", player);
                break;
            }

            if (checkDraw(board))
            {
                displayBoard(board);
                printf("\nGame is a draw!\n");
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);
        clearInputBuffer();

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}

void initializeBoard(char board[SIZE][SIZE])
{
    char value = '1';

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = value++;
        }
    }
}

void displayBoard(char board[SIZE][SIZE])
{
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c  \n",
               board[i][0],
               board[i][1],
               board[i][2]);

        if (i != SIZE - 1)
            printf("_____|_____|_____\n");
    }

    printf("     |     |     \n");
}

int makeMove(char board[SIZE][SIZE], char player)
{
    int position;
    int row;
    int col;

    printf("Enter position (1-9): ");

    if (scanf("%d", &position) != 1)
    {
        printf("Invalid input. Enter a number from 1 to 9.\n");
        clearInputBuffer();
        return 0;
    }

    clearInputBuffer();

    if (position < 1 || position > 9)
    {
        printf("Invalid position. Choose 1-9.\n");
        return 0;
    }

    row = (position - 1) / SIZE;
    col = (position - 1) % SIZE;

    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        printf("Position already occupied. Choose another.\n");
        return 0;
    }

    board[row][col] = player;

    return 1;
}

int checkWin(char board[SIZE][SIZE], char player)
{
    /* Check rows */
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return 1;
        }
    }

    /* Check columns */
    for (int j = 0; j < SIZE; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return 1;
        }
    }

    /* Check main diagonal */
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return 1;
    }

    /* Check opposite diagonal */
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

int checkDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }

    return 1;
}

void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
