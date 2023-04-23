#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

// char board[3][3] = {
//     {' ', ' ', ' '},
//     {' ', ' ', ' '},
//     {' ', ' ', ' '},
// };

// char PLAYER = 'X';
// char COMP = 'O';
// int MOVES = 0;
// int REMAINING_POS = 9;

void print_board(char[3][3]);
char check_winner(char[3][3]);
void player_move(char[3][3], int *, int *);
void comp_move(char[3][3], int *);

int main()
{
    char PLAY_AGAIN = 'Y';
    do
    {
        char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '},
        };

        char PLAYER = 'X';
        char COMP = 'O';
        int MOVES = 0;
        int REMAINING_POS = 9;
        // lets play
        char WINNER = ' ';

        do
        {
            print_board(board);
            player_move(board, &MOVES, &REMAINING_POS);
            print_board(board);
            if (MOVES > 2)
            {
                WINNER = check_winner(board);
                // printf("\nCurr winner: %c\n", winner);
            }
            if (WINNER != ' ')
                break;
            comp_move(board, &REMAINING_POS);
            print_board(board);

        } while (WINNER == ' ');
        if (WINNER == 'X')
            printf("You won!");
        else if (WINNER == 'O')
            printf("Computer won!");
        else if (REMAINING_POS == 0)
            printf("DEAD BOARD\n");

        printf("\nDo you want to play again? (Y or N): ");
        scanf(" %c", &PLAY_AGAIN);
    } while (PLAY_AGAIN == 'Y');

    return 0;
}

void print_board(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("---|---|---\n");
    }
}

char check_winner(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }

        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[i][0];
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return board[0][0];

    return ' ';
}

void player_move(char board[3][3], int *move, int *rem)
{
    printf("\nPLAYER MOVE\n");
    int row, col;
    do
    {
        do
        {
            printf("Select row (1-3): ");
            scanf("%d", &row);
        } while (row > 3 || row < 1);

        do
        {
            printf("Select col (1-3): ");
            scanf("%d", &col);
        } while (col > 3 || col < 1);

        if (board[row - 1][col - 1] != ' ')
        {
            printf("Position not empty, try again!");
        }

    } while (*rem > 0 && board[row - 1][col - 1] != ' ');

    board[row - 1][col - 1] = 'X';
    *move += 1;
    *rem -= 1;
}

void comp_move(char board[3][3], int *rem)
{
    printf("\nCOMP MOVE\n");

    srand(time(0));
    int row, col;

    if (*rem > 0)
    {
        do
        {
            row = 1 + rand() % 3;
            col = 1 + rand() % 3;

        } while (board[row - 1][col - 1] != ' ');

        board[row - 1][col - 1] = 'O';

        *rem -= 1;
    }
}
