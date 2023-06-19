#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char gameBoard[5][5] = {
    {' ', '|', ' ', '|', ' '},
    {'-', '+', '-', '+', '-'},
    {' ', '|', ' ', '|', ' '},
    {'-', '+', '-', '+', '-'},
    {' ', '|', ' ', '|', ' '}};

void welcomeScreen();
void mainMenu();
void printBoard(char gameBoard[5][5]);
void placeMove(char gameBoard[5][5], int position, char sign);
bool isFreeSpaceAvailable(char gameBoard[5][5], int position);
bool checkWin(char gameBoard[5][5], char sign);
bool isGameOver(char gameBoard[5][5]);
void singlePlayer();
void twoPlayer();
void decidePlayMode();
void playGame();
int playerOneTurn();
int playerTwoTurn();
int computerTurn();

void clearScreen();
void exitGame();

void welcomeScreen()
{
    clearScreen();
    printf("\n\n\n");
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               | Welcome To The Game |           #\n");
    printf("\t\t#               |        Of           |           #\n");
    printf("\t\t#               |    TIC TAC TOE      |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                      Press                      #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  1 to Start The Game        #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  0 to exit the Game         #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");

    char option;
    printf("\t\t\t\t--->: ");
    option = getch();
    option -= 48;
    printf("\n\n\n");
    if (option == 1)
    {
        mainMenu();
    }
    else if (option == 0)
    {
        exitGame();
    }
    else
    {
        printf("Invalid Option");
        welcomeScreen();
    }
}

void printBoard(char gameBoard[5][5])
{
    clearScreen();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void placeMove(char gameBoard[5][5], int position, char sign)
{
    switch (position)
    {
    case 1:
        gameBoard[0][0] = sign;
        return;
    case 2:
        gameBoard[0][2] = sign;
        return;
    case 3:
        gameBoard[0][4] = sign;
        return;
    case 4:
        gameBoard[2][0] = sign;
        return;
    case 5:
        gameBoard[2][2] = sign;
        return;
    case 6:
        gameBoard[2][4] = sign;
        return;
    case 7:
        gameBoard[4][0] = sign;
        return;
    case 8:
        gameBoard[4][2] = sign;
        return;
    case 9:
        gameBoard[4][4] = sign;
        return;
    default:
        printf("Invaild Choice:");
    }
}

bool isFreeSpaceAvailable(char gameBoard[5][5], int position)
{
    switch (position)
    {
    case 1:
        if (gameBoard[0][0] == ' ')
            return true;
        else
            return false;
    case 2:
        if (gameBoard[0][2] == ' ')
            return true;
        else
            return false;
    case 3:
        if (gameBoard[0][4] == ' ')
            return true;
        else
            return false;
    case 4:
        if (gameBoard[2][0] == ' ')
            return true;
        else
            return false;
    case 5:
        if (gameBoard[2][2] == ' ')
            return true;
        else
            return false;
    case 6:
        if (gameBoard[2][4] == ' ')
            return true;
        else
            return false;
    case 7:
        if (gameBoard[4][0] == ' ')
            return true;
        else
            return false;
    case 8:
        if (gameBoard[4][2] == ' ')
            return true;
        else
            return false;
    case 9:
        if (gameBoard[4][4] == ' ')
            return true;
        else
            return false;
    default:
        false;
    }
}

bool checkWin(char gameBoard[5][5], char sign)
{
    if ((gameBoard[0][0] == sign && gameBoard[0][2] == sign && gameBoard[0][4] == sign) ||
        (gameBoard[2][0] == sign && gameBoard[2][2] == sign && gameBoard[2][4] == sign) ||
        (gameBoard[4][0] == sign && gameBoard[4][2] == sign && gameBoard[4][4] == sign) ||

        (gameBoard[0][0] == sign && gameBoard[2][0] == sign && gameBoard[4][0] == sign) ||
        (gameBoard[0][2] == sign && gameBoard[2][2] == sign && gameBoard[4][2] == sign) ||
        (gameBoard[0][4] == sign && gameBoard[2][4] == sign && gameBoard[4][4] == sign) ||

        (gameBoard[0][0] == sign && gameBoard[2][2] == sign && gameBoard[4][4] == sign) ||
        (gameBoard[0][4] == sign && gameBoard[2][2] == sign && gameBoard[4][0] == sign))
        return true;

    return false;
}

bool isGameOver(char gameBoard[5][5]) 
{
    if (checkWin(gameBoard, 'X') || checkWin(gameBoard, 'O'))
        return true;
    for (int i = 1; i <= 9; i++)
    {
        if (isFreeSpaceAvailable(gameBoard, i))
            return false;
    }

    return true;   
}

int computerTurn()
{
    while (true)
    {
        srand(time(0));
        int position = rand() % 9 + 1;
        if (isFreeSpaceAvailable(gameBoard, position))
        {
            return position;
        }
    }
}

int playerOneTurn()
{
    while (true)
    {
        int position;
        printf("Player 1 Turn: \n");
        printf("Choose The Position between 1 to 9: \n");
        printf("Enter Position: ");
        scanf("%d", &position);
        if (isFreeSpaceAvailable(gameBoard, position))
        {
            return position;
        }
        else
        {
            printf("Invalid Position\n");
        }
    }
}

int playerTwoTurn()
{
    while (true)
    {
        int position;
        printf("Player 2 Turn: \n");
        printf("Choose The Position between 1 to 9: \n");
        printf("Enter Position: ");
        scanf("%d", &position);
        if (isFreeSpaceAvailable(gameBoard, position))
        {
            return position;
        }
        else
        {
            printf("Invalid Position\n");
        }
    }
}

void clearScreen()
{
    system("cls");
}

void exitGame()
{
    exit(0);
}

int main()
{
}