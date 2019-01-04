#include "G03.h"

int everymove(int k[4][4],struct Every *grades[],int moves){
    struct Every *newnode;
    newnode = (struct Every *)malloc(sizeof(struct Every));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            newnode->m[4*i+j]=k[i][j];
        }
    }
    newnode->m[16]=moves;
    grades[moves]=newnode;
}

int renew(int k[4][4],int moves){
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            k[i][j]=0;
        }
    }
    moves=0;
}

int choose(int h){
    h=getch();
    if(h=='w'||h=='W')
    {
        h=4;
    }
    else if(h=='a'||h=='A')
    {
        h=2;
    }
    else if(h=='d'||h=='D')
    {
        h=3;
    }
    else if(h=='r'||h=='R')
    {
        h=5;
    }
    else if(h=='e'||h=='E')
    {
        h=6;
    }
    else
        h=1;
    return h;
}

int moveUp(int k[4][4]){
    int n,m,next=0;
    int flag=-1;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            n = k[i][j];
            if(n!=0)
            {
                m = i+1;
                while(m<4)
                {
                    next = k[m][j];
                    if(next!=0)
                    {
                        if(n==next)
                        {
                            flag=0;
                            k[i][j]+=k[m][j];
                            k[m][j]=0;
                        }
                        m=4;
                        break;
                    }
                    m++;
                }
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            n=k[i][j];
            if(n==0)
            {
                m=i+1;
                while(m<4)
                {
                    next=k[m][j];
                    if(next!=0)
                    {
                        flag=0;
                        k[i][j]=next;
                        k[m][j]=0;
                        m=4;
                    }
                    m++;
                }
            }
        }
    }
    if(flag==-1)
        return -1;
}

int moveDown(int k[4][4]){
    int n,m,next=0;
    int flag=-1;
    for(int i=3; i>=0; i--)
    {
        for(int j=0; j<4; j++)
        {
            n=k[i][j];
            if(n!=0)
            {
                m=i-1;
                while(m>=0)
                {
                    next=k[m][j];
                    if(next!=0)
                    {
                        if(k[i][j]==k[m][j])
                        {
                            flag=0;
                            k[i][j]+=k[m][j];
                            k[m][j]=0;
                        }
                        m=0;
                        break;
                    }
                    m--;
                }
            }
        }
    }

    for(int i=3; i>0; i--)
    {
        for(int j=0; j<4; j++)
        {
            n=k[i][j];
            if(n==0)
            {
                m=i-1;
                while(m>=0)
                {
                    next=k[m][j];
                    if(next!=0)
                    {
                        flag=0;
                        k[i][j]=next;
                        k[m][j]=0;
                        m=0;
                    }
                    m--;
                }
            }
        }
    }
    if(flag==-1)
        return -1;
}

int moveLeft(int k[4][4]){
    int n,m,next=0;
    int flag=-1;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            n=k[i][j];
            if(n!=0)
            {
                m=j+1;
                while(m<4)
                {
                    next=k[i][m];
                    if(next!=0)
                    {
                        if(n==next)
                        {
                            flag=0;
                            k[i][j]+=k[i][m];
                            k[i][m]=0;
                        }
                        m=4;
                        break;
                    }
                    m++;
                }
            }
        }
    }


    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            n=k[i][j];
            if(n==0)
            {
                m=j+1;
                while(m<4)
                {
                    next=k[i][m];
                    if(next!=0)
                    {
                        flag=0;
                        k[i][j]=next;
                        k[i][m]=0;
                        m=4;
                    }
                    m++;
                }
            }
        }
    }
    if(flag==-1)
        return -1;
}

int moveRight(int k[4][4]){
    int n,m,next=0;
    int flag=-1;
    for(int i=0; i<4; i++)
    {
        for(int j=4-1; j>=0; j--)
        {
            n=k[i][j];
            if(n!=0)
            {
                m=j-1;
                while(m>=0)
                {
                    next=k[i][m];
                    if(next!=0)
                    {
                        if(n==next)
                        {
                            flag=0;
                            k[i][j]+=k[i][m];
                            k[i][m]=0;
                        }
                        m=-1;
                        break;
                    }
                    m--;
                }
            }
        }
    }


    for(int i=0; i<4; i++)
    {
        for(int j=3; j>0; j--)
        {
            n=k[i][j];
            if(n==0)
            {

                m=j-1;
                while(m>=0)
                {
                    int next=k[i][m];
                    if(next!=0)
                    {
                        flag=0;
                        k[i][j]=next;
                        k[i][m]=0;
                        m=-1;
                    }
                    m--;
                }
            }
        }
    }
    if(flag==-1)
        return -1;
}

int gameOver1(int k[4][4]){
    int a[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            a[i][j]=k[i][j];
    }
    if(moveDown(a)==-1&&moveUp(a)==-1&&moveLeft(a)==-1&&moveRight(a)==-1)
        return 1;
    else
        return 0;

}

int on(int k[4][4]){
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            k[j][i]=k[j][i]+k[j+1][i];
            k[j+1][i]=0;
        }
    }
}

int under(int k[4][4]){

    for(int i=0; i<4; i++)
    {
        for(int j=3; j>0; j--)
        {
            k[j][i]=k[j][i]+k[j-1][i];
            k[j-1][i]=0;
        }
    }
}

int left(int k[4][4]){
    for(int i=0; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            k[i][j-1]=k[i][j-1]+k[i][j];
            k[i][j]=0;
        }
    }
}

int right(int k[4][4]){
    for(int i=0; i<4; i++)
    {
        for(int j=3; j>0; j--)
        {
            k[i][j]=k[i][j]+k[i][j-1];
            k[i][j-1]=0;
        }
    }
}

int gameOver2(int k[4][4]){
    int a=0;
    char o;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(k[i][j]>248)
            {
                a=2;
                break;
            }
            else if(k[i][j]==248)
            {
                a=1;
                break;
            }
        }
    }
    if(a==2)
    {
        printf("Game over\n");
    }
    else if(a==1)
    {
        printf("You win\n");
    }
    return a;
}
