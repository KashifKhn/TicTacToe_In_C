# Tic Tac Toe Game

This is a simple command-line implementation of the Tic Tac Toe game in C programming language. The game allows you to play against the computer or another player.

## Prerequisites
C compiler

## Code Overview
The main functionality of the game is implemented in the following functions:

### welcomeScreen():
Displays the welcome screen.
### mainMenu(): 
Displays the main menu options and handles user input.
### singlePlayerMode(): 
Starts the single-player mode of the game.
### SinglePlayerTurn(char sign): 
Handles the player's turn in the single-player mode.
### computerTurn(char sign): 
Handles the computer's turn in the single-player mode.
### multiPlayerMode(): 
Starts the multiplayer mode of the game.
### playerOneTurn(char sign): 
Handles the first player's turn in the multiplayer mode.
### playerTwoTurn(char sign): 
Handles the second player's turn in the multiplayer mode.
### choosePlayerSign(char *playerSign, char *ComputerSign): 
Prompts the player to choose their sign.
### printBoard(char gameBoard[5][5]): 
Prints the current state of the game board.
### resetBoard(char gameBoard[5][5]): 
Resets the game board to its initial state.
### placeMove(char gameBoard[5][5], int position, char sign): 
Places the player's move on the game board.
### isFreeSpaceAvailable(char gameBoard[5][5], int position): 
Checks if a space on the game board is available.
checkWin(char gameBoard[5][5], char sign): Checks if a player has won the game.
### isGameOver(char gameBoard[5][5], char sign1, char sign2): 
Checks if the game is over.
### winingMessage(char sign): 
Displays the winning message for the player with the specified sign.
### drawMessage(): 
Displays the draw message when the game ends in a draw.
### playAgain(): 
Prompts the player to play again.
### clearScreen(): 
Clears the screen.
### exitGame(): 
Exits the game.

## How to Run
1. Clone the repository or download the source code files.
2. Compile the code using a C compiler.
3. Run the compiled executable.

## Game Rules
1. The game is played on a 3x3 grid.
2. Two players take turns marking spaces on the grid.
3. The first player uses 'X' as their marker, and the second player uses 'O'.
4. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.
5. If all spaces on the grid are filled and no player has won, the game is declared a draw.

## Gameplay

The game supports two game modes: Single Player and Multiplayer.

## How to Play
1. Upon running the game, you will see a welcome screen.
2. Choose the desired mode from the main menu: single-player or multiplayer.
3. In single-player mode, you play against the computer. In multiplayer mode, two players take turns.
4. Follow the on-screen instructions to make your moves by entering the corresponding position number.
5. The game will display the current state of the board after each move.
6. If a player wins or the game ends in a draw, the result will be displayed.
7. You will be prompted to play again or exit the game.

### Single Player Mode

In this mode, you play against the computer.

1. Choose "Single Player" from the main menu.
2. Select your symbol (X or O) for the game.
3. The game board will be displayed, and you can start making your moves.
4. Enter the position number (1 to 9) where you want to place your symbol.
5. The computer will take its turn automatically.
6. The game will continue until a player wins or there is a draw.
7. Play again or exit the game when prompted.

### Multiplayer Mode

In this mode, two players take turns playing against each other.

1. Choose "Multi Player" from the main menu.
2. Player 1 selects their symbol (X or O).
3. Player 2 selects the other symbol.
4. The game board will be displayed, and Player 1 can start making their move.
5. Enter the position number (1 to 9) where Player 1 wants to place their symbol.
6. Player 2 takes their turn.
7. The game continues until a player wins or there is a draw.
8. Play again or exit the game when prompted.

## Dependencies

The code uses the following standard C libraries:
- stdio.h
- stdbool.h
- conio.h
- stdlib.h
- time.h
- unistd.h

## Contributing

Contributions to this project are welcome. If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
