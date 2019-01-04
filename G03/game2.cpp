#include "G03.h"

int game2(int k[4][4],int moves){
    FILE *fp;
    int s=0,f=2;
    struct Every *grades[10000];
    everymove(k,grades,moves);
    while(1)
    {
        if(gameOver2(k)!=0||s==1)
            break;
        else
        {
            matrix(k,moves);
            int h=choose(h);
            system("cls");
            switch(h)
            {
            case 1:
            {
                under(k);
                break;
            }
            case 2:
            {
                left(k);
                break;
            }
            case 3:
            {
                right(k);
                break;
            }
            case 4:
            {
                on(k);
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
                s=question2(k,s,moves,f);
                break;
            }
            }
            moves++;
            random2(k);
            everymove(k,grades,moves);
        }
    }
    char filename3[10]= {'m','o','v','e','2','.','t','x','t'};
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

int new2(int k[4][4],int moves){
    random2(k);
    srand(time(NULL));
    system("cls");
    game2(k,moves);
    Ar(k);
    any();
}

int diff2048(int k[4][4],int moves){
    int s,f=2;
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
            new2(k,moves);
        }
        else
        {
            system("cls");
            realoldfile(k,moves,f);
        }
    }
    return 0;
}
