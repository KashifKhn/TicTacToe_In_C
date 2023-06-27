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
void singlePlayerMode();
void SinglePlayerTurn(char sign);
void computerTurn(char sign);
void multiPlayerMode();
void playerOneTurn(char sign);
void playerTwoTurn(char sign);
void choosePlayerSign(char *playerSign, char *ComputerSign);
void printBoard(char gameBoard[5][5]);
void restBoard(char gameBoard[5][5]);
void placeMove(char gameBoard[5][5], int position, char sign);
bool isFreeSpaceAvailable(char gameBoard[5][5], int position);
bool checkWin(char gameBoard[5][5], char sign);
bool isGameOver(char gameBoard[5][5], char sign1, char sign2);
void winingMessage(char sign);
void drawMessage();
void playAgain();
void clearScreen();
void exitGame();

void welcomeScreen()
{
    clearScreen();
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
        mainMenu();
    else if (option == 0)
        exitGame();
    else
    {
        printf("Invalid Option");
        welcomeScreen();
    }
}

void mainMenu()
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |    TIC TAC TOE      |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                      Press                      #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  1 - Single Player          #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  2 - Multi Player           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  0 - Exit The Game          #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    char option;
    printf("\t\t\t\t--->: ");
    option = getch();
    option -= 48;
    printf("\n\n\n");
    if (option == 1)
        singlePlayerMode();
    else if (option == 2)
        multiPlayerMode();
    else if (option == 0)
        exitGame();
    else
    {
        printf("Invalid Option");
        main();
    }
}

void singlePlayerMode()
{
    char option;
    int flag = true;
    do
    {
        char comptureSign = 'O';
        char playerSign = 'X';
        choosePlayerSign(&playerSign, &comptureSign);
        if (flag)
        {
            while (true)
            {
                SinglePlayerTurn(playerSign);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerSign, comptureSign))
                {
                    if (checkWin(gameBoard, playerSign))
                    {
                        winingMessage(playerSign);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
                computerTurn(comptureSign);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerSign, comptureSign))
                {
                    if (checkWin(gameBoard, comptureSign))
                    {
                        winingMessage(comptureSign);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
            }
            flag = false;
            // break;
        }
        else
        {
            while (true)
            {
                computerTurn(comptureSign);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerSign, comptureSign))
                {
                    if (checkWin(gameBoard, comptureSign))
                    {
                        winingMessage(comptureSign);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
                SinglePlayerTurn(playerSign);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerSign, comptureSign))
                {
                    if (checkWin(gameBoard, playerSign))
                    {
                        winingMessage(playerSign);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
            }
            flag = true;
            // break;
        }
        sleep(5);
        playAgain();
        option = getch();
        option -= 48;
    } while (option != 0);
}

void multiPlayerMode()
{
    char option;
    int flag = true;
    do
    {
        char playerOne = 'O';
        char playerTwo = 'X';
        choosePlayerSign(&playerOne, &playerTwo);
        if (flag)
        {
            while (true)
            {
                playerOneTurn(playerOne);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerOne, playerTwo))
                {
                    if (checkWin(gameBoard, playerOne))
                    {
                        winingMessage(playerOne);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
                playerTwoTurn(playerTwo);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerTwo, playerOne))
                {
                    if (checkWin(gameBoard, playerTwo))
                    {
                        winingMessage(playerTwo);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
            }
            flag = false;
            // break;
        }
        else
        {
            while (true)
            {
                playerTwoTurn(playerTwo);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerTwo, playerOne))
                {
                    if (checkWin(gameBoard, playerTwo))
                    {
                        winingMessage(playerTwo);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
                playerOneTurn(playerOne);
                printBoard(gameBoard);
                if (isGameOver(gameBoard, playerOne, playerTwo))
                {
                    if (checkWin(gameBoard, playerOne))
                    {
                        winingMessage(playerOne);
                        break;
                    }
                    else
                    {
                        drawMessage();
                        break;
                    }
                }
            }
            flag = true;
            // break;
        }
        sleep(5);
        playAgain();
        option = getch();
        option -= 48;
    } while (option != 0);
}

void computerTurn(char sign)
{
    while (true)
    {
        srand(time(0));
        int position = rand() % 9 + 1;
        if (isFreeSpaceAvailable(gameBoard, position))
        {
            printf("Computer Choose %d\n", position);
            placeMove(gameBoard, position, sign);
            break;
        }
    }
}

void SinglePlayerTurn(char sign)
{
    while (true)
    {
        char position;
        printf("Player %c Turn: \n", sign);
        printf("Choose The Position between 1 to 9: \n");
        printf("Enter Position: ");
        position = getch();
        if (position >= '0' && position <= '9')
        {
            position -= 48;
            if (isFreeSpaceAvailable(gameBoard, position))
            {
                placeMove(gameBoard, position, sign);
                break;
            }
            else
                printf("Invalid Position\n");
        }
        else
                printf("Invalid Position\n");
    }
}

void playerOneTurn(char sign)
{
    while (true)
    {
        int position;
        printf("Player 1 %c Turn: \n", sign);
        printf("Choose The Position between 1 to 9: \n");
        printf("Enter Position: ");
        position = getch();
        if (position >= '0' && position <= '9')
        {
            position -= 48;
            if (isFreeSpaceAvailable(gameBoard, position))
            {
                placeMove(gameBoard, position, sign);
                break;
            }
            else
                printf("Invalid Position\n");
        }
        else
            printf("Invalid Position\n");
    }
}

void playerTwoTurn(char sign)
{
    while (true)
    {
        int position;
        printf("Player 2 %c Turn: \n", sign);
        printf("Choose The Position between 1 to 9: \n");
        printf("Enter Position: ");
        position = getch();
        if (position >= '0' && position <= '9')
        {
            position -= 48;
            if (isFreeSpaceAvailable(gameBoard, position))
            {
                placeMove(gameBoard, position, sign);
                break;
            }
            else
                printf("Invalid Position\n");
        }
        else
            printf("Invalid Position\n");
    }
}

void choosePlayerSign(char *signOne, char *signTwo)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                 Choose Symbole                  #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                   X  or  O                      #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                      Press                      #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  1 - X                      #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  2 - O                      #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                 -->  0 - Main Menu              #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");

    char option;
    printf("\t\t\t\t--->: ");
    option = getch();
    if (option >= '0' && option <= '9')
        option -= 48;
    printf("\n\n\n");
    if (option == 1 || option == 'x' || option == 'X')
    {
        *signOne = 'X';
        *signTwo = 'O';
    }
    else if (option == 2 || option == 'o' || option == 'O')
    {
        *signOne = 'O';
        *signTwo = 'X';
    }
    else if (option == 0)
    {
        mainMenu();
    }
    else
    {
        printf("Invalid Option");
        choosePlayerSign(signOne, signTwo);
    }
}

void printBoard(char gameBoard[5][5])
{
    clearScreen();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%c", gameBoard[i][j]);
        printf("\n");
    }
}

void restBoard(char gameBoard[5][5])
{
    // clearScreen();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
                gameBoard[i][j] = ' ';
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
        return gameBoard[0][0] == ' ';
    case 2:
        return gameBoard[0][2] == ' ';
    case 3:
        return gameBoard[0][4] == ' ';
    case 4:
        return gameBoard[2][0] == ' ';
    case 5:
        return gameBoard[2][2] == ' ';
    case 6:
        return gameBoard[2][4] == ' ';
    case 7:
        return gameBoard[4][0] == ' ';
    case 8:
        return gameBoard[4][2] == ' ';
    case 9:
        return gameBoard[4][4] == ' ';
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

bool isGameOver(char gameBoard[5][5], char sign1, char sign2)
{
    if (checkWin(gameBoard, sign1))
        return true;
    if (checkWin(gameBoard, sign2))
        return true;

    for (int i = 1; i <= 9; i++)
        if (isFreeSpaceAvailable(gameBoard, i))
            return false;

    return true;
}

void winingMessage(char sign)
{
    clearScreen();
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*           $$ !!! Congratulations!!! $$                *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*                  {  %c  }                              *#*\n", sign);
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*              $***** WINNER *****$                     *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*       ** You have conquered the game! **              *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*            Enjoy your well-deserved                   *#*\n");
    printf("\t\t*#*            victory and celebration!                   *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\n");
}

void drawMessage()
{
    clearScreen();
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*                    Oppsss!!                           *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*                    Game Draw                          *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\n");
}

void playAgain()
{
    restBoard(gameBoard);
    clearScreen();
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*               Do You Want To Play Again               *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*               -->   Press any to Play Again           *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*              -->    0 - Main Menu                     *#*\n");
    printf("\t\t*#*                                                       *#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\t\t*#*********************************************************#*\n");
    printf("\n");
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
    welcomeScreen();
}