/*()()()()()()()()()()()()()()()()()()()()()()()()()()()()
  ()~C program by Nixon Pastor for CS1310               ()
  ()~This program allows two users to play Tic-Tac-Toe  ()
  ()()()()()()()()()()()()()()()()()()()()()()()()()()()())*/
#include <stdio.h>

char ttt[3][3]; /* tic tac toe board */
char player = 'X'; /* assigning X to player */
int i; /* index in array */
int j; /*index in array */
int moves; /* to count number of moves */
int user_input; /* storing user's input on key */
int win=0; /* not a win */

void clear_board() /* function that clears board */
{
    for (i=0; i<3; i++) /* row */
    {
        for (j=0; j<3; j++) /* column */
        {
            ttt[i][j] = ' '; /* free spot */
        }
    }
}

void print_board() /* printing boards function */
{

    printf("\n\n");
    printf("  ************* \n"); /* assinging the indexes */
    printf("  | %c | %c | %c |  \n", ttt[0][0], ttt[0][1], ttt[0][2]);
    printf("  *************  \n");
    printf("  | %c | %c | %c |  \n", ttt[1][0], ttt[1][1], ttt[1][2]);
    printf("  *************  \n");
    printf("  | %c | %c | %c |  \n", ttt[2][0], ttt[2][1], ttt[2][2]);
    printf("  ************* \n ");

    printf("\n");
    printf("    KEY     \n ");
    printf(" ************* \n");
    printf("  | 1 | 2 | 3 |  \n");
    printf("  *************  \n");
    printf("  | 4 | 5 | 6 |  \n");
    printf("  ************* \n");
    printf("  | 7 | 8 | 9 |  \n");
    printf("  ************* \n");
}



void get_user_move(void)
{
    do
    {
        do
        {
            printf("\nPlease type in a move 1-9: ");
            scanf("%i" , &user_input);
            printf("You chose placement: %i \n", user_input);
        } while (user_input < 1 || user_input > 9); /* user inputs 1-9 */

        switch (user_input) /* each case is an index on the board */
        {
            case 1:      /* top left spot on board */
                i=0;
                j=0;
                break;
            case 2:      /* middle spot top on board */
                i=0;
                j=1;
                break;
            case 3:	    /* top right corner board */
                i=0;
                j=2;
                break;
            case 4:       /* middle row left spot on board */
                i=1;
                j=0;
                break;
            case 5:       /* middle middle spot on board */
                i=1;
                j=1;
                break;
            case 6:       /* right spot on middele row */
                i=1;
                j=2;
                break;
            case 7:
                i=2;   /* bottom left spot on board */
                j=0;
                break;
            case 8:
                i=2;    /* middle spot on bottom row */
                j=1;
                break;
            case 9:
                i=2;
                j=2;  /*bottom right corner of board */
                break;
            default:
                printf("Error.");
        }
    } while(ttt[i][j] != ' '); /* while space is free */

}



void check_win(void) /* function to check win */
{        /* 8 options to check if win */
    if ((ttt[0][0]== player && ttt[0][1]== player && ttt[0][2]== player) ||
        (ttt[1][0]== player && ttt[1][1]== player && ttt[1][2]== player) ||
        (ttt[2][0]== player && ttt[2][1]== player && ttt[2][2]== player) ||
        (ttt[0][0]== player && ttt[1][1]== player && ttt[2][2]== player) ||
        (ttt[2][0]== player && ttt[1][1]== player && ttt[0][2]== player) ||
        (ttt[0][0]== player && ttt[1][0]== player && ttt[2][0]== player) ||
        (ttt[0][1]== player && ttt[1][1]== player && ttt[2][1]== player) ||
        (ttt[0][2]== player && ttt[1][2]== player && ttt[2][2]== player) )
    {
        printf("\n    %c WON!!!", player);
        moves=10; /* to get out of loop */
        win=1; /* a win */
        print_board(); /* function to print final move */
    }
    else if (moves == 9) /* other wise the number of moves is 9 to make tie */
    {
        printf("It is a tie.");
        win=1; /* a win */
        moves=10; /* to get out of loop */
        print_board(); /* function prints final move */
    }
}



void change_player() /*function that changes players */
{
    if (player == 'X') /* change player */
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}



void main(void)
{
    int play_again; /* stores play again */

    printf("Welcome to Tic-Tac-Toe. \n");
    printf("Play Tic-Tac-Toe to get 3 X's or O's in a row. \n");
    printf("You will choose a number 1-9 to select your spot.");

    do
    {
        clear_board(); /* function that clears board */
        moves=1; /* first move */

        /* while not win or moves < 9 it keeps playing */
        while (win == 0 || moves < 9)
        {
            print_board(); /*function that prints board */
            moves++; /*incrementing moves */
            get_user_move(); /*getting user's input */
            ttt[i][j]= player; /* assigning X to indexes */
            check_win(); /*function to check if there's a win */
            change_player(); /*changes players X or O */
        }

        printf("\nWould you like to play again?");
        printf("\nEnter 1 for Yes or any other number for No: ");
        scanf("%i" , &play_again); /* getting user's input to play again */
        printf("\nYou chose: %i", play_again);
    } while (play_again == 1); /* while loop to play again */


}