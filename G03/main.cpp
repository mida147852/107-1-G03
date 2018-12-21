#include "g03.h"

int main() {
    int board[4][4] = {{0}};
    int score, moveScore;
    char c;



    srand(time(NULL));

    printf("Enter 16 numbers making up initial board:\n");
    readBoard(board);

    score = 0;

    while (gameOver(board) == 0) {
        printf("\n");
        printf("Enter a for left, s for down, w for up, d for right, q to quit\n");
        printBoard(board);
        printf("Your score is %d.\n", score);
        printf("> ");

        c = getchar();
        while (isspace(c)) {
            c = getchar();
        }

        printf("\n");

        if (c == 'q' ) {
            printf("Good bye - your final score was %d.\n", score);
            return 0;
        }


            moveScore = 0;
            if (c == 'a') moveScore = moveLeft(board);
            else if (c == 's') moveScore = moveDown(board);
            else if (c == 'w') moveScore = moveUp(board);
            else if (c == 'd') moveScore = moveRight(board);


            if (moveScore == -1)
                printf("%c is not a legal move in the current position.\n", c);
            else {
                insertNewNumber(board);
                score = score + moveScore;
            }

    }
    printBoard(board);
    printf("Game over - your final score was %d.\n", score);
    return 0;
}
