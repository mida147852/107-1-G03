#include "g03.h"

void insertNewNumber(int board[4][4]) {
    int available = 0;
    int n;


    for (int i=0;i<4;i++) {
        for (int j=0; j<4;j++) {
            if (board[i][j] == 0) available++;
        }
    }

    if (available == 0) {
        printf("Internal error no available square\n");
        exit(1);
    }


    n = rand() % available;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (board[i][j] == 0) {
                if (n == 0) {
                    if (rand() % 10 == 0) {
                        board[i][j] = 4;
                    } else {
                        board[i][j] = 2;
                    }
                    return;
                }
                n--;
            }
        }
    }
}
