#include "g03.h"

int moveUp(int board[4][4]) {
   int i,j,n,m,score,next=0;
   int flag=-1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            n = board[i][j];
             if(n!=0){
                m = i+1;
                while(m<4) {
                     next = board[m][j];
                      if(next!=0){
                        if(n==next){
                            flag=0;
                            board[i][j]+=board[m][j];
                            score+=board[i][j];
                            board[m][j]=0;
                        }
                        m=4;
                        break;
                    }
                    m++;
                }
            }
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
             n=board[i][j];
             if(n==0){
               m=i+1;
                while(m<4){
                    int next=board[m][j];
                    if(next!=0)
                    {
                        flag=0;
                        board[i][j]=n;
                        board[m][j]=0;
                        m=4;
                    }
                    m++;
                }
            }
        }
    }
    if(flag!=-1)
        return score;
    else
        return -1;
}

int moveDown(int board[4][4]) {
    int i,j,n,m,score,next=0;
    int flag=-1;
    for(i=3;i>=0;i--){
        for(j=0;j<4;j++){
            n=board[i][j];
            if(n!=0){
                m=i-1;
                while(m>=0){
                    int next=board[m][j];
                    if(next!=0){
                        if(board[i][j]==board[m][j]){
                            flag=0;
                            board[i][j]+=board[m][j];
                            score+=board[i][j];
                            board[m][j]=0;
                        }
                        m=0;
                        break;
                    }
                    m--;
                }
            }
        }
    }

    for(i=3;i>0;i--)
    {
        for(j=0;j<4;j++)
        {
            n=board[i][j];
            if(n==0)
            {
                m=i-1;
                while(m>=0)
                {
                    int nextc=board[m][j];
                    if(next!=0)
                    {
                        flag=0;
                        board[i][j]=next;
                        board[m][j]=0;
                        m=0;
                    }
                    m--;
                }
            }
        }
    }
    if(flag!=-1)
        return score;
    else
        return -1;
}

int moveLeft(int board[4][4]) {
    int i,j,n,m,score,next=0;
    int flag=-1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            n=board[i][j];
            if(n!=0){
                m=j+1;
                while(m<4)
                {
                    next=board[i][m];
                    if(next!=0)
                    {
                        if(n==next){
                            flag=0;
                            board[i][j]+=board[i][m];
                            score+=board[i][j];
                            board[i][m]=0;
                        }
                        m=4;
                        break;
                    }
                    m++;
                }
            }
        }
    }


    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            n=board[i][j];
            if(n==0)
            {
                m=j+1;
                while(m<4)
                {
                    next=board[i][m];
                    if(next!=0)
                    {
                        flag=0;
                        board[i][j]=next;
                        board[i][m]=0;
                        m=4;
                    }
                    m++;
                }
            }
        }
    }
    if(flag!=-1)
        return score;
    else
        return -1;
}

int moveRight(int board[4][4]) {
    int i,j,n,m,score,next=0;
    int flag=-1;
    for(i=0;i<4;i++)
    {
        for(j=4-1;j>=0;j--)
        {
            n=board[i][j];
            if(n!=0)
            {
                m=j-1;
                while(m>=0)
                {
                    next=board[i][m];
                    if(next!=0)
                    {
                        if(n==next)
                        {
                            flag=0;
                            board[i][j]+=board[i][m];
                            score+=board[i][j];
                            board[i][m]=0;
                        }
                        m=-1;
                        break;
                    }
                    m--;
                }
            }
        }
    }


    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
        {
            n=board[i][j];
            if(n==0)
            {

                m=j-1;
                while(m>=0)
                {
                    int next=board[i][m];
                    if(next!=0)
                    {
                        flag=0;
                        board[i][j]=next;
                        board[i][m]=0;
                        m=-1;
                    }
                    m--;
                }
            }
        }
    }
    if(flag!=-1)
        return score;
    else
        return -1;
}


int gameOver(int board[4][4]) {
    int a[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        a[i][j]=board[i][j];
        }
    if(moveDown(a)==-1&&moveUp(a)==-1&&moveLeft(a)==-1&&moveRight(a)==-1)
        return 1;
    else
        return 0;

}


