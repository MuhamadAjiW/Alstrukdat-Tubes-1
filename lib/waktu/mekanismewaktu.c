#include "waktu.h"
#include "../simulator/simulator.h"
#include "../stack/stack.h"
/*dependent packages:
#include "waktu.c"
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
*/
#include <stdio.h>
#include <stdlib.h>

void inventoryDeliveryMechanism(Simulator *S, Stack* stack) {
    makanan dump, temp;
    while(timeIsZero(DLV(*S), 2)) {//delivery
        Dequeue(&DLV(*S), &temp, 2);
        Enqueue(&INV(*S), temp, 1);
        //add notif
        insertFirst(&NOTIF(*S), 'd', temp);
        if (Top(*stack) != -1){
            insertFirst(&NotifPrev(*stack), '6', temp);
        }
    }
    while(timeIsZero(INV(*S), 1)) {//expiration
        Dequeue(&INV(*S), &dump, 1);
        //add notiff
        insertFirst(&NOTIF(*S), 'e', dump);
        if (Top(*stack) != -1){
            insertFirst(&NotifPrev(*stack), '7', dump);
        }
    }
}

void passTime(Simulator *S, long pass, waktu *time){
// melewatkan waktu selama menit yang ditentukan
// makanan dengan waktu penyimpanan <0 artinya sudah expired
    addressQ idx;
    long temp = TIMEToMenit(*time);
    *time = MenitToTIME(temp + pass);

    if(!queueIsEmpty(INV(*S))){
        long menit;
        idx=Head(INV(*S));
        while(idx!=Tail(INV(*S))){
            menit=TIMEToMenit(Elmt(INV(*S),idx).expireTime);
            menit-=pass;
            Elmt(INV(*S),idx).expireTime=MenitToTIME(menit);
            if(idx==MaxEl(INV(*S))-1){
                idx=0;
            }
            else idx++;
        }
        menit=TIMEToMenit(InfoTail(INV(*S)).expireTime);
        menit-=pass;
        InfoTail(INV(*S)).expireTime=MenitToTIME(menit);
    }

    if (!queueIsEmpty(DLV(*S))) {
        long tMenit;
        int nDelivery = NBElmt(DLV(*S));
        int i = Head(DLV(*S));
        for (int j = 0; j < nDelivery; j++) {
            tMenit = TIMEToMenit(Deliver(DLV(*S), i));
            if ((tMenit-pass) <= 0) {
                long tempExp = TIMEToMenit(Expire(DLV(*S), i)) + tMenit - pass;
                Expire(DLV(*S), i) = MenitToTIME(tempExp);
                Deliver(DLV(*S), i) = MenitToTIME(0);
            }
            else {
                Deliver(DLV(*S), i) = MenitToTIME(tMenit-pass);
            }

            if (i == MaxEl(DLV(*S))-1) {
                i = 0;
            }
            else {
                i += 1;
            }
        }
    }
}