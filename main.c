#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char gameBoard [5][5] = {
    {' ', '|', ' ', '|', ' '},
    {'-', '+', '-', '+', '-'},
    {' ', '|', ' ', '|', ' '},
    {'-', '+', '-', '+', '-'},
    {' ', '|', ' ', '|', ' '}
};

void welcomeScreen();
void printBoard(char gameBoard [5][5]);
void mainMenu();
void singlePlayer();
void twoPlayer();
void decidePlayMode();
void playGame();
int playerOneTurn();
int playerTwoTurn();
int computerTurn();
bool isGameOver();
bool checkWin();
bool isFreeSpaceAvailable(char gameBoard [5] [5], int position);
void placeMove(char gameBoard [5][5], int position, char sign);
void clearScreen();
void exitGame();


int main()
{
    
}