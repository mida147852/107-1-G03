#include "G03.h"

int main(){
    int k[4][4]= {0};
    int moves=0;
    while(1)
    {
        printf("Your want play normal 2048 or different 2048?\n");
        int choice;
        printf("  Normal 2048  enter number 1\n");
        printf("Different 2048 enter number 2\n");
        printf("     Exit      enter number 3\n");
        scanf("%d",&choice);
        if(choice==3)
            break;
        switch(choice)
        {
        case 1:
        {
            regular2048(k,moves);
            system("cls");
            break;
        }
        case 2:
        {
            diff2048(k,moves);
            system("cls");
            break;
        }
        }
    }
    return 0;
}
