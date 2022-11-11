#include "stack.h"
/*dependent packages:
#include "../waktu/waktu.c"
#include "../queue/prioqueue.c"
#include "../notif/notif.c"
#include "../makanan/makanan.c"
#include "../tree/tree.c"
#include "../map/map.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"
*/
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyStack(Stack *S){
//inisiasi
    Top(*S) = Nil;
    for(int i = 0; i < undoCap; i++){
        createTime(&((*S).T[i].W));
        MakeEmpty(&((*S).T[i].invPrev), 1);
        MakeEmpty(&((*S).T[i].dlvPrev), 1);
        ((*S).T[i].proses) = -1;
        createListLink(&((*S).T[i].notifPrev));
    }
}
boolean IsEmptyStack(Stack S){
//true jika top adalah nil
    return Top(S) == Nil;
}

void PushStack(Stack *S, Simulator s, waktu globalt, char mov, int proses){
//mendorong state yang ingin disimpan ke stack
    if ((Top(*S)) == undoCap-1){
        Top(*S) = 0;
    }
    else{
        Top(*S)++;
    }
    Jam((*S).T[Top(*S)].W) = Jam(globalt);
    Menit((*S).T[Top(*S)].W) = Menit(globalt);
    Hari((*S).T[Top(*S)].W) = Hari(globalt);
    (*S).T[(*S).TOP].movement = mov;
    CopyQueue(INV(s),&(*S).T[Top(*S)].invPrev,1);
    CopyQueue(DLV(s),&(*S).T[Top(*S)].dlvPrev,2);
    ((*S).T[Top(*S)].proses) = proses;
}

void PopStack(Stack *S, Simulator *s, Map *M, waktu *globalt, list_statik catalog){
//mengambil state yang ingin diambil stack

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
    idx = ((*S).T[Top(*S)].proses);
    if (((*S).T[Top(*S)].proses) == -1){
        Top(*S) = -1;
    }
    else{
        Jam(*globalt) = Jam((*S).T[Top(*S)].W);
        Menit(*globalt) = Menit((*S).T[Top(*S)].W);
        Hari(*globalt) = Hari((*S).T[Top(*S)].W);
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
            insertFirst(&NOTIF(*s), '1', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '2'){
            insertFirst(&NOTIF(*s), '2', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '3'){
            insertFirst(&NOTIF(*s), '3', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '4'){
            insertFirst(&NOTIF(*s), '4', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == '5'){
            insertFirst(&NOTIF(*s), '5', ELMT(catalog, idx));
        }

        else if ((*S).T[(*S).TOP].movement == 'p'){
            insertFirst(&NOTIF(*s), 'p', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'o'){
            insertFirst(&NOTIF(*s), 'o', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'i'){
            insertFirst(&NOTIF(*s), 'i', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'u'){
            insertFirst(&NOTIF(*s), 'u', ELMT(catalog, idx));
        }
        else if ((*S).T[(*S).TOP].movement == 'y'){
            insertFirst(&NOTIF(*s), 'y', ELMT(catalog, idx));moveDir(M, 'a');
        }


        CopyQueue((*S).T[Top(*S)].invPrev,&INV(*s),1);
        CopyQueue((*S).T[Top(*S)].dlvPrev,&DLV(*s),2);
        ((*S).T[Top(*S)].proses) = -1;

        concatDel(&NotifPrev(*S), &NOTIF(*s));

        Top(*S)--;
        if ((Top(*S)) == -1){
            Top(*S) = undoCap-1;
            if (((*S).T[Top(*S)].proses) == -1){
                Top(*S) = -1;
            }
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