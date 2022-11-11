#ifndef Stack_H
#define Stack_H

#include "../map/map.h"
#include "../notif/notif.h"

#define undoCap 20

typedef struct 
{
    waktu W; //isi waktu saat push
    char movement; // berisi kode, kamus tertera di bawah
    PrioQueue invPrev; //isi state inventory saat push
    PrioQueue dlvPrev; //isi state delivery saat push
    List_Link notifPrev; //isi notif yang perlu keluar waktu undo/redo
    int proses; // berisi kode, -1 jika mark, index makanan jika dilakukan aksi pembuatan makanan
}StrukturUndo;

typedef struct
{
    StrukturUndo T[undoCap];
    int TOP; // top bernilai -1 jika stack kosong
} Stack;

#define Nil -1
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define WaktuTop(S) (S).T[(S).TOP].W
#define MovementTop(S) (S).T[(S).TOP].movement
#define NotifPrev(S) (S).T[(S).TOP].notifPrev
#define ProsesTop(S) (S).T[(S).TOP].proses

//Stack berbentuk statis sirkuler, jika kosong top adalah nil
//Pengecekan kosong tidaknya slot dilakukan dengan mengecek proses bernilai nil atau tidak

void CreateEmptyStack(Stack *S);
//inisiasi

boolean IsEmptyStack(Stack S);
//true jika top adalah nil

void PushStack(Stack *S, Simulator s, waktu globalt, char mov, int proses);
//mendorong state yang ingin disimpan ke stack

void PopStack(Stack *S, Simulator *s, Map *M, waktu *globalt, list_statik catalog);
//mengambil state yang ingin diambil stack

void convertUR(List_Link *Target, int Type);
//convert notif ke undo atau sebaliknya. type 1 undo ke redo, 2 redo ke undo

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

#endif