#include "waktu.c"
#include "mekanismewaktu.c"

#include "../simulator/simulator.c"
#include "../stack/stack.c"
#include "../queue/prioqueue.c"
#include "../notif/notif.c"
#include "../map/map.c"
#include "../list_statik/list_statik.c"
#include "../makanan/makanan.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    waktu t;
    createTime(&t);
    printTime(t);
    printf("\n");

    waktu t2;
    CreateTimeDirect(&t2,15,13,2);
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