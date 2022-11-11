#include "stackura.h"
#include <stdio.h>
#include <stdlib.h>


void CreateEmptyStackur(Stackur *S){
    Topur(*S) = Nil;
    for(int i = 0; i < undoCap; i++){
        createTime(&((*S).T[i].W));
        MakeEmpty(&((*S).T[i].invPrev), 1);
        MakeEmpty(&((*S).T[i].dlvPrev), 1);
        ((*S).T[i].proses) = -1;
        createListLink(&((*S).T[i].notifPrev));
    }
}
boolean IsEmptyStackur(Stackur S){
    return Topur(S) == Nil;
}
void PushStackur(Stackur *S, Simulator s, waktu globalt, char mov, int proses){
    if ((Topur(*S)) == undoCap-1){
        Topur(*S) = 0;
    }
    else{
        Topur(*S)++;
    }
    Jam((*S).T[Topur(*S)].W) = Jam(globalt);
    Menit((*S).T[Topur(*S)].W) = Menit(globalt);
    Hari((*S).T[Topur(*S)].W) = Hari(globalt);
    (*S).T[(*S).TOP].movement = mov;
    CopyQueue(INV(s),&(*S).T[Topur(*S)].invPrev,1);
    CopyQueue(DLV(s),&(*S).T[Topur(*S)].dlvPrev,2);
    ((*S).T[Topur(*S)].proses) = proses;
    printf("jumlah stack = %d\n", Topur(*S));
}

void PopStackur(Stackur *S, Simulator *s, Map *M, waktu *globalt, list_statik catalog){
    /*
    KAMUS movement
    w = move atas
    a = move kiri
    s = move bawah
    d = move kanan

    1 = mix undo
    2 = chop undo
    3 = fry undo
    4 = boil undo
    5 = buy undo
    6 = wait undo

    z = mix redo
    x = chop redo
    c = boil redo
    v = buy redo
    b = fry redo
    n = wait redo

    KAMUS mode
    0 = undo
    1 = redo
    */
    int idx;
    idx = ((*S).T[Topur(*S)].proses);
    int makanandibuat = 0;
    if (((*S).T[Topur(*S)].proses) == -1){
        Topur(*S) = -1;
    }
    else{
        Jam(*globalt) = Jam((*S).T[Topur(*S)].W);
        Menit(*globalt) = Menit((*S).T[Topur(*S)].W);
        Hari(*globalt) = Hari((*S).T[Topur(*S)].W);
        if ((*S).T[(*S).TOP].movement == 'w'){
            moveDir(M, 's');
        }
        else if ((*S).T[(*S).TOP].movement == 's'){
            moveDir(M, 'w');
        }
        else if ((*S).T[(*S).TOP].movement == 'd'){
            moveDir(M, 'a');
        }
        else if ((*S).T[(*S).TOP].movement == 'a'){
            moveDir(M, 'd');
        }

        else if ((*S).T[(*S).TOP].movement == '1'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), '1', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '2'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), '2', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '3'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), '3', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '4'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), '4', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '5'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), '5', ELMT(catalog, idx));
        }

        else if ((*S).T[(*S).TOP].movement == 'p'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), 'p', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'o'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), 'o', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'i'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), 'i', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'u'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), 'u', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'y'){
            makanandibuat = 1;
            insertFirst(&NOTIF(*s), 'y', ELMT(catalog, idx));moveDir(M, 'a');
        }


        CopyQueue((*S).T[Topur(*S)].invPrev,&INV(*s),1);
        CopyQueue((*S).T[Topur(*S)].dlvPrev,&DLV(*s),2);
        ((*S).T[Topur(*S)].proses) = -1;

        concatDel(&NotifPrev(*S), &NOTIF(*s));

        Topur(*S)--;
        if ((Topur(*S)) == -1){
            Topur(*S) = undoCap-1;
            if (((*S).T[Topur(*S)].proses) == -1){
                Topur(*S) = -1;
            }
        }
    }
    
    printf("jumlah stack = %d\n", Topur(*S));
}

void inventoryDeliveryMechanism(Simulator *S, Stackur* stack) {
    makanan dump, temp;
    while(timeIsZero(DLV(*S), 2)) {//delivery
        Dequeue(&DLV(*S), &temp, 2);
        Enqueue(&INV(*S), temp, 1);
        //add notif
        insertFirst(&NOTIF(*S), 'd', temp);
        if (Topur(*stack) != -1){
            insertFirst(&NotifPrev(*stack), '6', temp);
        }
    }
    while(timeIsZero(INV(*S), 1)) {//expiration
        Dequeue(&INV(*S), &dump, 1);
        //add notiff
        insertFirst(&NOTIF(*S), 'e', dump);
        if (Topur(*stack) != -1){
            insertFirst(&NotifPrev(*stack), '7', temp);
        }
    }
}

void convertUR(List_Link *Target, int Type){
    //convert notif ke undo atau sebaliknya
    // type 1 undo ke redo, 2 redo ke undo
    Address p = FIRST(*Target);
    if (Type == 1){
        while (p!= NULL)
        {
            if (KASUS(INFO(p)) == '6'){
                KASUS(INFO(p)) = 't';
            }
            else if (KASUS(INFO(p)) == '7'){
                KASUS(INFO(p)) = 'r';
            }
            p = NEXT(p);
        }
    }
    else if (Type == 2){
        while (p!= NULL)
        {
            if (KASUS(INFO(p)) == 't'){
                KASUS(INFO(p)) = '6';
            }
            else if (KASUS(INFO(p)) == 'r'){
                KASUS(INFO(p)) = '7';
            }
            p = NEXT(p);
        }
    }
    
}