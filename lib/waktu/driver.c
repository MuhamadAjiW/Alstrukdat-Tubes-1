#include "waktu.c"
#include <stdio.h>

int main(){
    int confirmDone = 0;
    //header program
    waktu t;
    createTime(&t);
    printTime(t);
    printf("\n");

    waktu t2;
    CreateTimeTest(&t2,15,13,2);
    printTime(t2);
    printf("\n");

    long menit= TIMEToMenit(t2);
    printf("%d",menit);
    printf("\n");

    t=MenitToTIME(menit);
    printTime(t);
    printf("\n");

    menit += 10;
    t2= MenitToTIME(menit);
    printTime(t2);
    printf("\n");

    printf("%d\n",TLT(t,t2)); //t lebih kecil dari t2 = true
    printf("%d\n",TGT(t,t2)); //t lebih besar dari t2 = false

    //akhir program
    printf("Done!");
    scanf("%d", &confirmDone);
    return 0;
}