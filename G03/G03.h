#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>
//FILE *fp;

struct Every{
    int m[17]= {0};
};
int save(int k[4][4],int f,int moves);
int everymove(int k[4][4],struct Every *grades[],int moves);
int any();
int renew(int k[4][4],int moves);
int question1(int s);
int question2(int k[4][4],int s,int moves,int f);
void caption();
void Ar(int k[4][4]);
void matrix(int k[4][4],int moves);
int choose(int h);
int moveUp(int k[4][4]);
int moveDown(int k[4][4]);
int moveLeft(int k[4][4]);
int moveRight(int k[4][4]);
int gameOver1(int k[4][4]);
void insertNewNumber(int k[4][4]);
int game1(int k[4][4],int moves);
int new1(int k[4][4],int moves);
int regular2048(int k[4][4],int moves);
int check(int n1,int n2,int k[4][4]);
int on(int k[4][4]);
int under(int k[4][4]);
int left(int k[4][4]);
int right(int k[4][4]);
int gameOver2(int k[4][4]);
int random1(int a);
int random2(int k[4][4]);
int game2(int k[4][4],int moves);
int new2(int k[4][4],int moves);
int diff2048(int k[4][4],int moves);
int realoldfile(int k[4][4],int moves,int f);
