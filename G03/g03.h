#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int moveUp(int board[4][4]);

int moveDown(int board[4][4]);

int moveLeft(int board[4][4]);

int moveRight(int board[4][4]);

int gameOver(int board[4][4]);

void printBoard(int board[4][4]);

void readBoard(int board[4][4]);

void insertNewNumber(int board[4][4]);
