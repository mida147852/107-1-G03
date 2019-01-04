#include "G03.h"

int game1(int k[4][4],int moves){
    FILE *fp;
    int s=0,f=1,c;
    struct Every *grades[10000];
    everymove(k,grades,moves);
    while(1)
    {
        if(gameOver1(k)!=0||s==1)
            break;
        else
        {
            matrix(k,moves);
            int c=choose(c);
            system("cls");
            switch(c)
            {
            case 1:
            {
                moveDown(k);
                break;
            }
            case 2:
            {
                moveLeft(k);
                break;
            }
            case 3:
            {
                moveRight(k);
                break;
            }
            case 4:
            {
                moveUp(k);
                break;
            }
            case 5:
            {
                save(k,f,moves);
                s=question1(s);
                break;
            }
            case 6:
            {
                s=question2(k,moves,s,f);
                break;
            }
            }
            moves++;
            insertNewNumber(k);
            everymove(k,grades,moves);
        }
    }
    char filename3[10]= {'m','o','v','e','1','.','t','x','t'};
    fp=fopen(filename3,"w");
    for(int i=0; i<moves; i++)
    {
        for(int j=0; j<17; j++)
        {
            fprintf(fp,"%3d ",grades[i]->m[j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}

int new1(int k[4][4],int moves){
    srand(time(NULL));
    system("cls");
    insertNewNumber(k);
    game1(k,moves);
    Ar(k);
    any();
}

int regular2048(int k[4][4],int moves){
    int s,f=1;
    while(1)
    {
        system("cls");
        caption();
        scanf("%d",&s);
        if(s==3)
            break;
        if(s==1)
        {
            printf("Enter the moving keyboard: \n");
            renew(k,moves);
            new1(k,moves);
        }
        else
        {
            system("cls");
            realoldfile(k,moves,f);
        }
    }
    return 0;
}


