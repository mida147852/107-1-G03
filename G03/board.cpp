#include "g03.h"

void printBoard(int board[4][4]) {

    for(int i=0;i<4;i++){
        printf("|");
        for(int j=0;j<4;j++){
            if(board[i][j]==0) printf("    0");
            else printf("%5d",board[i][j]);
          }
        printf("|\n\n");
    }

}

void readBoard(int board[4][4]) {
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        scanf("%d",&board[i][j]);
    }
}
