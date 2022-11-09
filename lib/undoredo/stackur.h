#ifndef stackur_H
#define stackur_H

#include "../map/map.c"
// #include "../waktu/waktu.c"

typedef struct 
{
    Map M;
    waktu W;
    Simulator S;
    int proses; // berisi proses sebelum undo/redo
}StrukturUndo;

typedef struct
{
    StrukturUndo T[50];
    int TOP; // top bernilai -1 jika stack kosong
} Stackur;

#define Nil -1
#define Topur(S) (S).TOP
#define InfoTopur(S) (S).T[(S).TOP]
#define SimulatorTopur(S) (S).T[(S).TOP].S
#define MapTopur(S) (S).T[(S).TOP].M
#define WaktuTopur(S) (S).T[(S).TOP].W
#define ProsesTopur(S) (S).T[(S).TOP].proses

void CreateEmptyStackur(Stackur *S);

boolean IsEmptyStackur(Stackur S);

void PushStackur(Stackur *S, StrukturUndo X);

void PopStackur(Stackur *S);

void PrintTopUR(Stackur *S);

void copyAll(StrukturUndo *Sout,StrukturUndo Sin);

void subsStrukturUR(StrukturUndo *Sout,Map m,waktu w,Simulator s,int proses);

void subsElementUR(StrukturUndo Sout,Map *m,waktu *w,Simulator *s,int *proses);


#endif