#include "point.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    POINT p;
    p=CreatePOINT(1,2);
    WritePOINT(p);     printf("\n");

    MoveSouth(&p);
    WritePOINT(p);     printf("\n");

    MoveEast(&p);
    WritePOINT(p);     printf("\n");

    MoveNorth(&p);
    WritePOINT(p);     printf("\n");

    MoveWest(&p);
    WritePOINT(p);     printf("\n");
    //akhir program
    printf("Done!");
    //scanf("%d", &confirmDone);
    return 0;
}