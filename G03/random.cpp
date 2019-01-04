#include "G03.h"

void insertNewNumber(int k[4][4]){
    int available = 0;
    int n;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (k[i][j] == 0)
                available++;
        }
    }
    if (available == 0)
    {
        printf("Internal error no available square\n");
        exit(1);
    }
    n = rand() % available;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (k[i][j] == 0)
            {
                if (n == 0)
                {
                    if (rand() % 10 == 0)
                    {
                        k[i][j] = 4;
                    }
                    else
                    {
                        k[i][j] = 2;
                    }
                    return;
                }
                n--;
            }
        }
    }
}

int check(int n1,int n2,int k[4][4]){
    int m;
    if(k[n1][n2]!=0)
    {
        m=1;
    }
    else
    {
        m=0;
    }
    return m;
}

int random1(int a){
    int k=rand()%50;
    if(k<=30)
        a=2;
    else if(30<k&&k<=40)
        a=4;
    else if(40<k&&k<=45)
        a=8;
    else if(45<k&&k<=48)
        a=16;
    else
        a=32;
    return a;
}

int random2(int k[4][4]){
    int a;
    int b1=rand()%4,b2=rand()%4,b4=rand()%4,b3=rand()%4;
    do
    {
        b1=rand()%4;
        b2=rand()%4;
    }
    while(check(b1,b2,k));
    k[b1][b2]=random1(a);
    do
    {
        b4=rand()%4;
        b3=rand()%4;
    }
    while(check(b3,b4,k));
    k[b3][b4]=random1(a);
}
