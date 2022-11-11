#ifndef stackur_H
#define stackur_H

#include "../map/map.c"
#include "../notif/notif.h"
// #include "../waktu/waktu.c"

#define undoCap 20

typedef struct 
{
    waktu W;
    char movement;
    PrioQueue invPrev;
    PrioQueue dlvPrev;
    List_Link notifPrev;
    int proses; // berisi proses sebelum undo/redo
}StrukturUndo;

typedef struct
{
    StrukturUndo T[undoCap];
    int TOP; // top bernilai -1 jika stack kosong
} Stackur;

#define Nil -1
#define Topur(S) (S).TOP
#define InfoTopur(S) (S).T[(S).TOP]
#define WaktuTopur(S) (S).T[(S).TOP].W
#define MovementTopur(S) (S).T[(S).TOP].movement
#define NotifPrev(S) (S).T[(S).TOP].notifPrev
#define ProsesTopur(S) (S).T[(S).TOP].proses

void CreateEmptyStackur(Stackur *S);
boolean IsEmptyStackur(Stackur S);
void PushStackur(Stackur *S, Simulator s, waktu globalt, char mov, int proses);
void PopStackur(Stackur *S, Simulator *s, Map *M, waktu *globalt, list_statik catalog);

#endif