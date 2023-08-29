# Tic-Tac-Toe Game

A simple command-line implementation of the classic Tic-Tac-Toe game in C++.

## Overview

This is a console-based implementation of the Tic-Tac-Toe game where two players can take turns to play. The game supports basic features like entering player symbols, making moves, and determining the game's outcome.

## How to Play

1. Run the program. You'll be prompted to enter symbols for Player 1 and Player 2.

2. Enter a symbol for Player 1 (e.g., 'X', 'O'). Make sure it's a single character different from '1' to '9'.

3. Enter a symbol for Player 2. Again, ensure it's a single character and different from the previous symbol.

4. The game board is displayed with numbered cells. Players take turns to enter the cell number where they want to place their symbol.

5. The game ends when one player wins, or the game is a draw. The result is displayed at the end.

## Code Structure

- The game logic is implemented using the `GameBoard` class and the `TicTacToe` class.
- The `GameBoard` class handles the state of the game board, including marking cells, checking for a win or draw, and validating moves.
- The `TicTacToe` class manages the flow of the game, alternating turns between players and updating the game state.
