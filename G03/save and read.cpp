#include "G03.h"

int save(int k[4][4],int f,int moves){
    FILE *fp;
    char filename2[10]= {'n','a','m','e','1','.','t','x','t'};
    char filename1[80];
    if(f==2)
        filename2[4]='2';
    int c=1;
    int p[17]= {0};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            p[4*i+j]=k[i][j];
        }
    }
    p[16]=moves;
    printf("Enter file name: ");
    scanf("%s",filename1);
    fp=fopen(filename1,"r+");
    if(fp==NULL)
    {
        printf("Fail To Open File %s!!",filename1);
        fp=fopen(filename1,"w");
        c=0;
    }
    for(int i=0; i<17; i++)
    {
        fprintf(fp,"%d\r",p[i]);
    }
    fprintf(fp,"%d\r",moves);
    fclose(fp);
    if(c==0)
    {
        fp=fopen(filename2,"a");
        fprintf(fp,"%s \n",filename1);
        fclose(fp);
    }
}

int any(){
    int h;
    printf("Enter any keyboard......\n");
    h=getch();
}

int question1(int s){
    char o;
    system("cls");
    printf("Continue games?(Y/N)\n");
    printf("=> ");
    scanf("%s",&o);
    if(o=='Y'||o=='y')
    {
        s=0;
    }
    else
    {
        s=1;
    }
    return s;
}

int question2(int k[4][4],int s,int moves,int f){
    char o;
    system("cls");
    printf("Save games?(Y/N)\n");
    scanf("%s",&o);
    if(o=='Y'||o=='y')
    {
        save(k,f,moves);
    }
    s=question1(s);
    return s;
}

void caption(){
    printf(" Restart game  enter number (1)\n");
    printf("Read old files enter number (2)\n");
    printf("    Back       enter number (3)\n");
}

int realoldfile(int k[4][4],int moves,int f){
    FILE *fp;
    char filename2[10]= {'n','a','m','e','1','.','t','x','t'};
    char filename1[80];
    if(f==2){
        filename2[4]='2';}
    int p[17],c;
    char ch;
    fp=fopen(filename2,"r+");
    if(fp==NULL)
    {
        printf("Fail To Open File %s!!",filename2);
        any();
        return 0;
    }
    int i=1;
    while(fscanf(fp,"%s",filename2)!=EOF)
    {
        printf("%d.%s\n",i,filename2);
        i++;
    }
    fclose(fp);
    printf("Enter your read file\n");
    scanf("%s",filename1);
    fp=fopen(filename1,"r+");
    i=0;
    while(fscanf(fp,"%d",&c)!=EOF&&i!=17)
    {
        if(i<16)
        {
            p[i]=c;
        }
        else
        {
            moves=c;
        }
        i++;
    }
    for(int j=0; j<4; j++)
    {
        for(int jj=0; jj<4; jj++)
        {
            k[j][jj]=p[4*j+jj];
        }
    }
    fclose(fp);
    if(f==2)game2(k,moves);
    else game1(k,moves);
}
