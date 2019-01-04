#include "G03.h"

void Ar(int k[4][4]){
    for(int i=0; i<4; i++)
    {
        printf("---------------------\n|");
        for(int j=0; j<4; j++)
        {
            printf("%4d|",k[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
}

void matrix(int k[4][4],int moves){
    printf("Right(d),Left(a),On(w),Under(s),Save(r),Exit(e)\n");
    Ar(k);
    printf("move= %d \n",moves);
}
